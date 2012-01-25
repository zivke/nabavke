#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spisakzahtevaa1.h"
#include "login.h"
#include "odobravanjekolicinaa2.h"
#include "slanjezahtevaa3.h"
#include "biranjedobavljacaa4.h"
#include "pretrazivanjesredstavad1.h"
#include "raspodeli.h"
#include "izvestavanjeosredstvimad2.h"
#include "transport.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //disejblujemo glavnu formu dok se ne unese user/pass
    this->setDisabled(true);
    //otvaramo login formu
    Login *l = new Login(this);
    l->show();
    //pravimo konekciju signala i slota za komunikaciju
    //izmedju forme login i mainwindow
    QObject::connect(l, SIGNAL(ucitanKorisnik(QString, int)), this, SLOT(inicijalizacija(QString, int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnZahtevi_clicked()
{
    spisakZahtevaA1 *sz = new spisakZahtevaA1(this, _userId);
    sz->show();
}

void MainWindow::inicijalizacija(QString ime, int id)
{
    ui->lbIme->setText(ime);
    _userId = id;
    //konverzija int-a u string
    QString str;
    str.append(QString("%1").arg(_userId));

    ui->lbId->setText(str);
}

void MainWindow::on_btnOdobravanje_clicked()
{
    OdobravanjeKolicinaA2 *ok = new OdobravanjeKolicinaA2(this);
    ok->show();
}

void MainWindow::on_btnSlanjeZahteva_clicked()
{
    SlanjeZahtevaA3 *sz = new SlanjeZahtevaA3(this);
    sz->show();
}

void MainWindow::on_btnUnosDiC_clicked()
{
    BiranjeDobavljacaA4 *bd = new BiranjeDobavljacaA4();
    bd->show();
}

void MainWindow::on_btnPretrazivanje_clicked()
{
    PretrazivanjeSredstavaD1 *ps = new PretrazivanjeSredstavaD1(this, _userId);
    ps->show();
}

void MainWindow::on_btnRaspodeli_clicked()
{
    Raspodeli *rs = new Raspodeli(this);
    rs->show();
}

void MainWindow::on_btnIzvestaj_clicked()
{
	IzvestavanjeOSredstvimaD2 *is = new IzvestavanjeOSredstvimaD2(this);
	is->show();
}




void MainWindow::on_btnTransport_clicked()
{
    Transport *tr = new Transport(this);
    tr->show();
}
