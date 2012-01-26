#include "raspodeli.h"
#include "ui_raspodeli.h"
#include <QMessageBox>

#include <QSqlQuery>
#include <QSqlError>

Raspodeli::Raspodeli(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Raspodeli)
{
    ui->setupUi(this);
    setModelZaposleni();
    connect(ui->comboZaposleni, SIGNAL(activated(int)), this, SLOT(zaposleniPromenjen(int)));
    ui->pushButton->setEnabled(false);
}

Raspodeli::~Raspodeli()
{
    delete ui;
}



void Raspodeli::setModelZaposleni()
{
    QComboBox *view = ui->comboZaposleni;
    modelZaposleni = new QSqlQueryModel();
    modelZaposleni->setQuery("SELECT -1 AS A, 'Izaberite zaposlenog...' AS B UNION select id, ime ||' '|| prezime from nalog");
    modelZaposleni->setHeaderData(1, Qt::Horizontal, "Zaposleni");
    view->setModel(modelZaposleni);
    view->setModelColumn(1);
}



void Raspodeli::setModelStavke(int idZaposlenog)
{
    QString str;
    str.append(QString("%1").arg(idZaposlenog));
    QTreeView *view = ui->treeStavke;
    modelStavke = new QSqlQueryModel();
    modelStavke->setQuery("select nalog.id, status, artikal.ime, odobrena_kol, id_stavke, case when status='U_ORG_JED' then 'NE' end as raspodeljeno from stavka \
                          join artikal on stavka.id_artikla=artikal.id_artikla \
                          join spisak on stavka.id_spiska = spisak.id_spiska \
                          join nalog on spisak.id_naloga = nalog.id where status = 'U_ORG_JED' and nalog.id = \""+ str+"\"");


    modelStavke->setHeaderData(2, Qt::Horizontal, "Naziv");
    modelStavke->setHeaderData(3, Qt::Horizontal, "Kolicina");
    view->setModel(modelStavke);
    view->setColumnHidden(0, true);
    view->setColumnHidden(1, true);
    view->setColumnHidden(4, true);
    view->setSortingEnabled(true);
    selectionModel = ui->treeStavke->selectionModel();
    connect(selectionModel,
            SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
            this, SLOT(updateSelection(const QItemSelection &, const QItemSelection &)));

}



void Raspodeli::updateSelection(const QItemSelection &selected,
    const QItemSelection &deselected)
{

    QModelIndex index;
    QModelIndexList items = selected.indexes();
    index = items.first();
    _odabranaStavkaId = modelStavke->data(modelStavke->index(index.row(), 4)).toInt();
    ui->pushButton->setEnabled(true);
}

void Raspodeli::changeCurrent(const QModelIndex &current,
    const QModelIndex &previous)
{
}


void Raspodeli::zaposleniPromenjen(int index)
{
    _odabraniUser = index;
    setModelStavke(modelZaposleni->data(modelZaposleni->index(_odabraniUser, 0)).toInt());


}



void Raspodeli::on_pushButton_clicked()
{

    QSqlQuery query;

    query.prepare(QString("UPDATE stavka SET status ='RASPODELJENO' WHERE id_stavke='%1'").arg(_odabranaStavkaId));
    if(!query.exec()){
        QMessageBox::warning(this, "Raspodela stavke", "Greska prilikom raspodele stavke.");
    }
    else{
        setModelStavke(modelZaposleni->data(modelZaposleni->index(_odabraniUser, 0)).toInt());
        zaRaspodelu.append(_odabranaStavkaId);
    }

}



void Raspodeli::on_zapamti_clicked()
{

    this->close();
  /*  QString qs;
       for (int i=0; i<zaRaspodelu.size(); i++)
       {
           if(i!=zaRaspodelu.size()-1){
               qs+= QString("%1, ").arg(zaRaspodelu.at(i));
           }
           else{
               qs+= QString("%1").arg(zaRaspodelu.at(i));
           }
       }
       QSqlQuery query;
       query.prepare(QString("UPDATE stavka SET status=%1 WHERE id_stavke in (%2)").arg("'RASPOREDJENO'").arg(qs));
       if(!query.exec()){
           QMessageBox::warning(this, "Raspodela stavki", "Greska prilikom raspodele stavki.");
       }
       else{
           this->close();
       }
*/
}
