#include "mscode.h"
#include "ui_mscode.h"

mscode::mscode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mscode)
{
    ui->setupUi(this);
}

mscode::~mscode()
{
    delete ui;
}
