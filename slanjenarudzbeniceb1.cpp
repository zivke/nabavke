#include "slanjenarudzbeniceb1.h"
#include "ui_slanjenarudzbeniceb1.h"

SlanjeNarudzbeniceB1::SlanjeNarudzbeniceB1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SlanjeNarudzbeniceB1)
{
    ui->setupUi(this);
}

SlanjeNarudzbeniceB1::~SlanjeNarudzbeniceB1()
{
    delete ui;
}
