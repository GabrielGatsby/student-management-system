#ifndef TEACHERINTERFACE_H
#define TEACHERINTERFACE_H

#include <QDialog>

namespace Ui {
class TeacherInterface;
}

class TeacherInterface : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherInterface(QWidget *parent = 0);
    ~TeacherInterface();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::TeacherInterface *ui;
};

#endif // TEACHERINTERFACE_H
