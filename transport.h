#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <QDialog>
#include <QSqlQueryModel>
#include <QItemSelection>
#include <QItemSelectionModel>
#include <QList>

namespace Ui {
class Transport;
}

class Transport : public QDialog
{
    Q_OBJECT
    
public:
    explicit Transport(QWidget *parent = 0);
    ~Transport();
    

public slots:
    void updateSelection(const QItemSelection &selected,
                         const QItemSelection &deselected);

private slots:
    void on_bttransport_clicked();

    void on_pushButton_clicked();

private:
    Ui::Transport *ui;
    void setModelStavke();
    QSqlQueryModel *modelStavke;
    QItemSelectionModel *selectionModel;
    int _odabranaStavkaId;
    QList<int> zaTransport;




};

#endif // TRANSPORT_H
