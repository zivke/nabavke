#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
    class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
signals:
    void ucitanKorisnik(QString, int);
private slots:
    void on_btnLogin_clicked();
    void closeEvent(QCloseEvent *event);
private:
    Ui::Login *ui;
    bool _login;
    QWidget *_parent;
};

#endif // LOGIN_H
