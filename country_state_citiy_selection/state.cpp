#include "state.h"

States::States(QObject *parent) : QObject(parent)
{

}

QList<StateItem*> States::items() const
{
    return _states;
}

bool States::setStateAt(int index, StateItem *state)
{
    if (index < 0 || index >= _states.size())
        return false;

    const StateItem *oldState = _states.at(index);
    if (state->name == oldState->name && state->area == oldState->area)
        return  false;

    _states[index] = state;
    return true;

}

bool States::setStates(QList<StateItem*> states)
{
    _states = states;
    return true;
}


void States::appendState(StateItem *state)
{
    emit preStateAppended();
    _states.append(state);

    emit postStateAppended();
}
