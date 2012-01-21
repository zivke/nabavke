#ifndef ODOBRAVANJEKOLICINAA2_H
#define ODOBRAVANJEKOLICINAA2_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QItemSelection>
#include <QItemSelectionModel>

namespace Ui {
    class OdobravanjeKolicinaA2;
}

class OdobravanjeKolicinaA2 : public QDialog
{
    Q_OBJECT

public:
    explicit OdobravanjeKolicinaA2(QWidget *parent = 0);
    ~OdobravanjeKolicinaA2();
public slots:
    void updateSelection(const QItemSelection &selected,
                         const QItemSelection &deselected);
    void changeCurrent(const QModelIndex &current, const QModelIndex &previous);
    void zaposleniPromenjen(int index);

private slots:

    void on_btnOdobri_clicked();

    void on_btnSaveExit_clicked();

private:
    Ui::OdobravanjeKolicinaA2 *ui;
    void setModelZaposleni();
    void setModelStavke(int idZaposlenog);
    QSqlQueryModel *modelZaposleni;
    QSqlQueryModel *modelStavke;
    QItemSelectionModel *selectionModel;
    int _odabraniUser;
    int _odabraniUserId;
};

#endif // ODOBRAVANJEKOLICINAA2_H
