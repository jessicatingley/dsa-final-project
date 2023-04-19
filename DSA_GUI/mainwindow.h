
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qspinbox.h"
#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_quick_sort_button_clicked();

    void on_insertion_sort_button_clicked();

    void on_merge_sort_button_clicked();

private:
    Ui::MainWindow *ui;
    QSpinBox *boxNumber;


};

#endif // MAINWINDOW_H
