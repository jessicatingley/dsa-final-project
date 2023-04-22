#ifndef QSCODE_H
#define QSCODE_H

#include <QDialog>

namespace Ui {
class QScode;
}

class QScode : public QDialog
{
    Q_OBJECT

public:
    explicit QScode(QWidget *parent = nullptr);
    ~QScode();

private:
    Ui::QScode *ui;
};

#endif // QSCODE_H
