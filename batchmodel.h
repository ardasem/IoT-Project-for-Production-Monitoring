#ifndef BATCHMODEL_H
#define BATCHMODEL_H

#include <QAbstractListModel>

class BatchList;

class BatchModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(BatchList *list READ list WRITE setList)

public:
    explicit BatchModel(QObject *parent = nullptr);

    enum {
        DoneRole = Qt::UserRole,
        DescriptionRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    BatchList *list() const;
    void setList(BatchList *list);

private:
    BatchList *mList;
};

#endif // BATCHMODEL_H
