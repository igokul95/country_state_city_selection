#ifndef COUNTRY_H
#define COUNTRY_H

#include <QObject>
#include <QVector>

#include "state.h"

struct CountryItem {
    QString name;
    States* states;
};

class Countries : public QObject
{
    Q_OBJECT
public:
    explicit Countries(QObject *parent = nullptr);
    QVector<CountryItem*> items() const;

    Q_INVOKABLE States* getStatesAt(int index);

signals:

public slots:
private:
    QVector<CountryItem*> _countries;
};

#endif // COUNTRY_H
