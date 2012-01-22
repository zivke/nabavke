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
	void on_btnObrisiSve_clicked();
	void on_btnIzadji_clicked();
	void setModelSredstva();
	void setModelGodina();
	void setModelOrgJedinica();
	void setModelStanjeSredstva();

private:
    Ui::PretrazivanjeSredstavaD1 *ui;
    QSqlQueryModel *modelSredstva;
    int _userId;
};

#endif // PRETRAZIVANJESREDSTAVAD1_H
