#include "todolist.h"



ToDoList::ToDoList(QObject *parent) : QObject(parent)
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

    mItems.append({false,QString("Geri")});
    mItems.append({ false,QString("Dokum Boslugu")});
    mItems.append({ false,QString("Catlak")});
    mItems.append({ false,QString("Yamuk")});
    mItems.append({ false,QString("Soguk Birlesme")});
    mItems.append({ false,QString("Pim Kirilmasi")});
    mItems.append({ false,QString("Ayar Hatali")});
    mItems.append({ false,QString("Dokum Hatali")});
    mItems.append({ false,QString("Mastar Hatasi")});
    mItems.append({ false,QString("Olcu Hatasi")});
    mItems.append({ false,QString("Trim Hatasi")});
    mItems.append({ false,QString("Eksen Kacik")});
    mItems.append({ false,QString("Hatali Isleme")});
    mItems.append({ false,QString("Yanlis Baglama")});
    mItems.append({ false,QString("Diger")});




}

QVector<ToDoItem> ToDoList::items() const
{
    return mItems;
}

bool ToDoList::setItemAt(int index, const ToDoItem &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const ToDoItem &oldItem = mItems.at(index);
    if (item.done == oldItem.done && item.description == oldItem.description)
        return false;

    mItems[index] = item;
    return true;
}


