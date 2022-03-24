#include "interiorlights.h"
#include "ui_interiorlights.h"
#include "mainwindow.h"
#include "iostream"

static MainWindow *mainWindow;

InteriorLights::InteriorLights(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InteriorLights)
{
    ui->setupUi(this);
    wiringPiSetupGpio();
    pinMode(22, OUTPUT);
    pinMode(23, OUTPUT);
}

InteriorLights::~InteriorLights()
{
    delete ui;
}

void InteriorLights::on_backButton_clicked()
{
    //Hide this window
    hide();
    //Show main window
    mainWindow = new MainWindow(this);
    mainWindow->show();
}

void InteriorLights::on_frontBox_stateChanged(int arg1)
{
    if (arg1 == 0) {
        digitalWrite(22, LOW);
        digitalWrite(23, LOW);
    }
    else {
        digitalWrite(22, HIGH);
        digitalWrite(23, HIGH);
    }
}

void InteriorLights::on_resetButton_clicked()
{
    // uncheck the checkboxes
    ui->frontBox->setChecked(false);

    // turn off the light
}
