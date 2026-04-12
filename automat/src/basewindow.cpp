//
// Created by Filip on 16.10.2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_baseWindow.h" resolved

#include "basewindow.h"
#include "ui_basewindow.h"
#include <QDateTime>
#include <QTimer>


BaseWindow::BaseWindow(QWidget *parent) : QWidget(parent), ui(new Ui::baseWindow) {
    ui->setupUi(this);

    connect(ui->normalTicketAdd, &QPushButton::clicked, this, &BaseWindow::addNormalTickedCount);
    connect(ui->normalTicketMinus, &QPushButton::clicked, this, &BaseWindow::minusNormalTickedCount);
    connect(ui->reducedTicketAdd, &QPushButton::clicked, this, &BaseWindow::addDiscountTickerCount);
    connect(ui->reducedTicketMinus, &QPushButton::clicked, this, &BaseWindow::minusDiscountTickerCount);

    connect(ui->buyButton, &QPushButton::clicked, this, &BaseWindow::buyTicket);
    connect(&timer, &QTimer::timeout, this, &BaseWindow::updateDataTime);
    timer.setInterval(1000);
    timer.start();

}

BaseWindow::~BaseWindow() {
    delete ui;
}

void BaseWindow::updateSum()
{
    int moneyValue = ui->normalTicketAmount->value() * 500;
    moneyValue+=ui->reducedTicketAmount->value()*250;
    QString money = QString("%1, %2zł").arg(moneyValue/100).arg(moneyValue % 100, 2, 10, QChar ('0'));
    ui->sumValue->setText(money);
}

void BaseWindow::addNormalTickedCount()
{
    ui->normalTicketAmount->stepUp();
    updateSum();
}

void BaseWindow::minusNormalTickedCount()
{
    ui->normalTicketAmount->stepDown();
    updateSum();
}

void BaseWindow::addDiscountTickerCount()
{
    ui->reducedTicketAmount->stepUp();
    updateSum();
}

void BaseWindow::minusDiscountTickerCount()
{
    ui->reducedTicketAmount->stepDown();
    updateSum();
}

void BaseWindow::updateDataTime(){
    QDateTime now = QDateTime::currentDateTime();
    ui->dateTime->setText(now.toString("yyyy-MM-dd hh:mm:ss"));
}
