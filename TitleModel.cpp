#include "TitleModel.h"
#include <QCoreApplication>
#include <QStandardPaths>
#include <QFile>
#include <QDir>
#include <QDebug>

TitleModel::TitleModel(QObject *parent)
    : QAbstractListModel(parent) {
    initializeDatabase();
    fetchAllRecords();
}

void TitleModel::initializeDatabase() {
    QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/teslaDB.db";
    QFile dbFile(":/resources/database/teslaDB.db");

    if (!QFile::exists(dbPath)) {
        QDir dir;
        dir.mkpath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
        dbFile.copy(dbPath);
        QFile::setPermissions(dbPath, QFile::WriteOwner | QFile::ReadOwner);
    }

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qDebug() << "Error: Could not connect to database.";
    }
}

void TitleModel::fetchAllRecords() {
    if (!db.isOpen()) {
        qDebug() << "Database is not open!";
        return;
    }

    QSqlQuery query("SELECT title FROM menus");
    while (query.next()) {
        QSqlRecord record = query.record();
        QVariantMap row;
        row.insert("title", record.value("title"));
        records.append(row);
    }
}

int TitleModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return records.count();
}

QVariant TitleModel::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= records.count())
        return QVariant();

    const QVariantMap &record = records[index.row()];
    if (role == TitleRole)
        return record.value("title");

    return QVariant();
}

QHash<int, QByteArray> TitleModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    return roles;
}
