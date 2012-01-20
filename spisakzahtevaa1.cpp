#include "spisakzahtevaa1.h"
#include "ui_spisakzahtevaa1.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

spisakZahtevaA1::spisakZahtevaA1(QWidget *parent, int userId) :
    QDialog(parent),
    ui(new Ui::spisakZahtevaA1)
{
    _userId = userId;
    ui->setupUi(this);
    setModelArtikli();
    //ubacujemo novi red u tabelu
    QSqlQuery q;
    q.prepare("insert into spisak (id_naloga, datum) values (2, strftime('%d.%m.%Y','now'))");
    if(!q.exec())
        QMessageBox::warning(this, "Dodavanje spiska", "Greska prilikom dodavanja spiska");
    _lastId = q.lastInsertId().toInt();
    //qDebug() << q.lastInsertId().toInt();
}

spisakZahtevaA1::~spisakZahtevaA1()
{
    delete ui;
}
void spisakZahtevaA1::setModelArtikli()
{
    QComboBox *view = ui->cbArtikli;
    model = new QSqlTableModel(this);
    model->setTable("artikal");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    view->setModel(model);
    view->setModelColumn(1);
}
