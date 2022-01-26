#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <thread>
#include <string>
#include <QThread>
#include <QQmlContext>
#include <QtSerialPort/QSerialPort>


#include "todolist.h"
#include "todomodel.h"
#include "backend.h"
#include "mythread.h"
#include "batchlist.h"
#include "batchmodel.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<ToDoModel>("ToDo", 1, 0, "ToDoModel");
    qmlRegisterUncreatableType<ToDoList>("ToDo", 1, 0, "ToDoList",QStringLiteral("ToDoList should not be created in QML"));

    qmlRegisterType<BatchModel>("Batch", 1, 0, "BatchModel");
    qmlRegisterUncreatableType<BatchList>("Batch", 1, 0, "BatchList",QStringLiteral("ToDoList should not be created in QML"));
    qmlRegisterType<Backend>("Backend", 1, 0, "Backend");

    qmlRegisterType<MyButtonThread>("WorkerThreadButton",1,0,"WorkerThreadButton");


    Backend * backend =new Backend ;

    MyButtonThread * thb=new MyButtonThread;
    thb->start();


    ToDoList * toDoList= new ToDoList;
    BatchList * batchList= new BatchList;

    batchList->batchSetter(backend->batchGetter());
    batchList->createList();


    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("threadbutton", thb);

    engine.rootContext()->setContextProperty("backend",backend);
    engine.rootContext()->setContextProperty(QStringLiteral("toDoList"), toDoList);
    engine.rootContext()->setContextProperty(QStringLiteral("batchList"),batchList);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
