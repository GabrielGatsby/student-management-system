#ifndef Register_H
#define Register_H

#include <QDialog>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private:
    Ui::Register *ui;
};

#endif // Register_H
