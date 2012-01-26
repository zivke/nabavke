#ifndef SMANJENJEZAHTEVAA6_H
#define SMANJENJEZAHTEVAA6_H

#include <QDialog>

namespace Ui {
    class SmanjenjeZahtevaA6;
}

class SmanjenjeZahtevaA6 : public QDialog
{
    Q_OBJECT

public:
    explicit SmanjenjeZahtevaA6(QWidget *parent = 0);
    ~SmanjenjeZahtevaA6();

private:
    Ui::SmanjenjeZahtevaA6 *ui;
};

#endif // SMANJENJEZAHTEVAA6_H
