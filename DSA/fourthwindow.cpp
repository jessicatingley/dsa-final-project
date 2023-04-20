#include "fourthwindow.h"
#include "mscode.h"
#include "ui_fourthwindow.h"

#include <QString>

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

void fourthwindow::merge_sort(std::vector<int>& vec, int low, int high){
    if(high <= low){
        return;
    }

    int mid = low + (high - low) / 2;

    merge_sort(vec, low, mid);
    merge_sort(vec, mid + 1, high);
    merge(vec, low, mid, high);

}


void fourthwindow::merge(std::vector<int>& vec, int low, int mid, int high){

    //create temp vector
    std::vector<int> temp(high - low + 1);
    int i = low, j = mid + 1, k = 0;

    ui -> listWidget -> addItem("-------------------------------------------");

    QString leftSubArray = "Left sub-array: ";

    //left sub-array
    for(int x = low; x <= mid; x++){
        leftSubArray += QString::number(vec[x]) + " ";
    }
    ui -> listWidget -> addItem(leftSubArray);

    //right sub-array
    QString rightSubArray = "Right sub-array: ";
    for(int x = mid+1; x <= high; x++){
        rightSubArray += QString::number(vec[x]) + " ";
    }
    ui -> listWidget -> addItem(rightSubArray);

    while (i <= mid && j <= high) {
        if (vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        }
        else {
            temp[k++] = vec[j++];
        }
    }

    //copy left over elements from left and right side
    while (i <= mid) {
        temp[k++] = vec[i++];
    }

    while (j <= high) {
        temp[k++] = vec[j++];
    }

    //merged array

    QString mergedArray = "Merged array: ";
    //std::cout << "Merged array: ";
    for(int x = 0; x < int(temp.size()); x++){
        mergedArray += QString::number(temp[x]) + " ";
    }
    ui -> listWidget -> addItem(mergedArray);

    //copy data back into vec
    std::memcpy(&vec[low], &temp[0], temp.size() * sizeof(int));
}

void fourthwindow::on_pushButton_clicked()
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

        merge_sort(vect, 0, vect.size() - 1);

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

        merge_sort(vect, 0, vect.size() - 1);

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

        merge_sort(vect, 0, vect.size() - 1);

        QString resultVector = "Result Array: ";
        for (int i = 0; i < n; i++)
            resultVector += QString::number(vect[i]) + " ";

        ui -> listWidget -> addItem("-------------------------------------------");

        ui -> listWidget -> addItem(resultVector);
    }

}


void fourthwindow::on_exitButton_2_clicked()
{
    mscode t;
    t.setModal(true);
    t.exec();
}

