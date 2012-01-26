#include "odobravanjekolicinaa2.h"
#include "ui_odobravanjekolicinaa2.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
OdobravanjeKolicinaA2::OdobravanjeKolicinaA2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OdobravanjeKolicinaA2)
{
    ui->setupUi(this);
    setModelZaposleni();
    //setModelStavke(2);
    ui->groupBox->setEnabled(false);
    connect(ui->cbZaposleni, SIGNAL(activated(int)), this, SLOT(zaposleniPromenjen(int)));
    ui->lbNaziv->setText("");
    ui->lbKolicina->setText("");
}

OdobravanjeKolicinaA2::~OdobravanjeKolicinaA2()
{
    delete ui;
}

void OdobravanjeKolicinaA2::setModelZaposleni()
{
    QComboBox *view = ui->cbZaposleni;
    modelZaposleni = new QSqlQueryModel();
    modelZaposleni->setQuery("SELECT -1 AS A, 'Izaberite zaposlenog...' AS B UNION select id, ime ||' '|| prezime from nalog");
    modelZaposleni->setHeaderData(1, Qt::Horizontal, "Zaposleni");
    view->setModel(modelZaposleni);
    view->setModelColumn(1);
}

void OdobravanjeKolicinaA2::setModelStavke(int idZaposlenog)
{
    QString str;
    str.append(QString("%1").arg(idZaposlenog));
    QTreeView *view = ui->tvArtikli;
    modelStavke = new QSqlQueryModel();
    modelStavke->setQuery("select nalog.id, status, artikal.ime, trazena_kol, odobrena_kol, id_stavke from stavka \
                          join artikal on stavka.id_artikla=artikal.id_artikla \
                          join spisak on stavka.id_spiska = spisak.id_spiska \
                          join nalog on spisak.id_naloga = nalog.id where status = 'UNETO' and nalog.id = \""+ str+"\"");

    modelStavke->setHeaderData(2, Qt::Horizontal, "Naziv");
    modelStavke->setHeaderData(3, Qt::Horizontal, "Trazena kol");
    modelStavke->setHeaderData(4, Qt::Horizontal, "Odobrena kol");
    view->setModel(modelStavke);
    view->setColumnHidden(0, true);
    view->setColumnHidden(1, true);
    view->setColumnHidden(5, true);
    view->setSortingEnabled(true);
    //povezujemo odabrani red sa unosom ispod treeview-a
    selectionModel = ui->tvArtikli->selectionModel();
    connect(selectionModel,
            SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
            this, SLOT(updateSelection(const QItemSelection &, const QItemSelection &)));

}
void OdobravanjeKolicinaA2::updateSelection(const QItemSelection &selected,
    const QItemSelection &deselected)
{

    ui->groupBox->setEnabled(true);
    QModelIndex index;
    QModelIndexList items = selected.indexes();
    index = items.first();
    //QMessageBox::warning(this, "", QString("(%1,%2)").arg(index.row()).arg(index.column()));
    ui->lbNaziv->setText(modelStavke->data(modelStavke->index(index.row(), 2)).toString());
    ui->lbKolicina->setText(modelStavke->data(modelStavke->index(index.row(), 3)).toString());
    ui->inputOdobrena->setValue(modelStavke->data(modelStavke->index(index.row(), 4)).toInt());
    _odabranaStavkaId = modelStavke->data(modelStavke->index(index.row(), 5)).toInt();
}



void OdobravanjeKolicinaA2::changeCurrent(const QModelIndex &current,
    const QModelIndex &previous)
{
}
void OdobravanjeKolicinaA2::zaposleniPromenjen(int index)
{
    _odabraniUser = index;
    setModelStavke(modelZaposleni->data(modelZaposleni->index(_odabraniUser, 0)).toInt());


}

void OdobravanjeKolicinaA2::on_btnOdobri_clicked()
{
    QSqlQuery query;
    int kolicina = ui->inputOdobrena->value();
    query.prepare(QString("UPDATE stavka SET odobrena_kol=%1 WHERE id_stavke='%2'").arg(kolicina).arg(_odabranaStavkaId));
    if(!query.exec()){
        QMessageBox::warning(this, "Odobravanje stavke", "Greska prilikom odobravanja stavke.");
    }
    else{
        setModelStavke(modelZaposleni->data(modelZaposleni->index(_odabraniUser, 0)).toInt());
        zaOdobravanje.append(_odabranaStavkaId);
    }
}

void OdobravanjeKolicinaA2::on_btnSaveExit_clicked()
{
    QString qs;
    for (int i=0; i<zaOdobravanje.size(); i++)
    {
        if(i!=zaOdobravanje.size()-1){
            qs+= QString("%1, ").arg(zaOdobravanje.at(i));
        }
        else{
            qs+= QString("%1").arg(zaOdobravanje.at(i));
        }
    }
    QSqlQuery query;
    query.prepare(QString("UPDATE stavka SET status=%1 WHERE id_stavke in (%2)").arg("'ODOBRENO'").arg(qs));
    if(!query.exec()){
        QMessageBox::warning(this, "Odobravanje stavki", "Greska prilikom odobravanja stavki.");
    }
    else{
        this->close();
    }
}
