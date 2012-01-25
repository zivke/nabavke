#ifndef IZVESTAVANJEOSREDSTVIMAD2_H
#define IZVESTAVANJEOSREDSTVIMAD2_H

#include <QtGui/QDialog>
#include <QSqlQueryModel>
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

private:
    Ui::IzvestavanjeOSredstvimaD2 *ui;
    QSqlQueryModel *modelGodina;
};

#endif // IZVESTAVANJEOSREDSTVIMAD2_H
