#ifndef CITY_H
#define CITY_H

#include <QObject>
#include <QVector>

struct CityItem {
    QString name;
};

class City : public QObject
{
    Q_OBJECT
public:
    explicit City(QObject *parent = nullptr);
    QVector<CityItem*> items() const;

    bool setStates(QVector<CityItem*> cities);

signals:
    void preCityAppended();
    void postCityAppended();

public slots:
    void appendState(CityItem *city);

private:
    QVector<CityItem*> _cities;
};

#endif // CITY_H
