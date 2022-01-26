#include "backend.h"


Backend::Backend(QObject * parent): QObject(parent){

    /* file.setFileName("./errorList.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString("errorList"));
    QJsonObject item = value.toObject();
    errorList = item["imp"].toArray();

    file.setFileName("./workOrder.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    d = QJsonDocument::fromJson(val.toUtf8());
    sett2 = d.object();
    value = sett2.value(QString("workOrder"));
    item = value.toObject();
    workOrder = item["imp"].toArray();*/

}


bool Backend::rfid_Pass(){

    std::cout<<" Non-master entrance."<<std::endl;
    emit sign();
    return true;

}



Q_INVOKABLE int Backend::done(QVariant trueNum){

    file.setFileName("./trueLog.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
    QTextStream stream(&file);
    int num= trueNum.toInt();

    stream <<workOrder[0].toString() <<date.currentDate().toString("dd-MM-yyyy") <<" "<<time.currentTime().toString()<<" "<<"T-Stuck "<<"|"<<" "<<"Dogru cikan parca sayisi: " <<truePartQuantity;
    file.close();
    qDebug()<<"True part quantity is:" <<truePartQuantity;

    return num;

}



//error names are collected here from Qml.
Q_INVOKABLE void Backend::error_Track(QVariant a){

    errorList.push_back("Geri");
    errorList.push_back("Dokum Boslugu");
    errorList.push_back("Catlak");
    errorList.push_back("Yamuk");
    errorList.push_back("Soguk Birlesme");
    errorList.push_back("Pim Kirilmasi");
    errorList.push_back("Ayar Hatali");
    errorList.push_back("Dokum Hatali");
    errorList.push_back("Mastar Hatasi");
    errorList.push_back("Olcu Hatasi");
    errorList.push_back("Trim Hatasi");
    errorList.push_back("Eksen Kacik");
    errorList.push_back("Hatali Isleme");
    errorList.push_back("Yanlis Baglama");
    errorList.push_back("Diger");



    file.setFileName("./errorLog.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
    QTextStream stream(&file);


    int errorIndex = a.toInt();

    stream << date.currentDate().toString("dd-MM-yyyy") <<" "<<time.currentTime().toString()<<" "<<"T-Stuck "<<"|"<< errorList[errorIndex].toString()<<" "<<  "Hatali parca sayisi: " << falsePartQuantity;
    file.close();


    qDebug() << "The error is : "<< errorList[errorIndex].toString();
    qDebug() << "False part quantity is: " << falsePartQuantity;

    /*
    QString command = "cd / ; touch ASD";
    system(qPrintable(command));*/
}

QStringList Backend::json_Info(){



    QStringList rfid_List;

    QString str1=" Ad Soyad";


    rfid_List << str1<<workOrder[0].toString()<<workOrder[1].toString();

    return rfid_List;


}

int Backend::truePartQuantityGetter(){


    return truePartQuantity;
}

void Backend::truePartQuantityAddition(){

    truePartQuantity=truePartQuantity+batch;

}

void Backend:: truePartQuantitySubstraction(){

    truePartQuantity=truePartQuantity-falsePartNum;
}
int Backend::falsePartQuantityGetter(){

    return falsePartQuantity;


}

void Backend::falsePartQuantityAddition(){
    if(batch!=1){
    falsePartQuantity=falsePartQuantity+falsePartNum;
    }
    else {
        falsePartQuantity++;
    }
}

int Backend::batchGetter(){

    return batch;
}


void Backend::falsePartNumSetter(int falseVariant){

    falsePartNum=falseVariant;
    qDebug()<<falsePartNum;


}

void Backend::resetTruePartQuantity(){

    truePartQuantity=0;
}

int Backend::partNumGetter(){

    return partNum;
}

int Backend::falsePartNumGetter(){
    return falsePartNum;
}







