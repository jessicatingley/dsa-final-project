#ifndef IS_CODE_H
#define IS_CODE_H

#include <QDialog>

namespace Ui {
class is_code;
}

class is_code : public QDialog
{
    Q_OBJECT

public:
    explicit is_code(QWidget *parent = nullptr);
    ~is_code();

private:
    Ui::is_code *ui;
};

#endif // IS_CODE_H
