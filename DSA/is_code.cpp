#include "is_code.h"
#include "ui_is_code.h"

is_code::is_code(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::is_code)
{
    ui->setupUi(this);
    setFixedSize(514, 351);
}

is_code::~is_code()
{
    delete ui;
}
