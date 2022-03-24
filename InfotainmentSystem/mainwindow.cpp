#include "mainwindow.h"
#include "ui_mainwindow.h"

static bool headlight = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (headlight) {
        ui->headlightButton->setStyleSheet("color: green");
    }
    else {
        ui->headlightButton->setStyleSheet("color: red");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_aboutButton_clicked()
{
    //Hide this window.
    hide();
    //Show the about window
    about = new About(this);
    about->show();
}

void MainWindow::on_brightnessButton_clicked()
{
    //Hide this window.
    hide();
    //Show the about window
    brightnessControl = new BrightnessControl(this);
    brightnessControl->show();
}

void MainWindow::on_interiorButton_clicked()
{
    //Hide this window.
    hide();
    //Show the about window
    interiorLights = new InteriorLights(this);
    interiorLights->show();
}

void MainWindow::on_headlightButton_clicked()
{
    headlight = !headlight;

    if (headlight) {
        ui->headlightButton->setStyleSheet("color: green");
    }
    else {
        ui->headlightButton->setStyleSheet("color: red");
    }
}
