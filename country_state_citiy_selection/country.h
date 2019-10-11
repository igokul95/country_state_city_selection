#ifndef COUNTRY_H
#define COUNTRY_H

#include <QObject>
#include <QVector>

#include "state.h"
#include "city.h"

struct CountryItem {
    QString name;
    States* states;
    City* cities;
};

class Countries : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int activeCountry READ activeCountry WRITE activeCountry)
    Q_PROPERTY(States* statesOfActiveCountry READ statesOfActiveCountry)
    Q_PROPERTY(City* citiesOfActiveCountry READ citiesOfActiveCountry)

public:
    explicit Countries(QObject *parent = nullptr);
    QList<CountryItem*> items() const;

    int activeCountry() const;
    void activeCountry(int currentCountry);

    States* statesOfActiveCountry() const;
    City* citiesOfActiveCountry() const;


signals:

public slots:

private:
    QList<CountryItem*> _countries;
    int _activeCountry;
};

#endif // COUNTRY_H
