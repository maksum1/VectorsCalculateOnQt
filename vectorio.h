#ifndef VECTORIO_H
#define VECTORIO_H
#include <iostream>
#include"vector.h"
#include"ui_mainwindow.h"

class VectorIO
{
public:
    VectorIO();


    friend void operator<<(Ui::MainWindow *os, Vector& a);

};

#endif // VECTORIO_H
