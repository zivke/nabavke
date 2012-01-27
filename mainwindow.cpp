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
#include "dodavanjedobavljaca.h"
#include "finansijskaodlukaa5.h"
#include "priprematransporta.h"
#include "smanjenjezahtevaa6.h"
#include "kreiranjenalogae1.h"
#include "deaktivacijanalogae2.h"
#include "slanjenarudzbeniceb1.h"
#include "prijemsredstavab2.h"
#include "dodajartikal.h"
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

/************* Iskljucivanje dugmica *****************************

    QSqlQuery query;
	query.prepare( "SELECT tip FROM nalog WHERE id = ?");
	query.bindValue(0, _userId);
	query.exec();

	if(query.next())
		_tipNaloga = query.value(0).toString();

	if(!_tipNaloga.compare("zaposleni"))
    {
    	ui->gbAdministratori->setEnabled(false);
    	ui->gbMagacioneri->setEnabled(false);
    	ui->gbMenadzeri->setEnabled(false);
    	ui->gbReferenti->setEnabled(false);
    	ui->gbRukovodioci->setEnabled(false);
    	ui->gbSekretari->setEnabled(false);
    }
	else if(!_tipNaloga.compare("rukovodilac"))
	{
		ui->gbAdministratori->setEnabled(false);
		ui->gbMagacioneri->setEnabled(false);
		ui->gbMenadzeri->setEnabled(false);
		ui->gbReferenti->setEnabled(false);
		ui->gbSekretari->setEnabled(false);
	}
	else if(!_tipNaloga.compare("referent_sluzbe"))
	{
		ui->gbAdministratori->setEnabled(false);
		ui->gbMagacioneri->setEnabled(false);
		ui->gbMenadzeri->setEnabled(false);
		ui->gbRukovodioci->setEnabled(false);
		ui->gbSekretari->setEnabled(false);
	}
	else if(!_tipNaloga.compare("menadzer"))
	{
		ui->gbAdministratori->setEnabled(false);
		ui->gbMagacioneri->setEnabled(false);
		ui->gbReferenti->setEnabled(false);
		ui->gbRukovodioci->setEnabled(false);
		ui->gbSekretari->setEnabled(false);
	}
	else if(!_tipNaloga.compare("sekretar"))
	{
		ui->gbAdministratori->setEnabled(false);
		ui->gbMagacioneri->setEnabled(false);
		ui->gbMenadzeri->setEnabled(false);
		ui->gbReferenti->setEnabled(false);
		ui->gbRukovodioci->setEnabled(false);
	}
*********************************************************/
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
    BiranjeDobavljacaA4 *bd = new BiranjeDobavljacaA4(this);
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

void MainWindow::on_btnDobavljaci_clicked()
{
    dodavanjedobavljaca *d = new dodavanjedobavljaca(this);
    d->show();
}

void MainWindow::on_pushButton_clicked()
{
    FinansijskaOdlukaA5 *fo  = new FinansijskaOdlukaA5(this);
    fo->show();
}

void MainWindow::on_btnpriprema_clicked()
{
    PripremaTransporta *priprema = new PripremaTransporta(this);
    priprema->show();
}

void MainWindow::on_btnSmanjenje_clicked()
{
    SmanjenjeZahtevaA6 *sz = new SmanjenjeZahtevaA6(this);
    sz->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    kreiranjenalogae1 *kn = new kreiranjenalogae1();
    kn->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    deaktivacijanalogae2 *dn = new deaktivacijanalogae2();
    dn->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    SlanjeNarudzbeniceB1 *sn = new SlanjeNarudzbeniceB1(this);
    sn->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    PrijemSredstavaB2 *ps = new PrijemSredstavaB2(this);
    ps->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    DodajArtikal *da = new DodajArtikal();
    da->show();
}
