#include "spisakzahtevaa1.h"
#include "ui_spisakzahtevaa1.h"

spisakZahtevaA1::spisakZahtevaA1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::spisakZahtevaA1)
{
    ui->setupUi(this);
}

spisakZahtevaA1::~spisakZahtevaA1()
{
    delete ui;
}
