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
    friend Vector MultyVectorSkalar( Vector &A ,int Skal);

    //OverLoading Operators
    Vector operator+(Vector& B);

    Vector& operator=(Vector B);

    Vector operator *(Vector& B);

    Vector operator -(Vector& B);

    //Functions
    Vector MultyVectorSkalar( Vector &A ,int Skal);

    double Skalar(Vector &B)const;

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

    //Funtion for initiations Vectors
    void InitVectorA(Ui::MainWindow *ui);
    void InitVectorB(Ui::MainWindow *ui);

    //add comment

    int Variable;
    double Width();

private:

    Ui::MainWindow *mi;


    int m_x;
    int m_y;
    int m_z;

};




#endif // VECTOR_H
