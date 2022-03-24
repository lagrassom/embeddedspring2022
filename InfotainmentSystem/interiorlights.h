#ifndef INTERIORLIGHTS_H
#define INTERIORLIGHTS_H

#include <QDialog>
#include "wiringPi.h"

namespace Ui {
class InteriorLights;
}

class InteriorLights : public QDialog
{
    Q_OBJECT

public:
    explicit InteriorLights(QWidget *parent = nullptr);
    ~InteriorLights();

private slots:
    void on_backButton_clicked();

    void on_frontBox_stateChanged(int arg1);

    void on_resetButton_clicked();

private:
    Ui::InteriorLights *ui;
};

#endif // INTERIORLIGHTS_H
