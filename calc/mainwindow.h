#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCalendarWidget>
#include <QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_result_clicked();

    void on_isNotEarlyClousing_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QCalendarWidget *calendar = new QCalendarWidget;
    QLabel *result = new QLabel;
};

#endif // MAINWINDOW_H
