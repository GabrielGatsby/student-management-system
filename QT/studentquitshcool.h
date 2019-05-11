#ifndef STUDENTQUITSHCOOL_H
#define STUDENTQUITSHCOOL_H

#include <QWidget>

namespace Ui {
class studentQuitShcool;
}

class studentQuitShcool : public QWidget
{
    Q_OBJECT

public:
    explicit studentQuitShcool(QWidget *parent = 0);
    ~studentQuitShcool();

private slots:
    void on_pushButton_clicked();

private:
    Ui::studentQuitShcool *ui;
};

#endif // STUDENTQUITSHCOOL_H
