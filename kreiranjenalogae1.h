#ifndef KREIRANJENALOGAE1_H
#define KREIRANJENALOGAE1_H

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlQueryModel>

namespace Ui {
    class kreiranjenalogae1;
}

class kreiranjenalogae1 : public QWidget
{
    Q_OBJECT

public:
    explicit kreiranjenalogae1(QWidget *parent = 0);
    ~kreiranjenalogae1();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::kreiranjenalogae1 *ui;
    void setModelOgranakComboBox();
    QSqlTableModel *modelCombo;
};

#endif // KREIRANJENALOGAE1_H


