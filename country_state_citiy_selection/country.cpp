#include "country.h"
#include <QDebug>

Countries::Countries(QObject *parent) : QObject(parent)
{
    States* stateslist1 = new States();
    StateItem *state = new StateItem();
    state->name = "Kerala";
    state->area = 50000;

    stateslist1->appendState(state);
    States* stateslist2 = new States();
    StateItem *state2 = new StateItem();
    state2->name = "MachuPichu";
    state2->area = 40000;
    stateslist2->appendState(state2);
    StateItem *state3 = new StateItem();
    state3->name = "MachuPichu 2";
    state3->area = 40000;
    stateslist2->appendState(state3);
    CountryItem *country1 = new CountryItem();
    country1->name = QStringLiteral("India");
    country1->states = stateslist1;
    CountryItem *country2 = new CountryItem();
    country2->name = QStringLiteral("Peru");
    country2->states = stateslist2;
    _countries.append(country1);
    _countries.append(country2);
}

QVector<CountryItem*> Countries::items() const
{
    return _countries;
}

States *Countries::getStatesAt(int index)
{
    if (index >= 0 && index <= _countries.size()) {
        qDebug() << "index at getStatesAt" << index << _countries[index]->states->items().first()->name;
        return _countries[index]->states;
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



