#ifndef REGISTERTEACHINGMANAGER_H
#define REGISTERTEACHINGMANAGER_H

#include <QDialog>

namespace Ui {
class registerteachingmanager;
}

class registerteachingmanager : public QDialog
{
    Q_OBJECT

public:
    explicit registerteachingmanager(QWidget *parent = 0);
    ~registerteachingmanager();

private slots:
    void on_pushButton_clicked();

private:
    Ui::registerteachingmanager *ui;
};

#endif // REGISTERTEACHINGMANAGER_H
