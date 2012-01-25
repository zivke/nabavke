#ifndef RASPODELI_H
#define RASPODELI_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QItemSelection>
#include <QItemSelectionModel>
#include <QList>

namespace Ui {
class Raspodeli;
}

class Raspodeli : public QDialog
{
    Q_OBJECT
    
public:
    explicit Raspodeli(QWidget *parent = 0);
    ~Raspodeli();

public slots:
    void updateSelection(const QItemSelection &selected,
                         const QItemSelection &deselected);
    void changeCurrent(const QModelIndex &current, const QModelIndex &previous);
    void zaposleniPromenjen(int index);
    
private slots:
    void on_pushButton_clicked();

    void on_zapamti_clicked();



private:
    Ui::Raspodeli *ui;
    void setModelZaposleni();
        void setModelStavke(int idZaposlenog);
        QSqlQueryModel *modelZaposleni;
        QSqlQueryModel *modelStavke;
        QItemSelectionModel *selectionModel;
        int _odabraniUser;
        int _odabranaStavkaId;
        QList<int> zaRaspodelu;
};

#endif // RASPODELI_H
