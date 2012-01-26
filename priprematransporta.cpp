#include "priprematransporta.h"
#include "ui_priprematransporta.h"

PripremaTransporta::PripremaTransporta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PripremaTransporta)
{
    ui->setupUi(this);
}

PripremaTransporta::~PripremaTransporta()
{
    delete ui;
}
