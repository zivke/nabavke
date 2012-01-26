#ifndef PRIPREMATRANSPORTA_H
#define PRIPREMATRANSPORTA_H

#include <QDialog>

namespace Ui {
class PripremaTransporta;
}

class PripremaTransporta : public QDialog
{
    Q_OBJECT
    
public:
    explicit PripremaTransporta(QWidget *parent = 0);
    ~PripremaTransporta();
    
private:
    Ui::PripremaTransporta *ui;
};

#endif // PRIPREMATRANSPORTA_H
