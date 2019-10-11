#include "city.h"

City::City(QObject *parent) : QObject(parent)
{

}

QVector<CityItem *> City::items() const
{
    return _cities;
}

bool City::setStates(QVector<CityItem *> cities)
{
    _cities = cities;
    return true;
}

void City::appendState(CityItem *city)
{
    emit preCityAppended();
    _cities.append(city);
    emit postCityAppended();
}
