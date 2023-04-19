#include "qscode.h"
#include "ui_qscode.h"

QScode::QScode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QScode)
{
    ui->setupUi(this);
}

QScode::~QScode()
{
    delete ui;
}
