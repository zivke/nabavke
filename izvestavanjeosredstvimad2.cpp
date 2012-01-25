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
	delete ui;
}

void IzvestavanjeOSredstvimaD2::on_btnIzadji_clicked()
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

void IzvestavanjeOSredstvimaD2::on_btnPrikazi_clicked()
{
	QTreeView *view = ui->tvIzvestaj;
	modelTableIzvestaj = new QSqlQueryModel(this);
	QString query = "select id_stavke, a.ime, substr(sp.datum,4,2), substr(sp.datum,-4), n.ime || ' ' || n.prezime, o.naziv, d.naziv, st.status, st.trazena_kol, st.odobrena_kol \
			         from stavka st join artikal a on st.id_artikla = a.id_artikla \
			         join spisak sp on sp.id_spiska = st.id_spiska \
			         join nalog n on sp.id_naloga = n.id \
			         join ogranak o on n.id_ogranka = o.id_ogranka \
			         join dobavljac d on st.id_dobavljaca = d.id_dobavljaca where 1=1";

	if(ui->cbMesec->currentIndex())
	{
		if(ui->cbMesec->currentIndex() < 10)
			query +=" and substr(sp.datum,4,2) = '0" + QString("%1").arg(ui->cbMesec->currentIndex()) + "'";
		else
			query +=" and substr(sp.datum,4,2) = '" + QString("%1").arg(ui->cbMesec->currentIndex()) + "'";
	}

	if(ui->cbGodina->currentText().compare("Sve"))
			query +=" and substr(sp.datum,-4) = '" + ui->cbGodina->currentText() + "'";


	modelTableIzvestaj->setQuery(query);
	modelTableIzvestaj->setHeaderData(1, Qt::Horizontal, "Naziv sredstva");
	modelTableIzvestaj->setHeaderData(2, Qt::Horizontal, "Mesec");
	modelTableIzvestaj->setHeaderData(3, Qt::Horizontal, "Godina");
	modelTableIzvestaj->setHeaderData(4, Qt::Horizontal, "Zaposleni");
	modelTableIzvestaj->setHeaderData(5, Qt::Horizontal, "Organizaiona jedinica");
	modelTableIzvestaj->setHeaderData(6, Qt::Horizontal, "Dobavljac");
	modelTableIzvestaj->setHeaderData(7, Qt::Horizontal, "Stanje");
	modelTableIzvestaj->setHeaderData(8, Qt::Horizontal, "Trazena kolicina");
	modelTableIzvestaj->setHeaderData(9, Qt::Horizontal, "Odobrena kolicina");
	view->setModel(modelTableIzvestaj);
	view->setSortingEnabled(true);
	view->setColumnHidden(0, true);
	if(modelTableIzvestaj->rowCount()==0)
			QMessageBox::warning(this, "Pretraga", "Ne postoje stavke za trazene vrednosti. Pokusajte ponovo.");
}
