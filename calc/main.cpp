#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "maths.h"
using namespace std;
using namespace date;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
