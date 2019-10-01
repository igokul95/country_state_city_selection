#include "statemodel.h"

#include "state.h"

StateModel::StateModel(QObject *parent)
    : QAbstractListModel(parent), mStates(nullptr)
{

}

int StateModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mStates ) {
        return 0;
    }

    return mStates->items().size();
}

QVariant StateModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mStates)
        return QVariant();
    const StateItem *state = mStates->items().at(index.row());
    switch (role) {
    case StateNameRole:
        return QVariant(state->name);
     case StateTotalSizeRole:
        return QVariant(state->area);
    }

    return QVariant();
}

bool StateModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mStates)
        return false;
    StateItem *state = mStates->items().at(index.row());

    switch (role) {
    case StateNameRole:
        state->name = value.toString();
        break;
     case StateTotalSizeRole:
        state->area = value.toInt();
        break;
    }

    if (mStates->setStateAt(index.row(), state)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags StateModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> StateModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[StateNameRole] = "stateName";
    names[StateTotalSizeRole] = "stateArea";
    return names;
}


States *StateModel::states() const
{

    return mStates;
}

void StateModel::setstates(States *states)
{
    beginResetModel();
        if (mStates)
            mStates->disconnect(this);

        mStates = states;

//        if (mStates) {
//            connect(mStates, &States::preStateAppended, this, [=]() {
//                const int index = mStates->items().size();
//                beginInsertRows(QModelIndex(), index, index);
//            });
//            connect(mStates, &States::postStateAppended, this, [=]() {
//                endInsertRows();
//            });
//            connect(mStates, &States::preStateRemoved, this, [=](int index) {
//                beginRemoveRows(QModelIndex(), index, index);
//            });
//            connect(mStates, &States::postStateRemoved, this, [=]() {
//                endRemoveRows();
//            });
//        }

        endResetModel();
}
