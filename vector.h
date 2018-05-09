#ifndef VECTOR_H
#define VECTOR_H
#include<qstring.h>
#include <math.h>

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

    bool operator == (const  Vector &a)const;
    bool operator < ( const  Vector &a)const;
    bool operator > (  const Vector &a)const;

    Vector MultiplyOnSkalar(const int Skal) const;

    //OverLoading Operators
    Vector operator + ( const Vector& B)const;

    Vector& operator = (const Vector B);

    Vector operator * (const Vector& B)const;

    Vector operator - (const Vector& B)const;

    double Skalar(const Vector &B)const;

    Vector V_Multiply(const Vector &B)const;

    Vector MultiplyOnK(const int K)const ;

    //Seters and Geters
    int x() const;
    void setX(int x);

    int y() const;
    void setY(int y);

    int z() const;
    void setZ(int z);

    int res()const;

    static int NumbersObj;


    //add comment
    double Length()const;

    int Variable;
private:



    int m_x;
    int m_y;
    int m_z;

};




#endif // VECTOR_H
