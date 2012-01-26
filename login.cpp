#include "login.h"
#include "ui_login.h"
#include <QCryptographicHash>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    _parent = parent;
    ui->setupUi(this);
    ui->inputPass->setEchoMode(QLineEdit::Password);
    //ui->inputUser->setText(QString(QCryptographicHash::hash(("myPassword"),QCryptographicHash::Md5).toHex()));
    _login = false;
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnLogin_clicked()
{

    QString user = ui->inputUser->text();
    QString pass1 = ui->inputPass->text();
    if(user.length()!=0 && pass1.length()!=0)
    {
        QString pass = QString(QCryptographicHash::hash(pass1.toUtf8(),QCryptographicHash::Md5).toHex());
        QSqlQuery query;
        query.prepare("SELECT * FROM nalog WHERE user=\""+user+"\" AND pass=\""+pass+"\" ");
        if(!query.exec())
        {
            QMessageBox::warning(this, "Povezivanje", "Nemoguce pronalazenje klijenta.");
            ui->inputPass->setText("");
            ui->inputUser->setText("");
        }
        else{
            query.first();
            if(!query.isNull(4))
            {
                emit ucitanKorisnik(query.value(2).toString()+" "+query.value(3).toString(), query.value(0).toInt());
                _parent->setEnabled(true);
                _login = true;
                this->close();
            }
            else
            {
                QMessageBox::warning(this, "Povezivanje", "Nemoguce pronalazenje klijenta.");
                ui->inputPass->setText("");
                ui->inputUser->setText("");
            }
        }
    }
    else
    {
        QMessageBox::warning(this, "Prazna polja", "Polja ne mogu biti prazna!");
    }
}
void Login::closeEvent(QCloseEvent *event)
{
    if(!_login)
        _parent->close();

}
