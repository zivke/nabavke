#include "dodavanjedobavljaca.h"
#include "ui_dodavanjedobavljaca.h"
#include <QSqlQueryModel>

dodavanjedobavljaca::dodavanjedobavljaca(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dodavanjedobavljaca)
{
    ui->setupUi(this);
    QSqlQueryModel *model = new QSqlQueryModel();
    QTreeView *view = ui->treeView;
    model->setQuery("SELECT '', '', '', '' ");
    model->setHeaderData(0, Qt::Horizontal, "Ime");
    model->setHeaderData(1, Qt::Horizontal, "Adresa");
    model->setHeaderData(2, Qt::Horizontal, "E-mail");
    model->setHeaderData(3, Qt::Horizontal, "Tel/Fax");
    view->setModel(model);
}

dodavanjedobavljaca::~dodavanjedobavljaca()
{
    delete ui;
}
