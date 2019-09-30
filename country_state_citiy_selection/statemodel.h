#ifndef STATEMODEL_H
#define STATEMODEL_H

#include <QAbstractListModel>

class States;

class StateModel: public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(States *states READ states WRITE setstates)
public:
    explicit StateModel(QObject *parent = nullptr);

    enum {
        StateNameRole = Qt::UserRole,
        StateTotalSizeRole,
    };
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    States *states() const;
    void setstates(States *states);

private:
    States *mStates;
};

#endif // STATEMODEL_H
