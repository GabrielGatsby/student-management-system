#ifndef REGISTERSTUDENT_H
#define REGISTERSTUDENT_H

#include <QDialog>

namespace Ui {
class registerstudent;
}

class registerstudent : public QDialog
{
    Q_OBJECT

public:
    explicit registerstudent(QWidget *parent = 0);
    ~registerstudent();



private slots:
    void on_pushButton_clicked();



private:
    Ui::registerstudent *ui;
};

#endif // REGISTERSTUDENT_H
