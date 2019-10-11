#include "country.h"
#include <QDebug>

Countries::Countries(QObject *parent) : QObject(parent)
{
    States* stateslist1 = new States();
    StateItem *state = new StateItem();
    state->name = "Kerala";
    state->area = 50000;
    stateslist1->appendState(state);

    City* cityList1 = new City();
    CityItem* city1 = new CityItem();
    city1->name = "Kottayam";
    cityList1->appendState(city1);


    States* stateslist2 = new States();
    StateItem *state2 = new StateItem();
    state2->name = "MachuPichu";
    state2->area = 40000;
    stateslist2->appendState(state2);

    StateItem *state3 = new StateItem();
    state3->name = "MachuPichu 2";
    state3->area = 40000;
    stateslist2->appendState(state3);


    City* cityList2 = new City();
    CityItem* city2 = new CityItem();
    city2->name = "Lost City";
    cityList2->appendState(city2);

    CountryItem *country1 = new CountryItem();
    country1->name = QStringLiteral("India");
    country1->states = stateslist1;
    country1->cities = cityList1;

    CountryItem *country2 = new CountryItem();
    country2->name = QStringLiteral("Peru");
    country2->states = stateslist2;
    country2->cities = cityList2;

    _countries.append(country1);
    _countries.append(country2);
}

QList<CountryItem*> Countries::items() const
{
    return _countries;
}

int Countries::activeCountry() const
{
    return _activeCountry;
}

void Countries::activeCountry(int currentCountry)
{
    _activeCountry = currentCountry;
}

States *Countries::statesOfActiveCountry() const
{
    if ( _activeCountry >= 0 && _activeCountry <= _countries.size()) {
        qDebug() << "index at getStatesAt" << _activeCountry << _countries[_activeCountry]->states->items().first()->name;
        return _countries[_activeCountry]->states;
    }
    else {
        States* stateslist = new States();
        StateItem *state = new StateItem();
        state->name = "Default state";
        state->area = 50000;

        stateslist->appendState(state);
        return  stateslist;
    }
}

City *Countries::citiesOfActiveCountry() const
{
    if ( _activeCountry >= 0 && _activeCountry <= _countries.size()) {
        qDebug() << "index at getStatesAt" << _activeCountry << _countries[_activeCountry]->states->items().first()->name;
        return _countries[_activeCountry]->cities;
    }
    else {
        City* cityList1 = new City();
        CityItem* city1 = new CityItem();
        city1->name = "Default City";
        cityList1->appendState(city1);
        return  cityList1;
    }
}



