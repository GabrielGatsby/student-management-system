#ifndef STUDENTFUNCTION_H
#define STUDENTFUNCTION_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class studentFunction;
}

class studentFunction : public QWidget
{
    Q_OBJECT

public:
    explicit studentFunction(QWidget *parent = 0);
    static QStandardItemModel *tableModel;
    ~studentFunction();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();


    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::studentFunction *ui;
};

#endif // STUDENTFUNCTION_H
