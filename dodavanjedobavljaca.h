#ifndef DODAVANJEDOBAVLJACA_H
#define DODAVANJEDOBAVLJACA_H

#include <QMainWindow>

namespace Ui {
    class dodavanjedobavljaca;
}

class dodavanjedobavljaca : public QMainWindow
{
    Q_OBJECT

public:
    explicit dodavanjedobavljaca(QWidget *parent = 0);
    ~dodavanjedobavljaca();

private:
    Ui::dodavanjedobavljaca *ui;
};

#endif // DODAVANJEDOBAVLJACA_H
