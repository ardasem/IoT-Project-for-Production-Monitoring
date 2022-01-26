#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>


class MyButtonThread : public QThread
{
    Q_OBJECT
public:
    MyButtonThread();
    ~MyButtonThread();
    void run();
    void exec();
    int infiniteloop=1;
    int PageIndex=0;

public slots:
     void infiniteloopChanger();
     void pageIndexChanger(QVariant pageIndex);

signals:

    void gsign();
    void rsign();
    void ysign();
    void rdsign();
    void rusign();
    void resign();
    void rfsign();

};



#endif // MYTHREAD_H
