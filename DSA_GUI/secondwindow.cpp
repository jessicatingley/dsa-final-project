#include "secondwindow.h"
#include "qscode.h"
#include "ui_secondwindow.h"

#include <QListWidget>
#include <QStringListModel>
#include <iostream>
#include <string>
#include <QString>


secondwindow::secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    //ui -> quicksortList -> addItem("Hello1");
    setFixedSize(679,491); // Set the size to 400x300 pixels

    //connect(exitButton, &QPushButton::clicked, this);

}

int secondwindow::list_partition(std::vector<int>& num_list, int start_position, int end_position)
{
    //index moving during every for loop iteration
    int pivoting_index = start_position;

    //Current pivot value at every quick_sort_algorithm recursive call
    int current_pivot_value = num_list[end_position];

    ui -> listWidget -> addItem("-------------------------------------------");
    QString pi = "Current Pivoting Index: " + QString::number(int(pivoting_index));
    ui -> listWidget -> addItem(pi);

    QString output2 = "Current Pivot Value: " + QString::number(int(current_pivot_value)) + " at position " + QString::number(end_position);
    ui -> listWidget -> addItem(output2);

    //Iterating through num_list from passed start to end position
    for (int i = start_position; i < end_position; i++)
    {

        //If the current element is less than the current pivot
        if (num_list[i] < current_pivot_value)
        {
            //swap values
            QString output3 = "-- Swapping Indexes: " + QString::number(i) + " && " + QString::number(pivoting_index) + "--";
            ui -> listWidget -> addItem(output3);

            QString beforeSwap = "Before Swap: ";


            for (int i = 0; i < int(num_list.size()); i++)
                beforeSwap += QString::number(num_list[i]) + " ";
            ui -> listWidget -> addItem(beforeSwap);

            std::swap(num_list[i], num_list[pivoting_index]);

            QString afterSwap = "After Swap: ";


            for (int i = 0; i < int(num_list.size()); i++)
                beforeSwap += QString::number(num_list[i]) + " ";
            ui -> listWidget -> addItem(afterSwap);

            //increment to the next index after swapping
            pivoting_index++;
        }
    }

    //Once iterative swapping is completed, swap the pivot and the
    //incrementing pivot index to finsh the sub-array sort
    std::swap(num_list[pivoting_index], num_list[end_position]);



    QString afterPivotSwap = "After Pivot Swap !" + QString::number(num_list[end_position]) +"!: ";
    ui -> listWidget -> addItem(afterPivotSwap);


    QString swappedIndexes = "-- Swapped Indexes: " + QString::number(pivoting_index) + " && " + QString::number(end_position) + " --";
    ui -> listWidget -> addItem(swappedIndexes);
    //Returning the pivoting index begin the next portion of sorting
    return pivoting_index;
}

void secondwindow::quick_sort_algorithm(std::vector<int>& num_list, int start_position, int end_position)
{
    //Check if num_list is sorted
    //if the two positions cross or equal, stop sorting
    if (start_position >= end_position)
        return;

    int index = list_partition(num_list, start_position, end_position);

    //Left partition of list
    quick_sort_algorithm(num_list, start_position, index - 1);

    //Right partition of list
    quick_sort_algorithm(num_list, index + 1, end_position);
}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::on_pushButton_clicked()
{
    int n = ui -> spinBox -> value();
    ui ->listWidget->clear();
    if (n == 4)
    {
        std::vector<int> vect;

        srand(time(NULL));
        for (int i = 0; i < n; i++)
            vect.push_back(rand() % 100 + 1);

        QString originalVector = "Current Array: ";
        for (int i = 0; i < n; i++)
            originalVector += QString::number(vect[i]) + " ";

        ui -> listWidget -> addItem(originalVector);


        quick_sort_algorithm(vect, 0, vect.size() - 1);

        QString resultVector = "Result Array: ";
        for (int i = 0; i < n; i++)
            resultVector += QString::number(vect[i]) + " ";

        ui -> listWidget -> addItem(resultVector);

    }
    if (n == 5)
    {
        std::vector<int> vect;

        srand(time(NULL));
        for (int i = 0; i < n; i++)
            vect.push_back(rand() % 100 + 1);

        QString originalVector = "Current Array: ";
        for (int i = 0; i < n; i++)
            originalVector += QString::number(vect[i]) + " ";

        ui -> listWidget -> addItem(originalVector);


        quick_sort_algorithm(vect, 0, vect.size() - 1);

        QString resultVector = "Result Array: ";
        for (int i = 0; i < n; i++)
            resultVector += QString::number(vect[i]) + " ";

        ui -> listWidget -> addItem(resultVector);
    }
    if (n == 6)
    {
        std::vector<int> vect;

        srand(time(NULL));
        for (int i = 0; i < n; i++)
            vect.push_back(rand() % 100 + 1);

        QString originalVector = "Current Array: ";
        for (int i = 0; i < n; i++)
            originalVector += QString::number(vect[i]) + " ";

        ui -> listWidget -> addItem(originalVector);


        quick_sort_algorithm(vect, 0, vect.size() - 1);

        QString resultVector = "Result Array: ";
        for (int i = 0; i < n; i++)
            resultVector += QString::number(vect[i]) + " ";

        ui -> listWidget -> addItem(resultVector);

    }

}



void secondwindow::on_exitButton_2_clicked()
{
    QScode t;
    t.setModal(true);
    t.exec();
}

