#ifndef IZVESTAVANJEOSREDSTVIMAD2_H
#define IZVESTAVANJEOSREDSTVIMAD2_H

#include <QtGui/QDialog>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "ui_izvestavanjeosredstvimad2.h"

namespace Ui {
    class IzvestavanjeOSredstvimaD2;
}

class IzvestavanjeOSredstvimaD2 : public QDialog
{
    Q_OBJECT

public:
    IzvestavanjeOSredstvimaD2(QWidget *parent = 0);
    ~IzvestavanjeOSredstvimaD2();

private slots:
	void setModelGodina();
	void on_btnPrikazi_clicked();
	void on_btnIzadji_clicked();

private:
    Ui::IzvestavanjeOSredstvimaD2 *ui;
    QSqlQueryModel *modelGodina;
    QSqlQueryModel *modelTableIzvestaj;
};

#endif // IZVESTAVANJEOSREDSTVIMAD2_H
