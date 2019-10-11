#ifndef COUNTRYMODEL_H
#define COUNTRYMODEL_H
#include <QAbstractListModel>

class Countries;

class CountryModel: public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(Countries *countries READ countries WRITE setcountries)
public:
    explicit CountryModel(QObject *parent = nullptr);
    enum {
        CountryNameRole = Qt::UserRole,
    };
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

//    bool setData(const QModelIndex &index, const QVariant &value,
//                 int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    Countries *countries() const;
    void setcountries(Countries *countries);

private:
    Countries *mCountries;

};

#endif // COUNTRYMODEL_H
