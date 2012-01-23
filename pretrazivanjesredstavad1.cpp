#include "pretrazivanjesredstavad1.h"
#include "ui_pretrazivanjesredstavad1.h"
#include <QSqlQuery>

PretrazivanjeSredstavaD1::PretrazivanjeSredstavaD1(QWidget *parent, int userId)
    : QDialog(parent),
      ui(new Ui::PretrazivanjeSredstavaD1)
{
	ui->setupUi(this);
	setModelSredstva();
	setModelGodina();
	setModelOrgJedinica();
	setModelDobavljac();
	setModelStatusSredstva();
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
	QComboBox *view = ui->cbGodina;
	modelGodina = new QSqlQueryModel();
	modelGodina->setQuery("select distinct(strftime('%Y', datum)) from spisak;");
	view->setModel(modelGodina);
	view->setModelColumn(0);
}

void PretrazivanjeSredstavaD1::setModelOrgJedinica()
{
	QComboBox *view = ui->cbOrgJedinica;
	modelOrgJedinica = new QSqlQueryModel();
	modelOrgJedinica->setQuery("select * from ogranak;");
	view->setModel(modelOrgJedinica);
	view->setModelColumn(1);
}

void PretrazivanjeSredstavaD1::setModelDobavljac()
{
	QComboBox *view = ui->cbDobavljac;
	modelDobavljac = new QSqlQueryModel();
	modelDobavljac->setQuery("select * from dobavljac;");
	view->setModel(modelDobavljac);
	view->setModelColumn(1);
}

void PretrazivanjeSredstavaD1::setModelStatusSredstva()
{
	QComboBox *view = ui->cbStatusSredstva;
	modelStatusSredstva = new QSqlQueryModel();
	modelStatusSredstva->setQuery("select distinct(status) from stavka;");
	view->setModel(modelStatusSredstva);
	view->setModelColumn(0);
}

void PretrazivanjeSredstavaD1::on_btnPretrazi_clicked()
{

}
