#ifndef STATE_H
#define STATE_H

#include <QObject>
#include <QVector>

struct StateItem {
    QString name;
    int area;
};

class States : public QObject
{
    Q_OBJECT
public:
    explicit States(QObject *parent = nullptr);
    QList<StateItem*> items() const;

    bool setStateAt(int index, StateItem *state);
    bool setStates(QList<StateItem*> states);

signals:
    void preStateAppended();
    void postStateAppended();

    void preStateRemoved();
    void postStateRemoved();

public slots:
    void appendState(StateItem *state);

private:
    QList<StateItem*> _states;
};

#endif // STATE_H
