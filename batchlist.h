#ifndef BATCHLIST_H
#define BATCHLIST_H

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
#include <string>
#include <sstream>

struct BatchItem
{
    bool done;
    QString description;
};

class BatchList : public QObject
{
    Q_OBJECT
public:

    explicit BatchList(QObject *parent = nullptr);
    void GetList();
    void batchSetter(int batchNumber);
    void createList();


    QVector<BatchItem> items() const;


    bool setItemAt(int index, const BatchItem &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();


private:
    int batch;
    QVector<BatchItem> mItems;
};


#endif // BATCHLIST_H
