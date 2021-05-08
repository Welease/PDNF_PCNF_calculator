#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class calculator; }
QT_END_NAMESPACE

class calculator : public QMainWindow
{
    Q_OBJECT

public:
    calculator(QWidget *parent = nullptr);
    ~calculator();
signals:
    void sendData(QString str);

private slots:
    void change_input();
    void on_Backspace_clicked();
    void on_Check_clicked();

private:
    Ui::calculator *ui;
};
#endif // CALCULATOR_H
