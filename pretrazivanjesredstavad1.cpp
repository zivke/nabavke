#include "pretrazivanjesredstavad1.h"
#include "ui_pretrazivanjesredstavad1.h"
#include <QSqlQuery>
#include <QMessageBox>

PretrazivanjeSredstavaD1::PretrazivanjeSredstavaD1(QWidget *parent, int userId)
    : QDialog(parent),
      ui(new Ui::PretrazivanjeSredstavaD1)
{
	ui->setupUi(this);
	_userId = userId;

	QSqlQuery query;
	query.prepare( "SELECT tip FROM nalog WHERE id = ?");
	query.bindValue(0, _userId);
	query.exec();

	if(query.next())
		tipNaloga = query.value(0).toString();

	setModelSredstva();
	setModelGodina();
	setModelOrgJedinica();
	setModelDobavljac();
	setModelStatusSredstva();
	setModelZaposleni();
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
	modelSredstva->setQuery("select -1 as A, 'Svi' as B union select * from artikal;");
	view->setModel(modelSredstva);
	view->setModelColumn(1);
}

void PretrazivanjeSredstavaD1::setModelGodina()
{
	QComboBox *view = ui->cbGodina;
	modelGodina = new QSqlQueryModel();
	modelGodina->setQuery("select 'Sve' union select distinct(substr(datum, -4)) as godina from spisak order by godina;");
	view->setModel(modelGodina);
	view->setModelColumn(0);
	view->setCurrentIndex(view->findText("Sve"));
}

void PretrazivanjeSredstavaD1::setModelOrgJedinica()
{
	QComboBox *view = ui->cbOrgJedinica;
	modelOrgJedinica = new QSqlQueryModel();
	if(!tipNaloga.compare("rukovodilac"))
	{
		modelOrgJedinica->setQuery("select o.id_ogranka, o.naziv \
									from ogranak o join nalog n on o.id_ogranka = n.id_ogranka \
									where n.id = " + QString("%1").arg(_userId) + ";");
		view->setModel(modelOrgJedinica);
		view->setModelColumn(1);
		view->setDisabled(true);
	}
	else
	{
		modelOrgJedinica->setQuery("select -1, 'Sve', -1, -1 union select * from ogranak;");
		view->setModel(modelOrgJedinica);
		view->setModelColumn(1);
	}
}

void PretrazivanjeSredstavaD1::setModelDobavljac()
{
	QComboBox *view = ui->cbDobavljac;
	modelDobavljac = new QSqlQueryModel();
	modelDobavljac->setQuery("select -1, 'Svi', -1 union select * from dobavljac;");
	view->setModel(modelDobavljac);
	view->setModelColumn(1);
}

void PretrazivanjeSredstavaD1::setModelStatusSredstva()
{
	QComboBox *view = ui->cbStatusSredstva;
	modelStatusSredstva = new QSqlQueryModel();
	modelStatusSredstva->setQuery("select 'Svi' union select distinct(status) from stavka;");
	view->setModel(modelStatusSredstva);
	view->setModelColumn(0);
	view->setCurrentIndex(view->findText("Svi"));
}

void PretrazivanjeSredstavaD1::setModelZaposleni()
{
	QComboBox *view = ui->cbZaposleni;
	modelZaposleni = new QSqlQueryModel();
	if(!tipNaloga.compare("zaposleni"))
	{
		modelZaposleni->setQuery("select id, ime || ' ' || prezime from nalog where id = " + QString("%1").arg(_userId) + ";");
		view->setModel(modelZaposleni);
		view->setModelColumn(1);
		view->setDisabled(true);
	}
	else
	{
		modelZaposleni->setQuery("select -1, 'Svi' union select id, ime || ' ' || prezime from nalog where tip = 'zaposleni';");
		view->setModel(modelZaposleni);
		view->setModelColumn(1);
	}
}

