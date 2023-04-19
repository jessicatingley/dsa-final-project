
#include "mainwindow.h"
#include "fourthwindow.h"
#include "secondwindow.h"
#include "thirdwindow.h"
#include "ui_mainwindow.h"
#include <iomanip>
#include <stdlib.h>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->quick_sort_button, SIGNAL(click()), this, SLOT(secondwindow()));

    setFixedSize(500, 300); // Set the size to 400x300 pixels
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_quick_sort_button_clicked()
{
    secondwindow *newWindow = new secondwindow(this);
    newWindow->show();
}



void MainWindow::on_insertion_sort_button_clicked()
{
    thirdwindow t;
    t.setModal(true);
    t.exec();
}


void MainWindow::on_merge_sort_button_clicked()
{
    fourthwindow t;
    t.setModal(true);
    t.exec();
}

