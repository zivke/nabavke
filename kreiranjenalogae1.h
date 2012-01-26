#ifndef KREIRANJENALOGAE1_H
#define KREIRANJENALOGAE1_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QSqlError>
#include <QTextEdit>

namespace Ui {
    class kreiranjenalogae1;
}

class kreiranjenalogae1 : public QWidget
{
    Q_OBJECT

public:
    explicit kreiranjenalogae1(QWidget *parent = 0);
    ~kreiranjenalogae1();

private slots:
    void on_btnOdustani_clicked();


    void on_btnSacuvajIzadji_clicked();

private:
    Ui::kreiranjenalogae1 *ui;
    void setModelOgranakComboBox();
    QSqlQueryModel *modelOgranak;
};

#endif // KREIRANJENALOGAE1_H