void PretrazivanjeSredstavaD1::on_btnPretrazi_clicked()
{
	QTreeView *view = ui->tvPretraga;
	modelTablePretraga = new QSqlQueryModel(this);
	QString query = "select id_stavke, a.ime, substr(sp.datum,4,2), substr(sp.datum,-4), n.ime || ' ' || n.prezime, o.naziv, d.naziv, st.status, st.trazena_kol, st.odobrena_kol \
			         from stavka st join artikal a on st.id_artikla = a.id_artikla \
			         join spisak sp on sp.id_spiska = st.id_spiska \
			         join nalog n on sp.id_naloga = n.id \
			         join ogranak o on n.id_ogranka = o.id_ogranka \
			         join dobavljac d on st.id_dobavljaca = d.id_dobavljaca where 1=1";

	if(ui->cbSredstva->currentIndex())
		query +=" and id_stavke = " + modelSredstva->data(modelSredstva->index(ui->cbSredstva->currentIndex(),0)).toString();

	if(ui->cbMesec->currentIndex())
	{
		if(ui->cbMesec->currentIndex() < 10)
			query +=" and substr(sp.datum,4,2) = '0" + QString("%1").arg(ui->cbMesec->currentIndex()) + "'";
		else
			query +=" and substr(sp.datum,4,2) = '" + QString("%1").arg(ui->cbMesec->currentIndex()) + "'";
	}

	if(ui->cbGodina->currentText().compare("Sve"))
			query +=" and substr(sp.datum,-4) = '" + ui->cbGodina->currentText() + "'";

	if(!tipNaloga.compare("zaposleni"))
	{
		query +=" and n.id = " + QString("%1").arg(_userId);
	}
	else if(ui->cbZaposleni->currentIndex())
			query +=" and n.id = " + modelZaposleni->data(modelZaposleni->index(ui->cbZaposleni->currentIndex(),0)).toString();

	if(!tipNaloga.compare("rukovodilac"))
	{
		query +=" and o.id_ogranka = " + modelOrgJedinica->data(modelOrgJedinica->index(ui->cbOrgJedinica->currentIndex(),0)).toString();
	}
	else if(ui->cbOrgJedinica->currentIndex())
				query +=" and o.id_ogranka = " + modelOrgJedinica->data(modelOrgJedinica->index(ui->cbOrgJedinica->currentIndex(),0)).toString();

	if(ui->cbDobavljac->currentIndex())
					query +=" and d.id_dobavljaca = " + modelDobavljac->data(modelDobavljac->index(ui->cbDobavljac->currentIndex(),0)).toString();

	if(ui->cbStatusSredstva->currentText().compare("Svi"))
					query +=" and st.status like '" + ui->cbStatusSredstva->currentText() + "'";

	modelTablePretraga->setQuery(query);
	modelTablePretraga->setHeaderData(1, Qt::Horizontal, "Naziv sredstva");
	modelTablePretraga->setHeaderData(2, Qt::Horizontal, "Mesec");
	modelTablePretraga->setHeaderData(3, Qt::Horizontal, "Godina");
	modelTablePretraga->setHeaderData(4, Qt::Horizontal, "Zaposleni");
	modelTablePretraga->setHeaderData(5, Qt::Horizontal, "Organizaiona jedinica");
	modelTablePretraga->setHeaderData(6, Qt::Horizontal, "Dobavljac");
	modelTablePretraga->setHeaderData(7, Qt::Horizontal, "Stanje");
	modelTablePretraga->setHeaderData(8, Qt::Horizontal, "Trazena kolicina");
	modelTablePretraga->setHeaderData(9, Qt::Horizontal, "Odobrena kolicina");
	view->setModel(modelTablePretraga);
	view->setSortingEnabled(true);
	view->setColumnHidden(0, true);
	if(modelTablePretraga->rowCount()==0)
			QMessageBox::warning(this, "Pretraga", "Ne postoje stavke za trazene vrednosti. Pokusajte ponovo.");
}
