#include "pretrazivanjesredstavad1.h"
#include "ui_pretrazivanjesredstavad1.h"
#include <QSqlQuery>

PretrazivanjeSredstavaD1::PretrazivanjeSredstavaD1(QWidget *parent, int userId)
    : QDialog(parent),
      ui(new Ui::PretrazivanjeSredstavaD1)
{
	ui->setupUi(this);
	setModelSredstva();
}

PretrazivanjeSredstavaD1::~PretrazivanjeSredstavaD1()
{
	delete ui;
}

void PretrazivanjeSredstavaD1::on_btnIzadji_clicked()
{
	this->close();
}

void PretrazivanjeSredstavaD1::setModelSredstva()
{
	QComboBox *view = ui->cbSredstva;
	modelSredstva = new QSqlQueryModel();
	modelSredstva->setQuery("select * from artikal;");
	view->setModel(modelSredstva);
	view->setModelColumn(1);
}

void PretrazivanjeSredstavaD1::setModelGodina()
{

}

void PretrazivanjeSredstavaD1::setModelOrgJedinica()
{

}

void PretrazivanjeSredstavaD1::setModelStanjeSredstva()
{

}

void PretrazivanjeSredstavaD1::on_btnPretrazi_clicked()
{

}

void PretrazivanjeSredstavaD1::on_btnObrisiSve_clicked()
{

}
