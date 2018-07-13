#include <QApplication>
#include "odbchelper.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    odbchelper k;
    k.getpointid();
    return a.exec();
}
