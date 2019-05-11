#ifndef SEARCHALL_H
#define SEARCHALL_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class searchall;
}

class searchall : public QWidget
{
    Q_OBJECT

public:
    explicit searchall(QWidget *parent = 0);
    static QStandardItemModel *tableModel;
    ~searchall();



private slots:
    void on_pushButton_clicked();

private:
    Ui::searchall *ui;

};

#endif // SEARCHALL_H
