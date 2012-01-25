#include "transport.h"
#include "ui_transport.h"

Transport::Transport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transport)
{
    ui->setupUi(this);
}

Transport::~Transport()
{
    delete ui;
}
