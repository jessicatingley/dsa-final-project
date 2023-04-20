#include "thirdwindow.h"
#include "is_code.h"
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

void thirdwindow::insertion_sort(std::vector<int>& items){
    const int size = items.size();


    for(auto curr_idx = 1; curr_idx < size; curr_idx++){

        ui -> listWidget -> addItem("-------------------------------------------");
        auto compare_idx = curr_idx - 1;


        const auto curr_val = items[curr_idx];

        QString comparing = "Comparing " + QString::number(items[compare_idx]) + " to " +  QString::number(curr_val);
        ui -> listWidget -> addItem(comparing);
        while(compare_idx >= 0 && items[compare_idx] > curr_val){

            QString swapping = "Swapping " + QString::number(items[compare_idx + 1]) + " and " + QString::number(items[compare_idx]);
            ui -> listWidget -> addItem(swapping);
            items[compare_idx + 1] = items[compare_idx];
            compare_idx -= 1;
        }
        items[compare_idx + 1] = curr_val;

        QString newVector = "New vector: ";
        for(auto i : items){
            newVector += QString::number(i) + " ";
        }
    }
}

void thirdwindow::on_pushButton_clicked()
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


        insertion_sort(vect);

        QString resultVector = "Result Array: ";
        for (int i = 0; i < n; i++)
            resultVector += QString::number(vect[i]) + " ";
        ui -> listWidget -> addItem("-------------------------------------------");
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


        insertion_sort(vect);

        QString resultVector = "Result Array: ";
        for (int i = 0; i < n; i++)
            resultVector += QString::number(vect[i]) + " ";
        ui -> listWidget -> addItem("-------------------------------------------");
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


        insertion_sort(vect);

        QString resultVector = "Result Array: ";
        for (int i = 0; i < n; i++)
            resultVector += QString::number(vect[i]) + " ";
        ui -> listWidget -> addItem("-------------------------------------------");
        ui -> listWidget -> addItem(resultVector);
    }
}


void thirdwindow::on_exitButton_3_clicked()
{
    is_code t;
    t.setModal(true);
    t.exec();
}

