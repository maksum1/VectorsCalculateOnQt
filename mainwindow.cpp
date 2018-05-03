#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<vectorio.h>
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


    //initiations of A and B Vectors
    A.InitVectorA(ui);
    B.InitVectorB(ui);

    //initiation C vector

    ui->line_skalar->setText(QString::number(A.Skalar(B)));


    C=A+B;
    C.Variable=1;
    VectorIO Test;
    ui<<Test &C;
    //ui<<C;

    C = A - B ;
    C.Variable=2;
    //ui<<C;

    C = A * B ;

    C = A.V_Mult(B);//Find Vector Multy
    C.Variable=3;
    //ui<<C;


    C = A.K_Mult(ui->line_K->text().toInt());//multiply vector A on number K
    C.Variable=4;
    //ui<<C;


    C=MultyVectorSkalar(A,ui->line_skal->text().toInt());//multiply vector A on number Skalar
    C.Variable=7;
    //ui<<C;

    B.Variable=5;
    //ui<<B;

    A.Variable=6;
    //ui<<A;


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
