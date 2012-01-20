#include "odobravanjekolicinaa2.h"
#include "ui_odobravanjekolicinaa2.h"

OdobravanjeKolicinaA2::OdobravanjeKolicinaA2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OdobravanjeKolicinaA2)
{
    ui->setupUi(this);

    setModelArtikli();


}

OdobravanjeKolicinaA2::~OdobravanjeKolicinaA2()
{
    delete ui;
}
void OdobravanjeKolicinaA2::setModelArtikli()
{
    QComboBox *view = ui->cbZaposleni;
    model = new QSqlQueryModel();
    model->setQuery("select id, ime ||' '|| prezime from nalog");

    view->setModel(model);
    view->setModelColumn(1);
}
