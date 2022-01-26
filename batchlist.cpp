#include "batchlist.h"



BatchList::BatchList(QObject *parent) : QObject(parent)
{


    /*    QString val;
    QFile file;
    file.setFileName("./errorList.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString("errorList"));
    QJsonObject item = value.toObject();
    QJsonArray errorList = item["imp"].toArray();


    for(int i=0;i<errorList.size();i++){
        mItems.append({ false,QString(errorList[i].toString())});
    }*/

    /*QString value;

    mItems.append({false, QString("Geri")});

    for(int i=1;i<batch+1;i++){

        value = QString::number(i);
        mItems.append({ false,QString(value)});
    }*/




}

QVector<BatchItem> BatchList::items() const
{
    return mItems;
}

bool BatchList::setItemAt(int index, const BatchItem &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const BatchItem &oldItem = mItems.at(index);
    if (item.done == oldItem.done && item.description == oldItem.description)
        return false;

    mItems[index] = item;
    return true;
}

void BatchList::batchSetter(int batchNumber){

    batch = batchNumber;
}

void BatchList::createList(){
    QString value;

    mItems.append({false, QString("Geri")});

    for(int i=1;i<batch+1;i++){

        value = QString::number(i);
        mItems.append({ false,QString(value)});
    }

}
