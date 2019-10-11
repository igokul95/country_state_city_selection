#include "citymodel.h"

#include "city.h"

CityModel::CityModel(QObject *parent)
    : QAbstractListModel(parent), mCities(nullptr)
{

}

int CityModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mCities ) {
        return 0;
    }

    return mCities->items().size();
}

QVariant CityModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mCities)
        return QVariant();
    const CityItem *city = mCities->items().at(index.row());
    switch (role) {
    case CityNameRole:
        return QVariant(city->name);
    }

    return QVariant();

}

bool CityModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mCities)
        return false;
    CityItem *city = mCities->items().at(index.row());

    switch (role) {
    case CityNameRole:
        city->name = value.toString();
        break;
    }
    emit dataChanged(index, index, QVector<int>() << role);
    return true;

}

Qt::ItemFlags CityModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> CityModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[CityNameRole] = "cityName";
    return names;
}

City *CityModel::cities() const
{
    return mCities;
}

void CityModel::setCities(City *cities)
{

    beginResetModel();
    if (mCities)
        mCities->disconnect(this);

    mCities = cities;
    endResetModel();

}
