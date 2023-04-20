#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QDialog>

namespace Ui {
class thirdwindow;
}

class thirdwindow : public QDialog
{
    Q_OBJECT

public:
    explicit thirdwindow(QWidget *parent = nullptr);
    ~thirdwindow();

private slots:
    void on_pushButton_clicked();

    void on_exitButton_3_clicked();

private:
    Ui::thirdwindow *ui;

    void insertion_sort(std::vector<int>& items);

};

#endif // THIRDWINDOW_H
