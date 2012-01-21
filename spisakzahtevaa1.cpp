#include "spisakzahtevaa1.h"
#include "ui_spisakzahtevaa1.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

spisakZahtevaA1::spisakZahtevaA1(QWidget *parent, int userId) :
    QDialog(parent),
    ui(new Ui::spisakZahtevaA1)
{
    _userId = userId;
    ui->setupUi(this);
    setModelArtikliCombo();
    //ubacujemo novi red u tabelu
    QSqlQuery q;
    q.prepare("insert into spisak (id_naloga, datum) values ("+QString("%1").arg(_userId)+", strftime('%d.%m.%Y','now'))");
    if(!q.exec())
        QMessageBox::warning(this, "Dodavanje spiska", "Greska prilikom dodavanja spiska");
    _lastId = q.lastInsertId().toInt();
    //qDebug() << q.lastInsertId().toInt();
    setModelArtikliTable();

}

spisakZahtevaA1::~spisakZahtevaA1()
{
    delete ui;
}
void spisakZahtevaA1::setModelArtikliCombo()
{
    QComboBox *view = ui->cbArtikli;
    modelCombo = new QSqlTableModel(this);
    modelCombo->setTable("artikal");
    modelCombo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelCombo->select();
    view->setModel(modelCombo);
    view->setModelColumn(1);
}
void spisakZahtevaA1::setModelArtikliTable()
{

    QTreeView *view = ui->tvStavke;
    modelTable = new QSqlQueryModel(this);
    //konverzija int-a u string
    QString str;
    str.append(QString("%1").arg(_lastId));
    //postavljamo upit za model
    modelTable->setQuery("select id_stavke, ime, trazena_kol from stavka join artikal on stavka.id_artikla = artikal.id_artikla where id_spiska ="+str);
    //definisemo nazive zaglavlja
    modelTable->setHeaderData(1, Qt::Horizontal, "Naziv");
    modelTable->setHeaderData(2, Qt::Horizontal, "Kolicina");
    //postavljamo model na tree view
    view->setModel(modelTable);
    //sortiranje omoguceno
    view->setSortingEnabled(true);
    //sakrivamo prvu kolonu jer je to id stavke
    view->setColumnHidden(0, true);
}

void spisakZahtevaA1::on_btnDodaj_clicked()
{
    int idArtikla = modelCombo->data(modelCombo->index(ui->cbArtikli->currentIndex(), 0)).toInt();
    int kol = ui->sbKolicina->value();
    QSqlQuery q;
    q.prepare("insert into stavka (id_spiska, id_artikla, trazena_kol, status) values (?, ?, ?, ?)");
    q.bindValue(0, _lastId);
    q.bindValue(1, idArtikla);
    q.bindValue(2, kol);
    q.bindValue(3, "UNETO");
    if(!q.exec())
        QMessageBox::warning(this, "Dodavanje spiska", "Greska prilikom dodavanja spiska");
    //qDebug() << q.lastError();
    //qDebug() << q.lastQuery();
    setModelArtikliTable();
}

void spisakZahtevaA1::on_bntSaveExit_clicked()
{
    this->close();
}
