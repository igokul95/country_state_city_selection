#ifndef CITYMODEL_H
#define CITYMODEL_H

#include <QAbstractListModel>

class City;

class CityModel: public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(City* cities READ cities WRITE setCities)
public:
    explicit CityModel(QObject *parent = nullptr);

    enum {
        CityNameRole = Qt::UserRole,
    };
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    City* cities() const;
    void setCities(City *cities);

private:
    City* mCities;
};

#endif // CITYMODEL_H
