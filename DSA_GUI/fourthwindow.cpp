#include "fourthwindow.h"
#include "mscode.h"
#include "ui_fourthwindow.h"

fourthwindow::fourthwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fourthwindow)
{
    ui->setupUi(this);
    setFixedSize(679,491); // Set the size to 400x300 pixels
}

fourthwindow::~fourthwindow()
{
    delete ui;
}

void fourthwindow::on_pushButton_clicked()
{
    int n = ui -> spinBox -> value();
    ui ->listWidget->clear();
    if (n == 4)
    {
        ui -> listWidget -> addItem("Given array: 29, 10, 14, 37");
        ui -> listWidget -> addItem("Split into partions of size 1.");
        ui -> listWidget -> addItem("Merge partition {29} and partition {10}.");
        ui -> listWidget -> addItem("Merged partition: 10, 29");
        ui -> listWidget -> addItem("Merge partition {14} and partition {37}.");
        ui -> listWidget -> addItem("Merged partition: 14, 37");
        ui -> listWidget -> addItem("Merge partition {10, 29} and partition {14, 37}.");
        ui -> listWidget -> addItem("Merged partition: 10, 14, 29, 37");
        ui -> listWidget -> addItem("Sorted array: 10, 14, 29, 37");
        ui -> listWidget -> addItem("");
        ui -> listWidget -> addItem("Total Comparison: 5");
    }
    if (n == 5)
    {
        ui -> listWidget -> addItem("Given array: 21, 45, 46, 27, 17");
        ui -> listWidget -> addItem("Split into partitions of size 1.");
        ui -> listWidget -> addItem("Merge partition {21} and partition {45}.");
        ui -> listWidget -> addItem("Merged partition: 21, 45");
        ui -> listWidget -> addItem("Merge partition {21, 45} and {46}.");
        ui -> listWidget -> addItem("Merge partition {27} and partition {17}.");
        ui -> listWidget -> addItem("Merged partition: 17, 27");
        ui -> listWidget -> addItem("Merge partition {21, 45 ,46} and partition {17, 27}.");
        ui -> listWidget -> addItem("Merged partition: 17, 21, 27, 45, 46");
        ui -> listWidget -> addItem("Sorted array: 17, 21, 27, 45, 46");
        ui -> listWidget -> addItem("");
        ui -> listWidget -> addItem("Total Comparison: 8");
    }
    if (n == 6)
    {
        ui -> listWidget -> addItem("Given array: 10, 14, 2, 31, 50, 28");
        ui -> listWidget -> addItem("Split into partitions of size 1.");
        ui -> listWidget -> addItem("Merge partition {10} and partition {14}.");
        ui -> listWidget -> addItem("Merged partition: 10, 14");
        ui -> listWidget -> addItem("Merge partition {10, 14} and partition {2}.");
        ui -> listWidget -> addItem("Merged partition: 2, 10, 14");
        ui -> listWidget -> addItem("Merge partition {31} and partition {50}.");
        ui -> listWidget -> addItem("Merged partition: 31, 50");
        ui -> listWidget -> addItem("Merge partition {31, 50} and partition {28}.");
        ui -> listWidget -> addItem("Merged partition: 28, 31, 50");
        ui -> listWidget -> addItem("Merge partition {2, 10, 14} and partition {28, 31, 50}.");
        ui -> listWidget -> addItem("Merged partition: 2, 10, 14, 28, 31, 50");
        ui -> listWidget -> addItem("Sorted array: 2, 10, 14, 28, 31, 50");
        ui -> listWidget -> addItem("");
        ui -> listWidget -> addItem("Total Comparison: 11");
    }

}


void fourthwindow::on_exitButton_2_clicked()
{
    mscode t;
    t.setModal(true);
    t.exec();
}

