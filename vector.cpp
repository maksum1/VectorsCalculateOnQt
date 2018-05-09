#include "vector.h"
#include<qdebug.h>

Vector::Vector(int x , int y , int z ):m_x(x),m_y(y),m_z(z)
{}


int Vector::NumbersObj=0;
Vector::Vector():m_x(0),m_y(0),m_z(0)
{
    NumbersObj++;
}

double Vector::Skalar(const Vector &B) const
{

    double result;
    result =  m_x*B.x()+m_y*B.y()+m_z*B.z();

    return result;
}

Vector Vector::MultiplyOnSkalar(const int Skal)const
{
    Vector Temp;
    Temp.setX(this->x()*Skal);
    Temp.setY(this->y()*Skal);
    Temp.setZ(this->z()*Skal);
    return Temp;
}

Vector Vector::V_Multiply(const Vector &B) const
{
    Vector Temp;
    Temp.setX( m_y * B.z()- m_z * B.y() );
    Temp.setY(( -1 ) * (m_x * B.z() - m_z * B.x() ));
    Temp.setZ(m_x * B.y() - m_y * B.x());
    return Temp;
}

Vector Vector::MultiplyOnK(const int K)const
{
    Vector Temp;
    Temp.setX(m_x*K);
    Temp.setY(m_y*K);
    Temp.setZ(m_z*K);
    return Temp;
}

double Vector::Length()const
{
    double Temp = sqrt(pow(m_x,2)+pow(m_y,2)+pow(m_z,2));

    return Temp;
}




int Vector::x() const
{
    return m_x;
}

void Vector::setX(int x)
{
    m_x = x;
}

int Vector::y() const
{
    return m_y;
}

void Vector::setY(int y)
{
    m_y = y;
}

int Vector::z() const
{
    return m_z;
}

void Vector::setZ(int z)
{
    m_z = z;
}

int Vector::res() const
{
    return 0;
}



Vector Vector::operator+(const Vector &B) const
{
    Vector temp;

    temp.setX(this->m_x+B.x());

    temp.setY(this->m_y+B.y());

    temp.setZ(this->m_z+B.z());

    return temp;

}

Vector &Vector::operator=(const Vector B)
{
    this->m_x=B.x();
    this->m_y=B.y();
    this->m_z=B.z();
    return *this;
}

Vector Vector::operator *( const Vector &B)const
{
    Vector temp;
    temp.setX(this->m_x*B.x());
    temp.setY(this->m_y*B.y());
    temp.setZ(this->m_z*B.z());
    return temp;
}

Vector Vector::operator -(const Vector &B)const
{
    Vector temp;
    temp.setX(this->m_x-B.x());
    temp.setY(this->m_y-B.y());
    temp.setZ(this->m_z-B.z());
    return temp;

}

bool Vector::operator == (const  Vector &a)const
{
    return ( a.Length() == this->Length() );
}

bool Vector::operator < ( const  Vector &a)const
{
    return ( a.Length() < this->Length() );
}

bool Vector::operator > (  const Vector &a)const
{
    return ( a.Length() > this->Length() );
}
