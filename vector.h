#ifndef VECTOR_H
#define VECTOR_H
#include<qstring.h>
#include <iostream>
#include <math.h>

#include"ui_mainwindow.h"
using namespace std;
class Vector
{
public:   
    ~Vector()//Destructor that will subtract if we delete object
    {
        --NumbersObj;
    }
    Vector(int x , int y , int z );

    Vector( );
    //Friends Functions
    friend bool operator == (  Vector &b,  Vector &a) ;
    friend bool operator < (  Vector &b,  Vector &a);
    friend bool operator > (  Vector &b,  Vector &a);
    friend ostream& operator<<(ostream& os, Vector& a);
    friend Vector MultyVectorSkalar( Vector &A ,int Skal);

    //OverLoading Operators
    Vector operator+(Vector& B);

    Vector& operator=(Vector B);

    Vector operator *(Vector& B);

    Vector operator -(Vector& B);

    //Functions
    Vector MultyVectorSkalar( Vector &A ,int Skal);

    QString Skalar()const;

    Vector V_Mult(Vector &B);

    Vector K_Mult(int K);

    //Seters and Geters
    int x() const;
    void setX(int x);

    int y() const;
    void setY(int y);

    int z() const;
    void setZ(int z);

    int res()const;

    //Function that counts number of create objects class Vector

    static int NumbersObj;

    static int AddNumberObj();
    static int MinusNumberObj();

    //Functions for print

    void PrintSumVectors(Ui::MainWindow *ui);

    void PrintMinusVector(Ui::MainWindow *ui);

    void PrintMultyVectors(Ui::MainWindow *ui);

    void PrintVectMulty(Ui::MainWindow *ui);

    void PrintMultyOnNumber(Ui::MainWindow *ui);

    void PrintWidthA(Ui::MainWindow *ui);
    void PrintWidthB(Ui::MainWindow *ui);

    void PrintVectorOnSkalar(Ui::MainWindow *ui);

    //Funtion for initiations Vectors
    void InitVectorA(Ui::MainWindow *ui);
    void InitVectorB(Ui::MainWindow *ui);

    //add comment

private:

    Ui::MainWindow *mi;

    double Width();
    int m_x;
    int m_y;
    int m_z;

};




#endif // VECTOR_H
