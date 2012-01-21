#include "slanjezahtevaa3.h"
#include "ui_slanjezahtevaa3.h"

SlanjeZahtevaA3::SlanjeZahtevaA3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SlanjeZahtevaA3)
{
    ui->setupUi(this);
}

SlanjeZahtevaA3::~SlanjeZahtevaA3()
{
    delete ui;
}

void SlanjeZahtevaA3::on_btnIzadji_clicked()
{
    this->close();
}
