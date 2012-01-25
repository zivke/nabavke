#include "finansijskaodlukaa5.h"
#include "ui_finansijskaodlukaa5.h"
#include "QSqlQueryModel"
FinansijskaOdlukaA5::FinansijskaOdlukaA5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FinansijskaOdlukaA5)
{
    ui->setupUi(this);
    QSqlQueryModel *model = new QSqlQueryModel();
    QTreeView *view = ui->treeView;
    model->setQuery("SELECT '', '', '', '' ");
    model->setHeaderData(0, Qt::Horizontal, "Naziv");
    model->setHeaderData(1, Qt::Horizontal, "Kolicina");
    model->setHeaderData(2, Qt::Horizontal, "Cena po jedinici");
    model->setHeaderData(3, Qt::Horizontal, "Ukupno");
    view->setModel(model);
}

FinansijskaOdlukaA5::~FinansijskaOdlukaA5()
{
    delete ui;
}
