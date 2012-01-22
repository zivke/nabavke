#ifndef SLANJEZAHTEVAA3_H
#define SLANJEZAHTEVAA3_H

#include <QDialog>
#include <QSqlQueryModel>
namespace Ui {
    class SlanjeZahtevaA3;
}

class SlanjeZahtevaA3 : public QDialog
{
    Q_OBJECT

public:
    explicit SlanjeZahtevaA3(QWidget *parent = 0);
    ~SlanjeZahtevaA3();

private slots:
    void on_btnIzadji_clicked();
    void setModelStavke();
    void setModelDobavljaci();
    void printHtml(const QString &html);
    void on_btnStampa_clicked();

    void on_btnEmail_clicked();

private:
    Ui::SlanjeZahtevaA3 *ui;
    QSqlQueryModel *modelDobavljaci;
    QSqlQueryModel *modelStavke;
};

#endif // SLANJEZAHTEVAA3_H
