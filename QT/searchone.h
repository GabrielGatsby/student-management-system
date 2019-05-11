#ifndef SEARCHONE_H
#define SEARCHONE_H

#include <QWidget>

namespace Ui {
class searchone;
}

class searchone : public QWidget
{
    Q_OBJECT

public:
    explicit searchone(QWidget *parent = 0);
    ~searchone();

private slots:
    void on_pushButton_clicked();

private:
    Ui::searchone *ui;
};

#endif // SEARCHONE_H
