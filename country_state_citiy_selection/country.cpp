#include "country.h"

Countries::Countries(QObject *parent) : QObject(parent)
{
    States* stateslist1 = new States();
    StateItem state = {"Kerala", 50000};
    stateslist1->appendState(state);
    States* stateslist2 = new States();
    StateItem state2 = {"MachuPichu", 40000};
    stateslist2->appendState(state);
    _countries.append({QStringLiteral("India"), stateslist1});
    _countries.append({QStringLiteral("Peru"), stateslist2});
}

QVector<CountryItem> Countries::items() const
{
    return _countries;
}

States *Countries::getStatesAt(int index)
{
    if (index >= 0 && index <= _countries.size()) {
        return _countries[index].states;
    }
    else {
        States* stateslist = new States();
        StateItem state = {"Default State", 50000};
        stateslist->appendState(state);
        return  stateslist;
    }
}



