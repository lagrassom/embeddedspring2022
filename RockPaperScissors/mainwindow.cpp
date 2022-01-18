#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_choiceRock_clicked()
{
    ui->playerChoice->setText("You Chose Rock");
}

void MainWindow::on_choicePaper_clicked()
{
    ui->playerChoice->setText("You Chose Paper");
}

void MainWindow::on_choiceScissors_clicked()
{
    ui->playerChoice->setText("You Chose Scissors");
}
