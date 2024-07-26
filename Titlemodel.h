#ifndef TITLEMODEL_H
#define TITLEMODEL_H

#include <QAbstractListModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariantMap>

class TitleModel : public QAbstractListModel {
    Q_OBJECT

public:
    enum TitleRoles {
        TitleRole = Qt::UserRole + 1
    };

    TitleModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void initializeDatabase();
    void fetchAllRecords();

private:
    QSqlDatabase db;
    QList<QVariantMap> records;
};

#endif // TITLEMODEL_H
