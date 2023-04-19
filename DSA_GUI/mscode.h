#ifndef MSCODE_H
#define MSCODE_H

#include <QDialog>

namespace Ui {
class mscode;
}

class mscode : public QDialog
{
    Q_OBJECT

public:
    explicit mscode(QWidget *parent = nullptr);
    ~mscode();

private:
    Ui::mscode *ui;
};

#endif // MSCODE_H
