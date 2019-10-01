#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


#include "state.h"
#include "country.h"
#include "statemodel.h"
#include "countrymodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<CountryModel>("Country", 1, 0, "CountryModel");
    qmlRegisterType<StateModel>("State", 1, 0, "StateModel");

    qmlRegisterUncreatableType<Countries>("Country", 1, 0, "Countries",
        QStringLiteral("Countries should not be created in QML"));

    qmlRegisterUncreatableType<States>("State", 1, 0, "States",
        QStringLiteral("States should not be created in QML"));

    Countries countries;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("countries"), &countries);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
