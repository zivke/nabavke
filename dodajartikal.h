#ifndef DODAJARTIKAL_H
#define DODAJARTIKAL_H

#include <QDialog>

namespace Ui {
    class DodajArtikal;
}

class DodajArtikal : public QDialog
{
    Q_OBJECT

public:
    explicit DodajArtikal(QWidget *parent = 0);
    ~DodajArtikal();

private:
    Ui::DodajArtikal *ui;
};

#endif // DODAJARTIKAL_H
