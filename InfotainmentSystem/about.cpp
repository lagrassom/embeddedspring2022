#include "about.h"
#include "ui_about.h"
#include "mainwindow.h"

static MainWindow *mainWindow;

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
}

About::~About()
{
    delete ui;
}

void About::on_backButton_clicked()
{
    //Hide this window
    hide();
    //Show main window
    mainWindow = new MainWindow(this);
    mainWindow->show();
}
