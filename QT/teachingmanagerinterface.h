#ifndef TEACHINGMANAGERINTERFACE_H
#define TEACHINGMANAGERINTERFACE_H

#include <QDialog>

namespace Ui {
class TeachingManagerInterface;
}

class TeachingManagerInterface : public QDialog
{
    Q_OBJECT

public:
    explicit TeachingManagerInterface(QWidget *parent = 0);
    ~TeachingManagerInterface();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::TeachingManagerInterface *ui;
};

#endif // TEACHINGMANAGERINTERFACE_H
