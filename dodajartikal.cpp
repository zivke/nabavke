#include "dodajartikal.h"
#include "ui_dodajartikal.h"
#include "QSqlQueryModel"
DodajArtikal::DodajArtikal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajArtikal)
{
    ui->setupUi(this);
    QSqlQueryModel *model = new QSqlQueryModel();
    QTreeView *view = ui->tvArtikli;
    model->setQuery("SELECT ''");
    model->setHeaderData(0, Qt::Horizontal, "Naziv");
    view->setModel(model);
}

DodajArtikal::~DodajArtikal()
{
    delete ui;
}
