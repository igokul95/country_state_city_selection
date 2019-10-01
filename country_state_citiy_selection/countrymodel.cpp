#include "countrymodel.h"
#include "country.h"

#include <QDebug>

CountryModel::CountryModel(QObject *parent)
    : QAbstractListModel(parent), mCountries(nullptr)
{
    Countries *Country = new Countries();
    mCountries = Country;
}

int CountryModel::rowCount(const QModelIndex &parent) const
{

    if (parent.isValid() || !mCountries ) {
        return 0;
    }

    return mCountries->items().size();
}

QVariant CountryModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mCountries)
        return QVariant();
    const CountryItem *country = mCountries->items().at(index.row());
    switch (role) {
    case CountryNameRole:
        return QVariant(country->name);

    }

    return QVariant();
}

Qt::ItemFlags CountryModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> CountryModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[CountryNameRole] = "name";
    return names;
}

Countries *CountryModel::countries() const
{
    qDebug() << "countries in countrymode";
    return mCountries;
}

void CountryModel::setcountries(Countries *countries)
{
    beginResetModel();

        if (mCountries)
            mCountries->disconnect(this);

        mCountries = countries;



        endResetModel();
}
