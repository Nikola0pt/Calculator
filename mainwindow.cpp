#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->HelloButton, &QPushButton::clicked, this,&MainWindow::HelloWorld);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::HelloWorld()
{
    QString userInput=ui->NumberInput->text();
    QString userInput2=ui->NumberInput2->text();
            if(userInput.isEmpty()|| userInput2.isEmpty()){
            QMessageBox::warning(this,"No Number","Enter both Numbers");
            return;
}
            bool k1,k2;
            int num1=userInput.toInt(&k1);
            int num2=userInput2.toInt(&k2);
            int sum;
            if (!k1 || !k2){
                QMessageBox::warning(this,"No Number","Enter valid numbers");
            return;
            }
            if(ui->MinusC->isChecked() && ui->PlusC->isChecked()){
                QMessageBox::warning(this,"Minus and Plus","Check only one operation");
                return;
            }
            if(!ui->MinusC->isChecked() && !ui->PlusC->isChecked()){
                QMessageBox::warning(this,"Minus and Plus","Check an operation");
                return;}

             if(ui->MinusC->isChecked()){
                sum=num1-num2;
            }
            if(ui->PlusC->isChecked()){
                sum=num1+num2;
            }

                QMessageBox::information(this,"Number","Your number is:"+ QString::number(sum));
}


