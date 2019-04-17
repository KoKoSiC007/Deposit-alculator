#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
#include "maths.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_result_clicked()
{
    QDate startDate = ui->startCalendar->selectedDate();
    QDate endDate = ui->endCalendar->selectedDate();
    qDebug() << startDate.year() << startDate.month() << startDate.day();
    date::year_month_day start = date::year{startDate.year()}/startDate.month()/startDate.day();
    date::year_month_day end = date::year{endDate.year()}/endDate.month()/endDate.day();
    int avg = (date::sys_days{end} - date::sys_days{start}).count();
    qDebug() << startDate << endDate << avg;
}
