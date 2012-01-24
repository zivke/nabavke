#ifndef PRETRAZIVANJESREDSTAVAD1_H
#define PRETRAZIVANJESREDSTAVAD1_H

#include <QtGui/QDialog>
#include <QSqlQueryModel>
#include "ui_pretrazivanjesredstavad1.h"

namespace Ui {
    class PretrazivanjeSredstavaD1;
}

class PretrazivanjeSredstavaD1 : public QDialog
{
    Q_OBJECT

public:
    explicit PretrazivanjeSredstavaD1(QWidget *parent = 0, int userId = 0);
    ~PretrazivanjeSredstavaD1();

private slots:
	void on_btnPretrazi_clicked();
	void on_btnIzadji_clicked();
	void setModelSredstva();
	void setModelGodina();
	void setModelOrgJedinica();
	void setModelDobavljac();
	void setModelStatusSredstva();
	void setModelZaposleni();

private:
    Ui::PretrazivanjeSredstavaD1 *ui;
    QSqlQueryModel *modelSredstva;
    QSqlQueryModel *modelGodina;
    QSqlQueryModel *modelOrgJedinica;
    QSqlQueryModel *modelDobavljac;
    QSqlQueryModel *modelStatusSredstva;
    QSqlQueryModel *modelTablePretraga;
    QSqlQueryModel *modelZaposleni;
    int _userId;
    QString tipNaloga;
};

#endif // PRETRAZIVANJESREDSTAVAD1_H
