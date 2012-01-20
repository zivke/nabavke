#ifndef SPISAKZAHTEVAA1_H
#define SPISAKZAHTEVAA1_H

#include <QDialog>
#include <QSqlTableModel>
namespace Ui {
    class spisakZahtevaA1;
}

class spisakZahtevaA1 : public QDialog
{
    Q_OBJECT

public:
    explicit spisakZahtevaA1(QWidget *parent = 0, int userId = 0);
    ~spisakZahtevaA1();

private:
    Ui::spisakZahtevaA1 *ui;
    void setModelArtikli();
    QSqlTableModel *model;
    int _userId;
    int _lastId;
};

#endif // SPISAKZAHTEVAA1_H
