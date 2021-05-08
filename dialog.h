#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include "simple_funcs.h"
char *convert(QString s);
int is_op(char c);
int validation(char *str);

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    void setT(QString s);
    void set_string();
    explicit Dialog(QWidget *parent = nullptr);
    void convert_answers_to_text(char *pdnf, char *pcnf, QString s);
    ~Dialog();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
