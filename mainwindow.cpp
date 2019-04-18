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
    ui->comboBox->addItem("RU");
    ui->comboBox->addItem("USD");
    ui->calendarLayout->addWidget(calendar);
    calendar->close();
    result->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_result_clicked()
{
    QDate startDate = ui->startCalendar->selectedDate();
    QDate endDate = ui->endCalendar->selectedDate();
    date::year_month_day start = date::year{startDate.year()}/startDate.month()/startDate.day();
    date::year_month_day end = date::year{endDate.year()}/endDate.month()/endDate.day();
    double depositAmount = ui->depositAmount->toPlainText().toDouble();
    bool isCapitalized = ui->isCpitalaised->isChecked();
    bool isEarlyClousing = ui->isEarlyClousing->isChecked();
    std::string strCurrency = (ui->comboBox->currentText()).toStdString();
    currency value = RU;
    switch (strCurrency[0]){
    case 'R':
        value = RU;
        break;
    case 'U':
        value = USD;
        break;
    }


    if (isEarlyClousing){
        QDate earlyDate = calendar->selectedDate();
        date::year_month_day early = date::year{earlyDate.year()}/earlyDate.month()/earlyDate.day();
        Maths deposit{value,start,end,depositAmount,early};
        ui->resultLabel->setText(QString::number(deposit.showResult()));
    } else {
        Maths deposit{value,start,end,depositAmount,isCapitalized,isEarlyClousing};
        ui->resultLabel->setText(QString::number(deposit.showResult()));
    }




}

void MainWindow::on_isNotEarlyClousing_toggled(bool checked)
{
    if (!checked){
        calendar->show();

    }else {

        ui->calendarLayout->removeWidget(calendar);
        calendar->close();
}

}
