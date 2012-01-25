#include "biranjedobavljacaa4.h"
#include "ui_biranjedobavljacaa4.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

BiranjeDobavljacaA4::BiranjeDobavljacaA4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BiranjeDobavljacaA4)
{
    ui->setupUi(this);
    setModelDobavljaci();
    setModelStavke();
    ui->groupBox_2->setEnabled(false);
    ui->lbKolicina->setText("");
    ui->lbNaziv->setText("");
}

BiranjeDobavljacaA4::~BiranjeDobavljacaA4()
{
    delete ui;
}
void BiranjeDobavljacaA4::setModelDobavljaci()
{
    QComboBox *view = ui->cbDobavljac;
    modelDobavljaci = new QSqlQueryModel();
    modelDobavljaci->setQuery("select * from dobavljac");
    modelDobavljaci->setHeaderData(1, Qt::Horizontal, "Zaposleni");
    view->setModel(modelDobavljaci);
    view->setModelColumn(1);
}

void BiranjeDobavljacaA4::setModelStavke()
{
    QTreeView *view = ui->tvStavke;
    modelStavke = new QSqlQueryModel();
    modelStavke->setQuery("select stavka.id_artikla, ime as Ime, sum(odobrena_kol) as Kolicina, cena as Cena, naziv as Dobavljac \
                          from stavka join artikal \
                          on stavka.id_artikla = artikal.id_artikla \
                          left outer join dobavljac on stavka.id_dobavljaca = dobavljac.id_dobavljaca \
                          where status = 'ODOBRENO' \
                          group by ime");

    modelStavke->setHeaderData(1, Qt::Horizontal, "Artikal");
    modelStavke->setHeaderData(2, Qt::Horizontal, "Kolicina");
    modelStavke->setHeaderData(3, Qt::Horizontal, "Cena");
    modelStavke->setHeaderData(4, Qt::Horizontal, "Dobavljac");
    view->setModel(modelStavke);
    view->setColumnHidden(0, true);
    view->setSortingEnabled(true);
    //povezujemo odabrani red sa unosom ispod treeview-a
    selectionModel = ui->tvStavke->selectionModel();
    connect(selectionModel,
            SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
            this, SLOT(updateSelection(const QItemSelection &, const QItemSelection &)));

}
void BiranjeDobavljacaA4::updateSelection(const QItemSelection &selected,
    const QItemSelection &deselected)
{

    ui->groupBox_2->setEnabled(true);
    QModelIndex index;
    QModelIndexList items = selected.indexes();
    index = items.first();
    //QMessageBox::warning(this, "", QString("(%1,%2)").arg(index.row()).arg(index.column()));
    ui->lbNaziv->setText(modelStavke->data(modelStavke->index(index.row(), 1)).toString());
    ui->lbKolicina->setText(modelStavke->data(modelStavke->index(index.row(), 2)).toString());
    ui->inputOdobrena->setValue(modelStavke->data(modelStavke->index(index.row(), 3)).toFloat());
    //_odabranaStavkaId = modelStavke->data(modelStavke->index(index.row(), 5)).toInt();
    ui->cbDobavljac->setCurrentIndex(ui->cbDobavljac->findText(modelStavke->data(modelStavke->index(index.row(), 4)).toString()));
    _idArtika = modelStavke->data(modelStavke->index(index.row(), 0)).toInt();
}



void BiranjeDobavljacaA4::changeCurrent(const QModelIndex &current,
    const QModelIndex &previous)
{
}

void BiranjeDobavljacaA4::on_btnSacuvajIzadji_clicked()
{
    QString qs;
    for (int i=0; i<zaKompletiranje.size(); i++)
    {
        if(i!=zaKompletiranje.size()-1){
            qs+= QString("%1, ").arg(zaKompletiranje.at(i));
        }
        else{
            qs+= QString("%1").arg(zaKompletiranje.at(i));
        }
    }
    QSqlQuery query;
    query.prepare(QString("UPDATE stavka SET status=%1 WHERE id_artikla in (%2)").arg("'KOMPLETIRANO'").arg(qs));
    if(!query.exec()){
        qDebug() << query.lastQuery();
        QMessageBox::warning(this, "Odobravanje stavki", "Greska prilikom odobravanja stavki.");
    }
    else{
        this->close();
    }
}

void BiranjeDobavljacaA4::on_btnOdobri_clicked()
{
    QSqlQuery query;

    int idDobavljaca = modelDobavljaci->data(modelDobavljaci->index(ui->cbDobavljac->currentIndex(), 0)).toInt();
    float cena = ui->inputOdobrena->value();
    query.prepare(QString("UPDATE stavka SET cena=%1, id_dobavljaca='%2' WHERE id_artikla='%3'").arg(cena).arg(idDobavljaca).arg(_idArtika));
    if(!query.exec()){
        qDebug() << query.lastQuery();
        QMessageBox::warning(this, "Kompletiranje stavke", "Greska prilikom kompletiranja stavke.");
    }
    else{
        setModelStavke();
        zaKompletiranje.append(_idArtika);
    }
}
