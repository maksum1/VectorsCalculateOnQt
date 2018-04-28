#include "vector.h"
#include<qdebug.h>

Vector::Vector(int x , int y , int z ):m_x(x),m_y(y),m_z(z)
{}

//Static function just add 1 for statinc variable (don't add object)
int Vector::AddNumberObj()
{
    NumbersObj++;
    return NumbersObj;
}
//Same to subtract
int Vector::MinusNumberObj()
{
    NumbersObj--;
    return NumbersObj;
}


//Print
void Vector::PrintSumVectors(Ui::MainWindow *ui)
{
    ui->line_Add_x->setText(QString::number(this->x()));
    ui->line_Add_y->setText(QString::number(this->y()));
    ui->line_Add_z->setText(QString::number(this->z()));
}

void Vector::PrintMinusVector(Ui::MainWindow *ui)
{
    ui->line_Minus_x->setText(QString::number(this->x()));
    ui->line_Minus_y->setText(QString::number(this->y()));
    ui->line_Minus_z->setText(QString::number(this->z()));
}

void Vector::PrintMultyVectors(Ui::MainWindow *ui)
{
    ui->line_skalar->setText(this->Skalar());
}

void Vector::PrintVectMulty(Ui::MainWindow *ui)
{

    ui->line_vect_x->setText(QString::number(this->x()));
    ui->line_vect_y->setText(QString::number(this->y()));
    ui->line_vect_z->setText(QString::number(this->z()));
}

void Vector::PrintMultyOnNumber(Ui::MainWindow *ui)
{
    ui->line_K_x->setText(QString::number(this->x()));
    ui->line_K_y->setText(QString::number(this->y()));
    ui->line_K_z->setText(QString::number(this->z()));
}

void Vector::PrintWidthB(Ui::MainWindow *ui)
{
    ui->lineWidthB->setText(QString::number(this->Width()));

}

void Vector::PrintWidthA(Ui::MainWindow *ui)
{
    ui->line_Width->setText(QString::number(this->Width()));
}

void Vector::PrintVectorOnSkalar(Ui::MainWindow *ui)
{

    ui->line_sk_x->setText(QString::number(this->x()));
    ui->line_sk_y->setText(QString::number(this->y()));
    ui->line_sk_z->setText(QString::number(this->z()));
}

void Vector::InitVectorB(Ui::MainWindow *ui)
{
    this->setX(ui->line_b_x->text().toInt());
    this->setY(ui->line_b_y->text().toInt());
    this->setZ(ui->line_b_z->text().toInt());
}

void Vector::InitVectorA(Ui::MainWindow *ui)
{
    this->setX(ui->line_a_x->text().toInt());
    this->setY(ui->line_a_y->text().toInt());
    this->setZ(ui->line_a_z->text().toInt());
}


//Increases our static variable (show how many objects we create)
int Vector::NumbersObj=0;
Vector::Vector():m_x(0),m_y(0),m_z(0)
{
    NumbersObj++;
}


QString Vector::Skalar() const
{

    QString result;
    result= QString::number( m_x+m_y+m_z) ;

    return result;
}

Vector MultyVectorSkalar( Vector &A ,int Skal)
{
    Vector Temp;
    Temp.setX(A.x()*Skal);
    Temp.setY(A.y()*Skal);
    Temp.setZ(A.z()*Skal);
    return Temp;
}

Vector Vector::V_Mult(Vector &B)
{
    Vector Temp;
    Temp.setX( m_y * B.z()- m_z * B.y() );
    Temp.setY(( -1 ) * (m_x * B.z() - m_z * B.x() ));
    Temp.setZ(m_x * B.y() - m_y * B.x());
    return Temp;
}

Vector Vector::K_Mult(int K)
{
    Vector Temp;
    Temp.setX(m_x*K);
    Temp.setY(m_y*K);
    Temp.setZ(m_z*K);
    return Temp;
}

double Vector::Width()
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


ostream& operator<<( ostream& os,  Vector& a)
{
    os << "X:"<<a.m_x;
    return os;
}


Vector Vector::operator+(Vector &B)
{
    Vector temp;

    temp.setX(this->m_x+B.x());

    temp.setY(this->m_y+B.y());

    temp.setZ(this->m_z+B.z());

    return temp;

}

Vector &Vector::operator=(Vector B)
{
    this->m_x=B.x();
    this->m_y=B.y();
    this->m_z=B.z();
    return *this;
}

Vector Vector::operator *(Vector &B)
{
    Vector temp;
    temp.setX(this->m_x*B.x());
    temp.setY(this->m_y*B.y());
    temp.setZ(this->m_z*B.z());
    return temp;
}

Vector Vector::operator -(Vector &B)
{
    Vector temp;
    temp.setX(this->m_x-B.x());
    temp.setY(this->m_y-B.y());
    temp.setZ(this->m_z-B.z());
    return temp;

}

bool operator == ( Vector &b, Vector &a)
{
    return ( a.Width() ==b.Width() );
}

bool operator < ( Vector &b, Vector &a)
{
    return ( a.Width() < b.Width() );
}

bool operator > (  Vector &b, Vector &a)
{
    return ( a.Width() > b.Width() );
}
