#include "mainwindow.h"
#include "odbchelper.h"
#include <QApplication>
#include "vtkConeSource.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    odbchelper k;
    k.getpointid();
    return a.exec();
}
