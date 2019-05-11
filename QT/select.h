#ifndef SELECT_H
#define SELECT_H

#include <QWidget>

namespace Ui {
class select;
}

class select : public QWidget
{
    Q_OBJECT

public:
    explicit select(QWidget *parent = 0);
    ~select();

private slots:
    void on_pushButton_clicked();

private:
    Ui::select *ui;
};

#endif // SELECT_H
