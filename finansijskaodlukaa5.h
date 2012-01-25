#ifndef FINANSIJSKAODLUKAA5_H
#define FINANSIJSKAODLUKAA5_H

#include <QDialog>

namespace Ui {
    class FinansijskaOdlukaA5;
}

class FinansijskaOdlukaA5 : public QDialog
{
    Q_OBJECT

public:
    explicit FinansijskaOdlukaA5(QWidget *parent = 0);
    ~FinansijskaOdlukaA5();

private:
    Ui::FinansijskaOdlukaA5 *ui;
};

#endif // FINANSIJSKAODLUKAA5_H
