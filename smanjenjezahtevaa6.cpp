#include "smanjenjezahtevaa6.h"
#include "ui_smanjenjezahtevaa6.h"

SmanjenjeZahtevaA6::SmanjenjeZahtevaA6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SmanjenjeZahtevaA6)
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

SmanjenjeZahtevaA6::~SmanjenjeZahtevaA6()
{
    delete ui;
}

void SmanjenjeZahtevaA6::on_pushButton_3_clicked()
{
    this->close();
}
