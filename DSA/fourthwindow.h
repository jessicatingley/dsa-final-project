#ifndef FOURTHWINDOW_H
#define FOURTHWINDOW_H

#include <QDialog>

namespace Ui {
class fourthwindow;
}

class fourthwindow : public QDialog
{
    Q_OBJECT

public:
    explicit fourthwindow(QWidget *parent = nullptr);
    ~fourthwindow();

private slots:
    void on_pushButton_clicked();

    void on_exitButton_2_clicked();

private:
    Ui::fourthwindow *ui;

    void merge(std::vector<int>& vec, int low, int mid, int high);
    void merge_sort(std::vector<int>& vec, int low, int high);
};

#endif // FOURTHWINDOW_H
