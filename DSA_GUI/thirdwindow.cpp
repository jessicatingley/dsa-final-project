#include "thirdwindow.h"
#include "ui_thirdwindow.h"

thirdwindow::thirdwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thirdwindow)
{
    ui->setupUi(this);
    setFixedSize(679,491); // Set the size to 400x300 pixels
}

thirdwindow::~thirdwindow()
{
    delete ui;
}

void thirdwindow::on_pushButton_clicked()
{
    int n = ui -> spinBox -> value();
    ui ->listWidget->clear();
    if (n == 4)
    {
        ui -> listWidget -> addItem("Given Array: 1, 2, 3, 4");
    }
    if (n == 5)
    {
        ui -> listWidget -> addItem("Given Array: 1, 2, 3, 4, 5");
    }
    if (n == 6)
    {
        ui -> listWidget -> addItem("Given Array: 1, 2, 3, 4, 5, 6");
    }
}

