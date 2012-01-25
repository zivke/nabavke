#include "dodavanjedobavljaca.h"
#include "ui_dodavanjedobavljaca.h"

dodavanjedobavljaca::dodavanjedobavljaca(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dodavanjedobavljaca)
{
    ui->setupUi(this);
}

dodavanjedobavljaca::~dodavanjedobavljaca()
{
    delete ui;
}
