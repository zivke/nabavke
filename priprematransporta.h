#ifndef PRIPREMATRANSPORTA_H
#define PRIPREMATRANSPORTA_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QItemSelection>
#include <QItemSelectionModel>
#include <QList>

namespace Ui {
class PripremaTransporta;
}

class PripremaTransporta : public QDialog
{
    Q_OBJECT
    
public:
    explicit PripremaTransporta(QWidget *parent = 0);
    ~PripremaTransporta();
    
public slots:
    void updateSelection(const QItemSelection &selected,
                         const QItemSelection &deselected);


private slots:
    void on_btnpriprema_clicked();

    void on_pushButton_clicked();

private:
    Ui::PripremaTransporta *ui;
    void setModelStavke();
    QSqlQueryModel *modelStavke;
    QItemSelectionModel *selectionModel;
    int _odabranaStavkaId;
    QList<int> pripremaTransport;

};

#endif // PRIPREMATRANSPORTA_H
