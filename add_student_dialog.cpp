#include "add_student_dialog.h"
#include "ui_add_student_dialog.h"

Add_Student_Dialog::Add_Student_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Student_Dialog)
{
    ui->setupUi(this);
}

Add_Student_Dialog::~Add_Student_Dialog()
{
    delete ui;
}

QString Add_Student_Dialog::getName()
{
    return ui->name_LineEdit->text();
}

QString Add_Student_Dialog::getSurname()
{
    return ui->surname_LineEdit->text();
}

int Add_Student_Dialog::getMathMark()
{
    return ui->mark_Math_SpinBox->value();
}

int Add_Student_Dialog::getPKMark()
{
    return ui->mar_PK_SpinBox->value();
}
