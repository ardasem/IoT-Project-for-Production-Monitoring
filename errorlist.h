#include <iostream>
#include <QString>
#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <vector>
#include <sstream>
#include <fstream>
#include <QQmlComponent>
#include <QQuickView>
#include <QQuickItem>
#include <QDebug>
#include <QQmlProperty>
#include <QString>
#include <QVariantMap>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QAbstractListModel>






#ifndef ERRORLIST_H
#define ERRORLIST_H


class ErrorList
{
public:
    ErrorList(const QString &errorName);
};

class ErrorListModel : public QAbstractListModel
{
    Q_OBJECT
    public:
    enum ErrorRoles{
        ErrorRole= Qt::UserRole+1
    };

    ErrorListModel(QObject *parent=0);

    QHash<int,QByteArray> ErrorListModel::roleNames() const{
        QHash<int,QByteArray> {

        }

    }

};

#endif // ERRORLIST_H
