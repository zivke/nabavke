#ifndef DEAKTIVACIJANALOGAE2_H
#define DEAKTIVACIJANALOGAE2_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QItemSelection>
#include <QItemSelectionModel>

namespace Ui {
    class deaktivacijanalogae2;
}

class deaktivacijanalogae2 : public QWidget
{
    Q_OBJECT

public:
    explicit deaktivacijanalogae2(QWidget *parent = 0);
    ~deaktivacijanalogae2();

private slots:
    void on_pushButton_2_clicked();
    void deleteSelection(const QItemSelection &selected,
                             const QItemSelection &deselected);

    void on_pushButton_clicked();

private:
    Ui::deaktivacijanalogae2 *ui;
      void setModelKorisnici();
      QSqlQueryModel *modelKorisnici;
      QItemSelectionModel *selectionModel;
      int _odabraniUser;

};

#endif // DEAKTIVACIJANALOGAE2_H
