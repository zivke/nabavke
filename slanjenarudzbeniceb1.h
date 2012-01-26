#ifndef SLANJENARUDZBENICEB1_H
#define SLANJENARUDZBENICEB1_H

#include <QDialog>

namespace Ui {
    class SlanjeNarudzbeniceB1;
}

class SlanjeNarudzbeniceB1 : public QDialog
{
    Q_OBJECT

public:
    explicit SlanjeNarudzbeniceB1(QWidget *parent = 0);
    ~SlanjeNarudzbeniceB1();

private slots:
    void on_btnIzadji_clicked();

private:
    Ui::SlanjeNarudzbeniceB1 *ui;
};

#endif // SLANJENARUDZBENICEB1_H
