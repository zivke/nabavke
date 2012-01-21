#include "slanjezahtevaa3.h"
#include "ui_slanjezahtevaa3.h"
#include "QPrintDialog"
#include "QPrinter"
#include "QTextDocument"

SlanjeZahtevaA3::SlanjeZahtevaA3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SlanjeZahtevaA3)
{
    ui->setupUi(this);
    setModelDobavljaci();
    setModelStavke();
}

SlanjeZahtevaA3::~SlanjeZahtevaA3()
{
    delete ui;
}

void SlanjeZahtevaA3::on_btnIzadji_clicked()
{
    this->close();
}
void SlanjeZahtevaA3::setModelDobavljaci()
{
    QComboBox *view = ui->cbDobavljaci;
    modelDobavljaci = new QSqlQueryModel();
    modelDobavljaci->setQuery("select * from dobavljac;");
    view->setModel(modelDobavljaci);
    view->setModelColumn(1);
}
void SlanjeZahtevaA3::setModelStavke()
{
    QTreeView *view = ui->tvStavke;
    modelStavke = new QSqlQueryModel();
    modelStavke->setQuery("select ime, sum(odobrena_kol) as ukupno \
                          from stavka join artikal on stavka.id_artikla = artikal.id_artikla \
                          where status = 'ODOBRENO' and odobrena_kol >0 \
                          GROUP BY ime;");

    modelStavke->setHeaderData(0, Qt::Horizontal, "Naziv");
    modelStavke->setHeaderData(1, Qt::Horizontal, "Odobrena kol");
    view->setModel(modelStavke);
    view->setSortingEnabled(true);

}

void SlanjeZahtevaA3::on_btnStampa_clicked()
{
    QString html;
    //QSqlQuery query, query2;
    html += "<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" /><style>table{border-style:solid; border-width:1px; border-color:#ccc;}</style></head><body>";
    html += "<table width=\"100%\" border=\"0\" cellspacing=\"0\" cellpadding=\"5\"><tr><td align=\"center\" bgcolor=\"lightgrey\" bordercolor=\"#666666\">Zahtev za ponudu</td></tr></table>";

    //dodavanje stavki
    html +="<br /><br /><br /><table width=\"100%\" cellspacing=\"0\" cellpadding=\"3\">";
    html +="<tr><td>r. br.</td><td>Artikal</td><td>Kolicina</td></tr>";
    int brR = modelStavke->rowCount();
    for (int i =0; i<brR; i++)
    {
        html +="<tr><td>";
        html +=QString::number(i+1)+".</td><td>";
        html += modelStavke->data(ui->tvStavke->model()->index(i, 0)).toString()+"</td><td>";
        html += modelStavke->data(ui->tvStavke->model()->index(i, 1)).toString()+"</td>";
        html += "</tr>";
    }
    html += "</table><br />";

//    html += "<table width=\"100%\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\"><tr><td width=\"50%\">Za:</td><td width=\"35%\">Od:</td>";
//    html += ime + "<br />"+adresa+", "+pbr+" "+mesto+"<br />e-mail: "+email+"<br />telefon: "+telefon+"<br />PIB: "+pib+"<br />MB:"+mb+"<br />&#381;iro racun: "+ziro;
//    html +="</td></tr></table><br />";
//    //naslov

//    html += "<table width=\"100%\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\"><tr><td width=\"50%\"></td><td width=\"50%\"  align=\"right\" valign=\"top\">";
//    html += "<br />Osnovica: "+ui->lb_osnovica->text()+"<br />PDV: "+ui->lb_opdv->text()+"<br />Rabat: "+ui->lb_orabat->text()+"<br />Ukupno: "+ui->lb_ukupno->text()+"<br />";
//    html +="</td></tr></table><hr />";
//    //QMessageBox::warning(this, "", _napomena);
//    if(_napomena!="")
//        html+="<br /><br />Napomena: "+_napomena+"<br /><br />";

//    html +="<br /><br /><table width=\"100%\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\"><tr><td width=\"33%\" align=\"center\">Za "+ime+"</td><td>&nbsp;</td>";
//    html +="<td align=\"center\">Potpis primaoca</td></tr><tr><td width=\"33%\"><p>&nbsp;</p><hr /></td><td>&nbsp;</td><td width=\"33%\"><p>&nbsp;</p><hr /></td></tr></table>";

    html += "</body></html>";
    printHtml(html);
}
void SlanjeZahtevaA3::printHtml(const QString &html)
{
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec()) {
        QTextDocument textDocument;
        textDocument.setHtml(html);
        textDocument.print(&printer);
    }
}
