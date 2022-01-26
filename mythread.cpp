#include "mythread.h"


MyButtonThread::MyButtonThread()
{}

MyButtonThread::~MyButtonThread()
{}

void MyButtonThread::infiniteloopChanger(){
    infiniteloop=0;
}

void MyButtonThread::pageIndexChanger(QVariant pageIndex){

    PageIndex = pageIndex.toInt();

}
void MyButtonThread::run(){

    exec();
    quit();
    wait();
}

void MyButtonThread::exec(){


    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {


        qDebug() << "Name : " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();

        // Example use QSerialPort
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite)){
            qDebug()<<"Serial open.";
        }
        while(infiniteloop==1){



            int numRead = 0, numReadTotal = 0;
            char buffer[50];



                numRead  = serial.read(buffer, 50);

                // Do whatever with the array

                numReadTotal += numRead;
                //qDebug() << buffer[0] << " " << numRead << " " << numReadTotal << endl;

                    if (buffer[0] == 'a') {
                        qDebug() << "rotaryDown" << endl;
                        emit rdsign();
                        buffer[0]=0;

                    }

                    if (buffer[0]== 'b'){
                        qDebug()<< "rotaryUp"<< endl;
                        emit rusign();
                        buffer[0]=0;

                    }

                    if (buffer[0]== 'e'){
                        qDebug()<< "rotaryEnter"<< endl;
                        emit resign();
                        buffer[0]=0;

                    }


                    if (buffer[0] == 'g') {
                        qDebug() << "Green Pressed" << endl;
                        emit gsign();
                        buffer[0]=0;


                    }
                    if (buffer[0] == 'r') {
                        qDebug() << "Red Pressed" << endl;
                        emit rsign();
                        buffer[0]=0;


                    }
                    if (buffer[0] == 'y') {
                        qDebug() << "Yellow Pressed" << endl;
                        emit ysign();
                        buffer[0]=0;


                    }





                if (numRead == 0 && !serial.waitForReadyRead()) {
                   // qDebug() << "serial read error" << endl;
                    //break;
                }


                //serial.close();


        }

    }

}
