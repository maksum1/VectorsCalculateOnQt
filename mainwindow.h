#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "vector.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    //Functions that press button when we end editing any on EditLines
    void on_pushButton_clicked();

    void on_line_a_x_editingFinished();

    void on_line_a_y_editingFinished();

    void on_line_a_z_editingFinished();

    void on_line_b_x_editingFinished();

    void on_line_b_y_editingFinished();

    void on_line_b_z_editingFinished();

    void on_line_K_editingFinished();

    void on_line_skal_editingFinished();

    void on_pushButtonAddNum_clicked();

    void on_pushButtonMinusNumObj_clicked();

private:
    Vector A;
    Vector B;


    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
