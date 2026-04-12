//
// Created by Filip on 19.10.2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PaymentWindows.h" resolved

#include "paymentwindows.h"

#include <QPushButton>

#include "ui_paymentwindows.h"


PaymentWindows::PaymentWindows(QWidget *parent) : QWidget(parent), ui(new Ui::PaymentWindows) {
    ui->setupUi(this);
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
