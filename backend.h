#ifndef BACKEND_H
#define BACKEND_H

#include <iostream>
#include <QString>
#include <QObject>
#include <QGuiApplication>

#include <vector>
#include <sstream>
#include <fstream>

#include <QDebug>

#include <QVariantMap>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>
#include <QTime>
#include <QThread>
#include <QTimer>
#include <QDir>


#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>



class Backend : public QObject

{
    Q_OBJECT
    Q_PROPERTY(QStringList json_Info READ json_Info CONSTANT)

public:

    Backend(QObject * parent=NULL);

    QJsonArray errorList;
    QStringList errors;
    QStringList json_Info();
    QJsonArray workOrder;
    QString val;
    QFile file;
    QTextStream stream;
    QTime time;
    QDate date;


private:
    int truePartQuantity=0;
    int falsePartQuantity=0;
    int batch =1;
    int falsePartNum=0;
    int partNum=497;


signals:
    void sign();


public slots:
    void error_Track(QVariant a);
    int done(QVariant trueNum);
    bool rfid_Pass();
    int truePartQuantityGetter();
    void truePartQuantityAddition();
    int falsePartQuantityGetter();
    void falsePartQuantityAddition(); //hatalı parça sayılarını topluyor batchsiz için.
    int batchGetter(); //headerdaki batch sayısını alıyor
    void truePartQuantitySubstraction(); //program batchli parçalar için çalışırken hatalı ve hatasız parça sayısını hesaplıyor.
    void falsePartNumSetter(int falseVariant); // batch listesindeki hatalı çıkan parça sayısını UI üzerinden gelen veriye göre set ediyoruz.
    void resetTruePartQuantity(); //iş emri tamamlandığında progress circle'ı ve logu resetliyor.
    int partNumGetter(); // iş emri ile gelen parça adedini alıyor
    int falsePartNumGetter(); //batch listesindeki hatalı çıkan parça sayısını alıyor


};





#endif // BACKEND_H
