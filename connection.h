#ifndef CONNECTION_H
#define CONNECTION_H
#include "mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QSqlDatabase>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    /*QString path(QDir::home().path());
    path.append(QDir::separator()).append(".jukebox/baza.db");
    path = QDir::toNativeSeparators(path);*/
    QString path = "baza.db";
    if(!QFile::exists(path))
    {
        QMessageBox::critical(0, qApp->tr("Baza ne postoji"),
            qApp->tr("Mora da se kreira fajl baze, posto trenutno ne postoji.\n"), QMessageBox::Cancel);
    }
    db.setDatabaseName(path);
    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"), QMessageBox::Cancel);
        return false;
    }
    return true;
}

#endif // CONNECTION_H
