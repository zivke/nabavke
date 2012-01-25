#include "izvestavanjeosredstvimad2.h"

IzvestavanjeOSredstvimaD2::IzvestavanjeOSredstvimaD2(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::IzvestavanjeOSredstvimaD2)
{
	ui->setupUi(this);
	setModelGodina();
}

IzvestavanjeOSredstvimaD2::~IzvestavanjeOSredstvimaD2()
{
	this->close();
}

void IzvestavanjeOSredstvimaD2::setModelGodina()
{
	QComboBox *view = ui->cbGodina;
	modelGodina = new QSqlQueryModel();
	modelGodina->setQuery("select 'Sve' union select distinct(substr(datum, -4)) as godina from spisak order by godina;");
	view->setModel(modelGodina);
	view->setModelColumn(0);
	view->setCurrentIndex(view->findText("Sve"));
}
