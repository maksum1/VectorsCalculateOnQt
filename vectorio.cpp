#include "vectorio.h"

VectorIO::VectorIO()
{

}

void operator<<(Ui::MainWindow *os, Vector &a )
{
    //os->line_Width->setText(QString::number());

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
        os->lineWidthB->setText(QString::number(a.Width()));
    }
    if(a.Variable == 6)
    {
        os->line_Width->setText(QString::number(a.Width()));
    }

    if(a.Variable == 7)
    {
        os->line_sk_x->setText(QString::number(a.x()));
        os->line_sk_y->setText(QString::number(a.y()));
        os->line_sk_z->setText(QString::number(a.z()));
    }



}
