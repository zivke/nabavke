#include "biranjedobavljacaa4.h"
#include "ui_biranjedobavljacaa4.h"

BiranjeDobavljacaA4::BiranjeDobavljacaA4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BiranjeDobavljacaA4)
{
    ui->setupUi(this);
}

BiranjeDobavljacaA4::~BiranjeDobavljacaA4()
{
    delete ui;
}
