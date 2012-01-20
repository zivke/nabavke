#include <QtGui/QApplication>
#include "mainwindow.h"
#include "connection.h"
#include <QMessageBox>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!createConnection())
        qDebug("Veza sa bazom nije uspostavljena");
    else
        qDebug("Veza sa bazom je uspostavljena");
    MainWindow w;
    w.show();

    return a.exec();
}
