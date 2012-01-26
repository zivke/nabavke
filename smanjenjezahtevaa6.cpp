#include "smanjenjezahtevaa6.h"
#include "ui_smanjenjezahtevaa6.h"

SmanjenjeZahtevaA6::SmanjenjeZahtevaA6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SmanjenjeZahtevaA6)
{
    ui->setupUi(this);
}

SmanjenjeZahtevaA6::~SmanjenjeZahtevaA6()
{
    delete ui;
}

void SmanjenjeZahtevaA6::on_pushButton_3_clicked()
{
    this->close();
}
