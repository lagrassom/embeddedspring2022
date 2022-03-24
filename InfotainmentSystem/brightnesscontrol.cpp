#include "brightnesscontrol.h"
#include "ui_brightnesscontrol.h"
#include "mainwindow.h"
#include <softPwm.h>

static MainWindow *mainWindow;
static int brightnessValue = 0;
int pin = 22;

BrightnessControl::BrightnessControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrightnessControl)
{
    ui->setupUi(this);
    ui->brightnessBar->setValue(brightnessValue);
    ui->brightnessSlider->setValue(brightnessValue);
}

BrightnessControl::~BrightnessControl()
{
    delete ui;
}

void BrightnessControl::on_backButton_clicked()
{
    //Hide this window
    hide();
    //Show main window
    mainWindow = new MainWindow(this);
    mainWindow->show();
}

void BrightnessControl::on_brightnessSlider_valueChanged(int value)
{
    brightnessValue = value;
    ui->brightnessBar->setValue(brightnessValue);
}

void BrightnessControl::on_dimButton_clicked()
{
    softPwmCreate(pin, 0, 100);
    softPwmWrite(pin, 35);
}

void BrightnessControl::on_brightButton_clicked()
{
    softPwmCreate(pin, 0, 100);
    softPwmWrite(pin, 85);
}
