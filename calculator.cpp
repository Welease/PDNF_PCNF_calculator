#include "calculator.h"
#include "ui_calculator.h"
#include "dialog.h"

calculator::calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calculator)
{
    ui->setupUi(this);
    connect(ui->Disjunction, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->Conjunction,  SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->Inversion, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->Equivalence, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->Implication, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->XOR, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->Pier_arrow, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->Schaeffers_stroke, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->Zero, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->One, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->a, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->b, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->c, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->x, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->y, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->z, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->Left_bracket, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->Right_bracket, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->l, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->m, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->n, SIGNAL(clicked()), this, SLOT(change_input()));
    connect(ui->p, SIGNAL(clicked()), this, SLOT(change_input()));
}

calculator::~calculator()
{
    delete ui;
}

void calculator::change_input()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label;
    new_label = ui->input->text();
    new_label = new_label + button->text();
    ui->input->setText(new_label);
}

void calculator::on_Backspace_clicked()
{
    QString str;
    int i;

    str = ui->input->text();
    i = str.length();
    ui->input->setText(str.left(i - 1));
}

void calculator::on_Check_clicked()
{
    QString res = ui->input->text();
    Dialog dlg;
    dlg.setT(res);
    dlg.setModal(true);
    dlg.exec();
}
