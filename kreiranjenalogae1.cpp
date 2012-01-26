#include "kreiranjenalogae1.h"
#include "ui_kreiranjenalogae1.h"

kreiranjenalogae1::kreiranjenalogae1(QWidget *parent) :
    QWidget(parent),

    ui(new Ui::kreiranjenalogae1)
{
    ui->setupUi(this);
    ui->lePassword->setEchoMode(QLineEdit::Password);
    setModelOgranakComboBox();
}

kreiranjenalogae1::~kreiranjenalogae1()
{
    delete ui;
}

void kreiranjenalogae1::setModelOgranakComboBox()
{
        QComboBox *view = ui->cbOgranak;
        modelOgranak = new QSqlQueryModel();
        modelOgranak->setQuery("select * from ogranak;");
        view->setModel(modelOgranak);
        view->setModelColumn(1);
}

void kreiranjenalogae1::on_btnOdustani_clicked()
{
    this->close();
}

void kreiranjenalogae1::on_btnSacuvajIzadji_clicked()
{
    //inicijalizujemo vrednosti koje unosimo u bazu
    QString ime=ui->leIme->text();
    QString prezime=ui->lePrezime->text();
    QString username=ui->leUsername->text();
    QString password1=ui->lePassword->text();
    QString password = QString(QCryptographicHash::hash(password1.toUtf8(),QCryptographicHash::Md5).toHex());
    QString tip =ui->cbTipKorisnika->currentText();
    int ogranak = modelOgranak->data(modelOgranak->index(ui->cbOgranak->currentIndex(), 0)).toInt();

    //Unosimo vrednosti u bazu podataka
    QSqlQuery q;
    q.prepare("insert into nalog (id_ogranka, ime, prezime, user, pass, tip) values (?, ?, ?, ?, ?, ?)");
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
    {
    	QMessageBox::warning(this, "Kreiranje naloga", "Greska prilikom kreiranja naloga");
    }
}
