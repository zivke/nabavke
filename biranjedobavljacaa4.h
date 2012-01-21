#ifndef BIRANJEDOBAVLJACAA4_H
#define BIRANJEDOBAVLJACAA4_H

#include <QDialog>

namespace Ui {
    class BiranjeDobavljacaA4;
}

class BiranjeDobavljacaA4 : public QDialog
{
    Q_OBJECT

public:
    explicit BiranjeDobavljacaA4(QWidget *parent = 0);
    ~BiranjeDobavljacaA4();

private:
    Ui::BiranjeDobavljacaA4 *ui;
};

#endif // BIRANJEDOBAVLJACAA4_H
