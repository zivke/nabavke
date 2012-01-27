#include "deaktivacijanalogae2.h"
#include "ui_deaktivacijanalogae2.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

deaktivacijanalogae2::deaktivacijanalogae2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deaktivacijanalogae2)
{
    ui->setupUi(this);
    setModelKorisnici();
}

deaktivacijanalogae2::~deaktivacijanalogae2()
{
    delete ui;
}

void deaktivacijanalogae2::on_pushButton_2_clicked()
{
    this->close();
}

void deaktivacijanalogae2::setModelKorisnici()
{
    QString str;
    QTreeView *view = ui->treeView;
    modelKorisnici = new QSqlQueryModel();
    modelKorisnici->setQuery("select nalog.id, ime, prezime, user, nalog.tip, ogranak.naziv from nalog join ogranak on nalog.id_ogranka = ogranak.id_ogranka");

    modelKorisnici->setHeaderData(1, Qt::Horizontal, "Ime");
    modelKorisnici->setHeaderData(2, Qt::Horizontal, "Prezime");
    modelKorisnici->setHeaderData(3, Qt::Horizontal, "Username");
    modelKorisnici->setHeaderData(4, Qt::Horizontal, "Tip");
    modelKorisnici->setHeaderData(5, Qt::Horizontal, "Ogranak");
    view->setModel(modelKorisnici);
    view->setColumnHidden(0, true);
    view->setSortingEnabled(true);

    //povezujemo odabrani red sa unosom ispod treeview-a
    selectionModel = ui->treeView->selectionModel();
    connect(selectionModel,
            SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
            this, SLOT(deleteSelection(const QItemSelection &, const QItemSelection &)));
}

void deaktivacijanalogae2::deleteSelection(const QItemSelection &selected,
    const QItemSelection &deselected)
{
    QModelIndex index;
        QModelIndexList items = selected.indexes();
        index = items.first();
        _odabraniUser = modelKorisnici->data(modelKorisnici->index(index.row(), 0)).toInt();

}

void deaktivacijanalogae2::on_pushButton_clicked()
{
    QSqlQuery query;
    query.prepare(QString("DELETE FROM nalog WHERE id='%1'").arg(_odabraniUser));
    if(query.exec()){
         QMessageBox::warning(this, "Deaktivacija naloga", "Nalog je deaktiviran.");
         this->close();
    }
}
