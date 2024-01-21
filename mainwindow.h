#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QString>
#include <QMultiMap>
#include <QVariant>
#include <QMessageBox>
#include "add_student_dialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_stud_Btn_clicked();
    void on_count_avg_Btn_clicked();

private:
    Ui::MainWindow *ui;
    Add_Student_Dialog *m_add_Stud_Dialog;
    void showLogo();
    QMap<QString, QString> m_Students_Names_Map;
    QMap<QString, int> m_Students_MathMark_Map;
    QMap<QString, int> m_Students_PKMark_Map;
    void refreshTable();
    void setupTable();
    void computeMarkAvg();
    void showMarkAvg(double math_avg, double pk_avg);

};
#endif // MAINWINDOW_H
