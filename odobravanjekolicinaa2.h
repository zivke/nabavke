#ifndef ODOBRAVANJEKOLICINAA2_H
#define ODOBRAVANJEKOLICINAA2_H

#include <QDialog>
#include <QSqlQueryModel>
namespace Ui {
    class OdobravanjeKolicinaA2;
}

class OdobravanjeKolicinaA2 : public QDialog
{
    Q_OBJECT

public:
    explicit OdobravanjeKolicinaA2(QWidget *parent = 0);
    ~OdobravanjeKolicinaA2();


private:
    Ui::OdobravanjeKolicinaA2 *ui;
    void setModelArtikli();
    QSqlQueryModel *model;
};

#endif // ODOBRAVANJEKOLICINAA2_H
