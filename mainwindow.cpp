#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("JustVectors");//Change title of mainwindow

    // Use Validator , so we can enter just numbers (-1000 to 1000)
    ui->line_a_x->setValidator( new QIntValidator(-1000, 1000, this) );
    ui->line_a_y->setValidator( new QIntValidator(-1000, 1000, this) );
    ui->line_a_z->setValidator( new QIntValidator(-1000, 1000, this) );

    ui->line_b_x->setValidator( new QIntValidator(-1000, 1000, this) );
    ui->line_b_y->setValidator( new QIntValidator(-1000, 1000, this) );
    ui->line_b_z->setValidator( new QIntValidator(-1000, 1000, this) );

    ui->line_K->setValidator( new QIntValidator(-1000, 1000, this) );

    ui->line_skal->setValidator( new QIntValidator(-1000, 1000, this) );

}

void operator<<(Ui::MainWindow *os,  Vector &a )
{
    if(a.Variable ==1 )
    {
        os->line_Add_x->setText(QString::number(a.x()));
        os->line_Add_y->setText(QString::number(a.y()));
        os->line_Add_z->setText(QString::number(a.z()));
    }
    if(a.Variable == 2)
    {
        os->line_Minus_x->setText(QString::number(a.x()));
        os->line_Minus_y->setText(QString::number(a.y()));
        os->line_Minus_z->setText(QString::number(a.z()));
    }
    if(a.Variable == 3)
    {
        os->line_vect_x->setText(QString::number(a.x()));
        os->line_vect_y->setText(QString::number(a.y()));
        os->line_vect_z->setText(QString::number(a.z()));
    }
    if(a.Variable == 4)
    {
        os->line_K_x->setText(QString::number(a.x()));
        os->line_K_y->setText(QString::number(a.y()));
        os->line_K_z->setText(QString::number(a.z()));
    }
    if(a.Variable == 5)
    {
        os->lineWidthB->setText(QString::number(a.Length()));
    }
    if(a.Variable == 6)
    {
        os->line_Width->setText(QString::number(a.Length()));
    }

    if(a.Variable == 7)
    {
        os->line_sk_x->setText(QString::number(a.x()));
        os->line_sk_y->setText(QString::number(a.y()));
        os->line_sk_z->setText(QString::number(a.z()));
    }
}

void operator>>(Ui::MainWindow *is,  Vector &a )
{
    if(a.Variable == 11)
    {
        a.setX(is->line_a_x->text().toInt());
        a.setY(is->line_a_y->text().toInt());
        a.setZ(is->line_a_z->text().toInt());
    }
    if(a.Variable == 22)
    {
        a.setX(is->line_b_x->text().toInt());
        a.setY(is->line_b_y->text().toInt());
        a.setZ(is->line_b_z->text().toInt());
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Vector::NumbersObj=0;
    Vector A;
    Vector B;
    Vector C;

    A.Variable=11;
    ui>>A;
    B.Variable=22;
    ui>>B;

    //initiation C vector

    ui->line_skalar->setText(QString::number(A.Skalar(B)));

    C=A+B;
    C.Variable=1;
    ui<<C;

    C = A - B ;
    C.Variable=2;
    ui<<C;

    C = A * B ;

    C = A.V_Multiply(B);//Find Vector Multy
    C.Variable=3;
    ui<<C;


    C = A.MultiplyOnK(ui->line_K->text().toInt());//multiply vector A on number K
    C.Variable=4;
    ui<<C;

    C=A.MultiplyOnSkalar(ui->line_skal->text().toInt());//multiply vector A on number Skalar
    C.Variable=7;
    ui<<C;

    B.Variable=5;
    ui<<B;

    A.Variable=6;
    ui<<A;


    //Compare vector A and B
    if (A == B )
    {
        ui->line_equals->setText("Yes");
        ui->lineLower->setText("No");
        ui->linehigher->setText("No");
    }
    if(A>B)
    {   ui->line_equals->setText("No");
        ui->lineLower->setText("Yes");
        ui->linehigher->setText("No");

    }
    if(A<B)
    {   ui->line_equals->setText("No");
        ui->lineLower->setText("No");
        ui->linehigher->setText("Yes");
    }
    //get number of obj

    ui->lineNumberObg->setText(QString::number(Vector::NumbersObj));

}


//Helping functions when we end edit EditLine
void MainWindow::on_line_a_x_editingFinished()
{
    ui->pushButton->click();
}

void MainWindow::on_line_a_y_editingFinished()
{
    ui->pushButton->click();
}

void MainWindow::on_line_a_z_editingFinished()
{
    ui->pushButton->click();
}

void MainWindow::on_line_b_x_editingFinished()
{
    ui->pushButton->click();
}

void MainWindow::on_line_b_y_editingFinished()
{
    ui->pushButton->click();
}

void MainWindow::on_line_b_z_editingFinished()
{
    ui->pushButton->click();

}



void MainWindow::on_line_K_editingFinished()
{
    ui->pushButton->click();

}

void MainWindow::on_line_skal_editingFinished()
{
    ui->pushButton->click();

}
