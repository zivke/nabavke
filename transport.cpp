#include "transport.h"
#include "ui_transport.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

Transport::Transport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transport)
{
    ui->setupUi(this);
    setModelStavke();
    ui->bttransport->setEnabled(false);

}



Transport::~Transport()
{
    delete ui;
}


void Transport::setModelStavke()
{
         QTreeView *view = ui->treeStavke;
        modelStavke = new QSqlQueryModel();
        modelStavke->setQuery("select stavka.id_stavke, ogranak.naziv, artikal.ime, sum(odobrena_kol), status, stavka.id_artikla from stavka join artikal on stavka.id_artikla=artikal.id_artikla  join spisak on spisak.id_spiska = stavka.id_spiska join nalog on spisak.id_naloga=nalog.id join ogranak on nalog.id_ogranka= ogranak.id_ogranka where status= 'U_TRANSPORTU' group by artikal.ime");
        view->setModel(modelStavke);

    modelStavke->setHeaderData(1, Qt::Horizontal, "Ogranak");
     modelStavke->setHeaderData(2, Qt::Horizontal, "Artikal");
     modelStavke->setHeaderData(3, Qt::Horizontal, "Ukupna kolicina");

   //  view->setModel(modelStavke);
     view->setColumnHidden(4, true);
     view->setColumnHidden(0, true);
     view->setColumnHidden(5, true);
     view->setSortingEnabled(true);
     selectionModel = ui->treeStavke->selectionModel();
    connect(selectionModel,SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),this, SLOT(updateSelection(const QItemSelection &, const QItemSelection &)));


}

void Transport::updateSelection(const QItemSelection &selected,
    const QItemSelection &deselected)
{

    QModelIndex index;
    QModelIndexList items = selected.indexes();
    index = items.first();
    _odabranaStavkaId = modelStavke->data(modelStavke->index(index.row(), 5)).toInt();

    ui->bttransport->setEnabled(true);
}





void Transport::on_bttransport_clicked()
{
    QSqlQuery query;
    query.prepare(QString("UPDATE stavka SET status ='U_ORG_JED' WHERE id_artikla='%1'").arg(_odabranaStavkaId));
        if(!query.exec()){
            qDebug() << query.lastQuery();
            QMessageBox::warning(this, "Transport stavke", "Greska prilikom transporta stavke.");
        }
        else{
            setModelStavke();
            zaTransport.append(_odabranaStavkaId);
        }



}

void Transport::on_pushButton_clicked()
{
     this->close();
}
