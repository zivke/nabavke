#include "prijemsredstavab2.h"
#include "ui_prijemsredstavab2.h"
#include <QSqlQueryModel>
PrijemSredstavaB2::PrijemSredstavaB2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrijemSredstavaB2)
{
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);
    QSqlQueryModel *model = new QSqlQueryModel();
    QTreeView *view = ui->treeStavke;
    model->setQuery("SELECT '', '', ''");
    model->setHeaderData(0, Qt::Horizontal, "Naziv");
    model->setHeaderData(1, Qt::Horizontal, "Kolicina");
    model->setHeaderData(2, Qt::Horizontal, "Raspodeljeno");
    view->setModel(model);
}

PrijemSredstavaB2::~PrijemSredstavaB2()
{
    delete ui;
}

void PrijemSredstavaB2::on_zapamti_2_clicked()
{
    this->close();
}
