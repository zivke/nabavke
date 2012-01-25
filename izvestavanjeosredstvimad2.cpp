#include "izvestavanjeosredstvimad2.h"

IzvestavanjeOSredstvimaD2::IzvestavanjeOSredstvimaD2(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::IzvestavanjeOSredstvimaD2)
{
	ui->setupUi(this);
	setModelGodina();
	ui->btnOdstampaj->setEnabled(false);
	ui->btnSacuvaj->setEnabled(false);
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
	if(modelTableIzvestaj->rowCount())
	{
		ui->btnOdstampaj->setEnabled(true);
		ui->btnSacuvaj->setEnabled(true);
	}
}

QString IzvestavanjeOSredstvimaD2::napraviIzvestaj()
{
	QString html;
	    html += "<html><head></head><body>";
	    html += "<table width=\"100%\" border=\"5\" cellspacing=\"0\" cellpadding=\"5\"><tr> \
	    		 <td align=\"center\" bgcolor=\"lightgrey\" bordercolor=\"#666666\"><font size=\"5\" face=\"arial\">IZVESTAJ</font></td></tr></table>";

	    //dodavanje stavki
	    html +="<br /><table width=\"100%\" border=\"5\" cellspacing=\"0\" cellpadding=\"5\">";
	    html +="<tr><th>RBR</th><th>Artikal</th><th>Mesec</th><th>Godina</th><th>Zaposleni</th><th>Org. Jedinica</th><th>Dobavljac</th><th>Stanje</th><th>Trazena kol.</th><th>Odobrena kol.</th></tr>";
	    int brR = modelTableIzvestaj->rowCount();
	    for (int i =0; i<brR; i++)
	    {
	        html +="<tr><td>" + QString::number(i+1)+".</td>";
	        html += "<td>" + modelTableIzvestaj->data(ui->tvIzvestaj->model()->index(i, 1)).toString()+"</td>";
	        html += "<td>" + modelTableIzvestaj->data(ui->tvIzvestaj->model()->index(i, 2)).toString()+"</td>";
	        html += "<td>" + modelTableIzvestaj->data(ui->tvIzvestaj->model()->index(i, 3)).toString()+"</td>";
	        html += "<td>" + modelTableIzvestaj->data(ui->tvIzvestaj->model()->index(i, 4)).toString()+"</td>";
	        html += "<td>" + modelTableIzvestaj->data(ui->tvIzvestaj->model()->index(i, 5)).toString()+"</td>";
	        html += "<td>" + modelTableIzvestaj->data(ui->tvIzvestaj->model()->index(i, 6)).toString()+"</td>";
	        html += "<td>" + modelTableIzvestaj->data(ui->tvIzvestaj->model()->index(i, 7)).toString()+"</td>";
	        html += "<td>" + modelTableIzvestaj->data(ui->tvIzvestaj->model()->index(i, 8)).toString()+"</td>";
	        html += "<td>" + modelTableIzvestaj->data(ui->tvIzvestaj->model()->index(i, 9)).toString()+"</td>";
	        html += "</tr>";
	    }
	    html += "</table><br />";
	    html += "</body></html>";

	    return html;
}

void IzvestavanjeOSredstvimaD2::on_btnOdstampaj_clicked()
{
	QPrinter printer;
	QPrintDialog printDialog(&printer, this);
	if (printDialog.exec()) {
		QTextDocument textDocument;
		textDocument.setHtml(napraviIzvestaj());
		textDocument.print(&printer);
	}
}

void IzvestavanjeOSredstvimaD2::on_btnSacuvaj_clicked()
{
	QString filename = QFileDialog::getSaveFileName(this, "Sacuvaj kao", "", "*.html");
	QFile f( filename );
	f.open( QIODevice::WriteOnly );
	QString html = napraviIzvestaj();
	f.write(html.toUtf8());
	f.close();
}
