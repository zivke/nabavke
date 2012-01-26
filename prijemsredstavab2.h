#ifndef PRIJEMSREDSTAVAB2_H
#define PRIJEMSREDSTAVAB2_H

#include <QDialog>

namespace Ui {
    class PrijemSredstavaB2;
}

class PrijemSredstavaB2 : public QDialog
{
    Q_OBJECT

public:
    explicit PrijemSredstavaB2(QWidget *parent = 0);
    ~PrijemSredstavaB2();

private slots:
    void on_zapamti_2_clicked();

private:
    Ui::PrijemSredstavaB2 *ui;
};

#endif // PRIJEMSREDSTAVAB2_H
