#include "dialog.h"
#include "ui_dialog.h"
#include "calculation.h"
#include <QDebug>
#include <iostream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

void Dialog::setT(QString s)
{
    ui->label->setText(s);
    set_string();
}

char *convert(QString s)
{
    char *res;
    res = new char[s.length() + 1];

    int i;
    int j;
    i = 0;
    j = 0;
    while (i < s.length())
    {
        if (s[i] == "∨")
            res[j++] = '+';
        else if (s[i] == "∧")
            res[j++] = '*';
        else if (s[i] == "¬")
            res[j++] = '!';
        else if (s[i] == "⊕")
            res[j++] = '~';
        else if (s[i] == "→")
            res[j++] = '-';
        else if (s[i] == "≡")
            res[j++] = '=';
        else if (s[i] == "↓")
            res[j++] = '/';
        else if (s[i] == "|")
            res[j++] = '|';
        else if (s[i] == "0")
            res[j++] = '0';
        else if (s[i] == "1")
            res[j++] = '1';
        else if (s[i] == "a")
            res[j++] = 'a';
        else if (s[i] == "b")
            res[j++] = 'b';
        else if (s[i] == "c")
            res[j++] = 'c';
        else if (s[i] == "x")
            res[j++] = 'x';
        else if (s[i] == "y")
            res[j++] = 'y';
        else if (s[i] == "z")
            res[j++] = 'z';
        else if (s[i] == "(")
            res[j++] = '(';
        else if (s[i] == ")")
            res[j++] = ')';
        else if (s[i] == "l")
            res[j++] = 'l';
        else if (s[i] == "m")
            res[j++] = 'm';
        else if (s[i] == "n")
            res[j++] = 'n';
        else if (s[i] == "p")
            res[j++] = 'p';
        i++;
    }
    res[i] = '\0';
    return (res);
}

void Dialog::set_string()
{
    QString s;
    char pcnf[2000];
    char pdnf[2000];
    int j = 0;
    int k = 0;
    int flag1 = 1;
    int flag2 = 1;
    char *res_string;
    s = ui->label->text();
    char *string = convert(s);
    string[s.length()] = '\0';
    if ((validation(string) == 0) || (count_of_brackets(string) % 2 == 1))
    {
        ui->label->setText("You made a mistake, please check the input data.");
        return ;
    }
    res_string = get_answer(string);
    pdnf[0] = '\0';
    pcnf[0] = '\0';
    while(*res_string)
    {
        if  (*res_string == '.')
        {
            res_string++;
            while ((*res_string != ',') && (*res_string != '.') && (*res_string))
            {
                pcnf[j] = *res_string;
                j++;
                res_string++;
            }
            pcnf[j++] = ' ';
            pcnf[j++] = 'v';
            pcnf[j++] = ' ';
            if (flag1 % 3 == 0)
            {
                pcnf[j++] = '\n';
                pcnf[j++] = '\t';
            }
        }
        else if  (*res_string == ',')
        {
            res_string++;
            pdnf[k++] = '(';
            while ((*res_string != ',') && (*res_string != '.') && (*res_string))
            {
                pdnf[k] = *res_string;
                k++;
                res_string++;
            }
            pdnf[k++] = ')';
            pdnf[k++] = ' ';
            pdnf[k++] = '&';
            pdnf[k++] = ' ';
            if (flag2 % 3 == 0)
            {
                pdnf[k++] = '\n';
                pdnf[k++] = '\t';
            }
        }
        flag1++;
        flag2++;
    }
    pdnf[k - 3] = '\0';
    pcnf[j - 3] = '\0';
    delete [] string;
    convert_answers_to_text(pdnf, pcnf, s);
}

void Dialog::convert_answers_to_text(char *pdnf, char *pcnf, QString s)
{
    ui->label->setText("Entered data: " + s + "\n\n\n" + "PCNF is: " + pdnf + "\n\n" + "PDNF is :" + pcnf);
    std::cout << std::endl;
}

int validation(char *str)
{
    int i;

    i = 0;
    while (str[i + 1])
    {
        if ((is_op(str[i])) && (is_op(str[i + 1])))
            return (0);
        i++;
    }
    return (1);
}

int is_op(char c)
{
    if ((c == '+') || (c == '*') || (c == '-') || (c == '/') || (c == '|') || (c == '~') || (c == '='))
        return (1);
    return (0);
}

Dialog::~Dialog()
{
    delete ui;
}

