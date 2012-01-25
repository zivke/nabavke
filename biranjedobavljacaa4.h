#ifndef BIRANJEDOBAVLJACAA4_H
#define BIRANJEDOBAVLJACAA4_H
#include <QSqlQueryModel>
#include <QDialog>
#include <QItemSelection>
#include <QModelIndex>
#include <QItemSelectionModel>

namespace Ui {
    class BiranjeDobavljacaA4;
}

class BiranjeDobavljacaA4 : public QDialog
{
    Q_OBJECT

public:
    explicit BiranjeDobavljacaA4(QWidget *parent = 0);
    ~BiranjeDobavljacaA4();
private slots:
    void setModelStavke();
    void setModelDobavljaci();
    void updateSelection(const QItemSelection &selected,
                         const QItemSelection &deselected);
    void changeCurrent(const QModelIndex &current, const QModelIndex &previous);
    void on_btnSacuvajIzadji_clicked();

    void on_btnOdobri_clicked();

private:
    Ui::BiranjeDobavljacaA4 *ui;
    QSqlQueryModel *modelDobavljaci, *modelStavke;
    QItemSelectionModel *selectionModel;
    int _idArtika;
    QList<int> zaKompletiranje;
};

#endif // BIRANJEDOBAVLJACAA4_H
