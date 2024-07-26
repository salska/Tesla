#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "TitleModel.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<TitleModel>("Tesla", 1, 0, "TitleModel");

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection
        );
    engine.loadFromModule("Tesla", "Main");

    return app.exec();
}

