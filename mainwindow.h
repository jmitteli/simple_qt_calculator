#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <string>

#include <QButtonGroup>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void onDigitClicked(int digit);

    void on_clrBtn_clicked();

    void on_plusBtn_clicked();

    void on_resultBtn_clicked();

private:
    Ui::MainWindow *ui;
    QButtonGroup* digitGroup = nullptr;
    QString currentEntry = "0";
    bool startNewEntry = true;
    void appendDigit(int d);
};
#endif // MAINWINDOW_H
