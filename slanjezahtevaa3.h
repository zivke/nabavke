#ifndef SLANJEZAHTEVAA3_H
#define SLANJEZAHTEVAA3_H

#include <QDialog>

namespace Ui {
    class SlanjeZahtevaA3;
}

class SlanjeZahtevaA3 : public QDialog
{
    Q_OBJECT

public:
    explicit SlanjeZahtevaA3(QWidget *parent = 0);
    ~SlanjeZahtevaA3();

private:
    Ui::SlanjeZahtevaA3 *ui;
};

#endif // SLANJEZAHTEVAA3_H
