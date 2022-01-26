#ifndef TODOLIST_H
#define TODOLIST_H

#include <QString>
#include <QObject>
#include <QVector>
#include <vector>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>
#include <QDebug>


struct ToDoItem
{
    bool done;
    QString description;
};

class ToDoList : public QObject
{
    Q_OBJECT
public:

    explicit ToDoList(QObject *parent = nullptr);
    void GetList();



    QVector<ToDoItem> items() const;


    bool setItemAt(int index, const ToDoItem &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();


private:
    QVector<ToDoItem> mItems;
};

#endif // TODOLIST_H
