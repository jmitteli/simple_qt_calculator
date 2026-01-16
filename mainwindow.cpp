#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Using button groups to not need a separate method for each number. The functional buttons +,-,*,/,= etc have their own methods.
    digitGroup = new QButtonGroup(this);
    digitGroup->setExclusive(false);

    digitGroup->addButton(ui->zeroBtn,0);
    digitGroup->addButton(ui->oneBtn,1);
    digitGroup->addButton(ui->twoBtn,2);
    digitGroup->addButton(ui->threeBtn,3);
    digitGroup->addButton(ui->fourBtn,4);
    digitGroup->addButton(ui->fiveBtn,5);
    digitGroup->addButton(ui->sixBtn,6);
    digitGroup->addButton(ui->sevenBtn,7);
    digitGroup->addButton(ui->eightBtn,8);
    digitGroup->addButton(ui->nineBtn,9);

//Some QT version handling suggested by AI. Need to look more into this. Does not work without this, atleast under linux
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    connect(digitGroup, &QButtonGroup::idClicked,this, &MainWindow::onDigitClicked);
#else
    connect(digitGroup, &QOverload<int>::of(&QButtonGroup::buttonClicked),this, &MainWindow::onDigitClicked);
#endif


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onDigitClicked(int digit)
{
    std::cout<<"Digit clicked: "<< digit <<std::endl;//Just for debug. Should be put in comments for final version
    appendDigit(digit);
}

//Clear button clears the displaay to zero
void MainWindow::on_clrBtn_clicked()
{
    std::cout<<"Clear button clicked"<<std::endl;//Just for debug. Should be put in comments for final version
    currentEntry = "0";
    startNewEntry = true;
    ui->displayLineEdit->setText("0");
}


void MainWindow::on_plusBtn_clicked()
{
    std::cout<<" Plus button clicked"<<std::endl;//Just for debug. Should be put in comments for final version
}


void MainWindow::on_resultBtn_clicked()
{
    std::cout<<"Result button clicked"<<std::endl;//Just for debug. Should be put in comments for final version
}

//Handling of the digits to the input. Function definition
void MainWindow::appendDigit(int d)
{
    std::cout<<"appendDigit called"<<std::endl;//Just for debug. Should be put in comments for final version

    if (startNewEntry == true){
        currentEntry = "0";
        startNewEntry = false;
    }

    if (currentEntry == "0"){
        if (d == 0){
            return;//Exits the function if digit pressed is 0
        }
        currentEntry = QString::number(d);//Converts int d to Qstring type variable
    }else{
        currentEntry += QString::number(d);
    }


    ui->displayLineEdit->setText(currentEntry);

}



