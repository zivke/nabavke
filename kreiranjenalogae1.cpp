#include "kreiranjenalogae1.h"
#include "ui_kreiranjenalogae1.h"
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QSqlError>
#include<QTextEdit>

kreiranjenalogae1::kreiranjenalogae1(QWidget *parent) :
    QWidget(parent),

    ui(new Ui::kreiranjenalogae1)
{
    ui->setupUi(this);
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    setModelOgranakComboBox();
}

kreiranjenalogae1::~kreiranjenalogae1()
{
    delete ui;
}

void kreiranjenalogae1::setModelOgranakComboBox()
{
        QComboBox *view = ui->comboBox_2;
        modelCombo = new QSqlTableModel(this);
        modelCombo->setTable("nalog");
        modelCombo->setEditStrategy(QSqlTableModel::OnManualSubmit);
        modelCombo->select();
        view->setModel(modelCombo);
        view->setModelColumn(1);
}

void kreiranjenalogae1::on_pushButton_clicked()
{
    this->close();
}

void kreiranjenalogae1::on_pushButton_2_clicked()
{
    //inicijalizujemo vrednosti koje unosimo u bazu
    QString ime=ui->lineEdit->text();
    QString prezime=ui->lineEdit_2->text();
    QString username=ui->lineEdit_3->text();
    QString password1=ui->lineEdit_4->text();
    QString password = QString(QCryptographicHash::hash(password1.toUtf8(),QCryptographicHash::Md5).toHex());
    QString tip =ui->comboBox->currentText();
    int ogranak = modelCombo->data(modelCombo->index(ui->comboBox_2->currentIndex(), 0)).toInt();

    //Unosimo vrednosti u bazu podataka
    QSqlQuery q;
    q.prepare("insert into nalog (id_ogranka, ime, prezime, user, pass, tip) values (?, ?, ?, ?,?,?)");
    q.bindValue(0, ogranak);
    q.bindValue(1, ime);
    q.bindValue(2, prezime);
    q.bindValue(3, username);
    q.bindValue(4, password);
    q.bindValue(5, tip);

    if(q.exec())
    {
     QMessageBox::warning(this, "Kreiranje naloga", "Uspesno kreiran nalog");
     this->close();
    }
    else
    {QMessageBox::warning(this, "Kreiranje naloga", "Greska prilikom kreiranja naloga");}
}
