#ifndef SPISAKZAHTEVAA1_H
#define SPISAKZAHTEVAA1_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlQueryModel>

namespace Ui {
    class spisakZahtevaA1;
}

class spisakZahtevaA1 : public QDialog
{
    Q_OBJECT

public:
    explicit spisakZahtevaA1(QWidget *parent = 0, int userId = 0);
    ~spisakZahtevaA1();
signals:
    void dodataStavka();
private slots:
    void on_btnDodaj_clicked();

    void on_bntSaveExit_clicked();

    void on_btnOdustani_clicked();

private:
    Ui::spisakZahtevaA1 *ui;
    void setModelArtikliCombo();
    void setModelArtikliTable();
    QSqlTableModel *modelCombo;
    QSqlQueryModel *modelTable;
    int _userId;
    int _lastId;
};

#endif // SPISAKZAHTEVAA1_H
