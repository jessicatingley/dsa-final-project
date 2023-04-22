#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include "qlistwidget.h"
#include "qspinbox.h"
#include <QDialog>
#include <QDebug>
#include <vector>
#include <string>

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();

    QListWidget *quicksortList;
    QPushButton* exitButton;


    //Public Quick Sort Method
    void swap(int arr[] , int pos1, int pos2);
    void printArray();
    void insertArray(int n);


private slots:
    void on_pushButton_clicked();


    void on_exitButton_2_clicked();

private:
    Ui::secondwindow *ui;

    QSpinBox *spinBox;
    std::vector<std::string> arrayHolder;
    void quick_sort_algorithm(std::vector<int>& num_list, int start_position, int end_position);
    int list_partition(std::vector<int>& num_list, int start_position, int end_position);

    //QuickSort Functions
    int arrayPartition(int array[], int start, int end);
    void quicksortAlgorithm(int array[], int start, int end);


};
#endif // SECONDWINDOW_H
