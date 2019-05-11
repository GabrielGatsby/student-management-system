#ifndef REGISTERTEACHER_H
#define REGISTERTEACHER_H

#include <QDialog>

namespace Ui {
class registerteacher;
}

class registerteacher : public QDialog
{
    Q_OBJECT

public:
    explicit registerteacher(QWidget *parent = 0);
    ~registerteacher();

private slots:
    void on_pushButton_clicked();

private:
    Ui::registerteacher *ui;
};

#endif // REGISTERTEACHER_H
