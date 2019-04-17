#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "maths.h"
using namespace std;
using namespace date;
int main(int argc, char *argv[])
{
    year_month_day today = floor<days>(std::chrono::system_clock::now());
    std::cout << today << endl;
    year_month_day endDay = 2020_y/04/15;
    cout << (sys_days{endDay} - sys_days{today}).count() << endl;
    Maths testDeposit{RU,today,endDay, 10000, false, false};
    int y = 2000;
    int m = 5;
    int d = 11;
    year_month_day date = year{y}/5/11;
    cout << date;
    testDeposit.showResult();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
