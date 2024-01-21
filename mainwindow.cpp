#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showLogo();
    setupTable();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showLogo()
{
    QString FILENAME_LOGO = "./image/logo.png";
    QPixmap m_logo_Pix;

    if(m_logo_Pix.load(FILENAME_LOGO))
    {
    ui->logo_pix->setScaledContents(true);
    ui->logo_pix->setPixmap(m_logo_Pix);
    }
}

void MainWindow::refreshTable()
{
    ui->stud_mark_Table->clearContents();
    ui->stud_mark_Table->setRowCount(0);

    QMapIterator<QString,QString> i(m_Students_Names_Map);
    QMapIterator<QString, int> m(m_Students_MathMark_Map);
    QMapIterator<QString, int> pk(m_Students_PKMark_Map);

    for (int row = 0; row < m_Students_Names_Map.count(); row++) {
        if(i.hasNext() && m.hasNext()&& pk.hasNext()){
            i.next();   m.next();   pk.next();
            ui->stud_mark_Table->insertRow(row);
            ui->stud_mark_Table->setItem(row,0,new QTableWidgetItem(i.value()));
            ui->stud_mark_Table->setItem(row,1,new QTableWidgetItem(i.key()));
            ui->stud_mark_Table->setItem(row,2,new QTableWidgetItem(QString::number(m.value())));
            ui->stud_mark_Table->setItem(row,3,new QTableWidgetItem(QString::number(pk.value())));
        }
    }
}

void MainWindow::setupTable()
{
    QStringList header_labels;
    header_labels << "Imię" << "Nazwisko" << "Matematyka" << "PK";
    ui->stud_mark_Table->setColumnCount(4);
    ui->stud_mark_Table->verticalHeader()->setVisible(false);
    ui->stud_mark_Table->setHorizontalHeaderLabels(header_labels);
}


void MainWindow::on_add_stud_Btn_clicked()
{
    m_add_Stud_Dialog = new Add_Student_Dialog(nullptr);
    int which_Button_Clicked = m_add_Stud_Dialog->exec();
    if(which_Button_Clicked){
    QString key = m_add_Stud_Dialog->getSurname();
    m_Students_Names_Map.insert(key,m_add_Stud_Dialog->getName());
    m_Students_MathMark_Map.insert((key),m_add_Stud_Dialog->getMathMark());
    m_Students_PKMark_Map.insert(key, m_add_Stud_Dialog->getPKMark());
    refreshTable();
    }else{
        QMessageBox message(this);
        message.setText("Nie wprowadzono danych. Nie dodano danych ucznia.");
        message.exec();
    }
    delete m_add_Stud_Dialog;

}


void MainWindow::on_count_avg_Btn_clicked()
{
    computeMarkAvg();
}

void MainWindow::computeMarkAvg()
{
    int sum_math_mark = 0, sum_pk_mark=0;
    for (int math_mark : m_Students_MathMark_Map) {
        sum_math_mark+=math_mark;
    }
    for (int pk_mark : m_Students_PKMark_Map) {
        sum_pk_mark+=pk_mark;
    }
    double total = m_Students_Names_Map.count();
    double math_avg = sum_math_mark/total;
    double pk_avg = sum_pk_mark/total;
    showMarkAvg(math_avg, pk_avg);

}

void MainWindow::showMarkAvg(double math_avg, double pk_avg)
{
    ui->avg1_Lbl->setText(QString::number(math_avg,'g',2));
    ui->avg2_Lbl->setText(QString::number(pk_avg,'g',2));
}
