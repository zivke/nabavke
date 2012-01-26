#include "slanjenarudzbeniceb1.h"
#include "ui_slanjenarudzbeniceb1.h"
#include "QSqlQueryModel"
SlanjeNarudzbeniceB1::SlanjeNarudzbeniceB1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SlanjeNarudzbeniceB1)
{
    ui->setupUi(this);
    QSqlQueryModel *model = new QSqlQueryModel();
    QTreeView *view = ui->tvStavke;
    model->setQuery("SELECT '', '', '', '', ''");
    model->setHeaderData(0, Qt::Horizontal, "Naziv");
    model->setHeaderData(1, Qt::Horizontal, "Kolicina");
    model->setHeaderData(2, Qt::Horizontal, "Cena po jedinici");
    model->setHeaderData(3, Qt::Horizontal, "Dobavljac");
    model->setHeaderData(4, Qt::Horizontal, "Ukupno");
    view->setModel(model);
}

SlanjeNarudzbeniceB1::~SlanjeNarudzbeniceB1()
{
    delete ui;
}

void SlanjeNarudzbeniceB1::on_btnIzadji_clicked()
{
    this->close();
}
