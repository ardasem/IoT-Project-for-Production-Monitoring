#include "batchmodel.h"

#include "batchlist.h"



BatchModel::BatchModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int BatchModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant BatchModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const BatchItem item = mList->items().at(index.row());
    switch (role) {
    case DoneRole:
        return QVariant(item.done);
    case DescriptionRole:
        return QVariant(item.description);
    }

    return QVariant();
}

bool BatchModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    BatchItem item = mList->items().at(index.row());
    switch (role) {
    case DoneRole:
        item.done = value.toBool();
        break;
    case DescriptionRole:
        item.description = value.toString();
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags BatchModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> BatchModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[DoneRole] = "done";
    names[DescriptionRole] = "description";
    return names;
}

BatchList *BatchModel::list() const
{
    return mList;
}

void BatchModel::setList(BatchList *list)
{
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &BatchList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &BatchList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(mList, &BatchList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &BatchList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}

