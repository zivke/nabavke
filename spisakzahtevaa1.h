#ifndef SPISAKZAHTEVAA1_H
#define SPISAKZAHTEVAA1_H

#include <QDialog>

namespace Ui {
    class spisakZahtevaA1;
}

class spisakZahtevaA1 : public QDialog
{
    Q_OBJECT

public:
    explicit spisakZahtevaA1(QWidget *parent = 0);
    ~spisakZahtevaA1();

private:
    Ui::spisakZahtevaA1 *ui;
};

#endif // SPISAKZAHTEVAA1_H
