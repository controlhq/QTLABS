//
// Created by Filip on 19.10.2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PaymentWindows.h" resolved

#include "paymentwindows.h"

#include <QPushButton>

#include "ui_paymentwindows.h"
#include <QDateTime>
#include <QTimer>


PaymentWindows::PaymentWindows(QWidget *parent) : QWidget(parent), ui(new Ui::PaymentWindows) {
    ui->setupUi(this);
    clockTimer = new QTimer(this);
    connect(clockTimer, &QTimer::timeout, this, &PaymentWindows::updateDataTime);
    clockTimer->start(1000);
    updateDataTime();

    connect(&coinInserter, &CoinInserter::coinInserted, this, &PaymentWindows::handleCoin);
    connect(ui->backButton, &QPushButton::clicked, this, &PaymentWindows::onReturnClicked);
}

PaymentWindows::~PaymentWindows() {
    delete ui;
}

void PaymentWindows::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    coinInserter.show();
}

void PaymentWindows::hideEvent(QHideEvent *event)
{
    QWidget::hideEvent(event);

    coinInserter.hide();
}

void PaymentWindows::setAmountToPay(int amountInGrosze, int normal, int reduced) {
    totalToPay = amountInGrosze;
    normalTicketsCount = normal;
    reducedTicketsCount = reduced;
    amountPaid = 0;
    updateLabels();
}

void PaymentWindows::updateLabels() {
    int remaining = totalToPay - amountPaid;
    if (remaining < 0) remaining = 0;

    QString toPayStr = QString("%1,%2 zł").arg(remaining / 100).arg(remaining % 100, 2, 10, QChar('0'));
    ui->toPayValue->setText(toPayStr);

    QString paidStr = QString("%1,%2 zł").arg(amountPaid / 100).arg(amountPaid % 100, 2, 10, QChar('0'));
    ui->paidValue->setText(paidStr);
}

void PaymentWindows::handleCoin(int coinValue) {
    amountPaid += coinValue;
    updateLabels();

    if (amountPaid >= totalToPay) {
        int change = amountPaid - totalToPay;
        emit paymentSuccessful(change, normalTicketsCount, reducedTicketsCount);
    }
}

void PaymentWindows::updateDataTime() {
    QDateTime now = QDateTime::currentDateTime();
    ui->dateTime->setText(now.toString("yyyy-MM-dd hh:mm:ss"));
}

void PaymentWindows::onReturnClicked() {
    emit resetAndReturnToMain();
}