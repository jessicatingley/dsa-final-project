#include "mscode.h"
#include "ui_mscode.h"

mscode::mscode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mscode)
{
    ui->setupUi(this);
    setFixedSize(510,771);
}

mscode::~mscode()
{
    delete ui;
}
