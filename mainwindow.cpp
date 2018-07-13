#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVTKWidget.h>
#include <vtkRenderer.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVTKWidget *a=new QVTKWidget(this);
    this->setCentralWidget(a);
}

MainWindow::~MainWindow()
{
    delete ui;
}
