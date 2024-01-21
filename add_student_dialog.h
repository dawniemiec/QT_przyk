#ifndef ADD_STUDENT_DIALOG_H
#define ADD_STUDENT_DIALOG_H

#include <QDialog>

namespace Ui {
class Add_Student_Dialog;
}

class Add_Student_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Student_Dialog(QWidget *parent = nullptr);
    ~Add_Student_Dialog();
    QString getName();
    QString getSurname();
    int getMathMark();
    int getPKMark();

private:
    Ui::Add_Student_Dialog *ui;

};

#endif // ADD_STUDENT_DIALOG_H
