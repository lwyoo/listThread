#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "listmodelcontrol.h"
#include <QThread>
#include <QDebug>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    //set thread name
    QThread::currentThread()->setObjectName("Main Thread");
    qDebug() << Q_FUNC_INFO << QThread::currentThread();

    QQmlApplicationEngine engine;
    ListModelControl::instance()->setRootContext(engine.rootContext());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}
