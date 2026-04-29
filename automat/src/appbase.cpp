#include "appbase.h"
#include "basewindow.h"
#include "ui_appbase.h"
#include "paymentwindows.h"
#include "summarywindow.h"

AppBase::AppBase(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AppBase)
{
    ui->setupUi(this);


    baseWindow = new BaseWindow(ui->stackedWidget);
    ui->stackedWidget->addWidget(baseWindow);
    ui->stackedWidget->setCurrentWidget(baseWindow);

    connect(baseWindow, &BaseWindow::buyTicket, [this](int amount, int normal, int reduced){
        ui->payment->setAmountToPay(amount, normal, reduced);
        ui->stackedWidget->setCurrentWidget(ui->payment);
    });


    connect(ui->payment, &PaymentWindows::paymentSuccessful, [this](int change, int normal, int reduced){
        ui->summary->displaySummary(change, normal, reduced);
        ui->stackedWidget->setCurrentWidget(ui->summary);
    });


    connect(ui->payment, &PaymentWindows::resetAndReturnToMain, [this](){
        baseWindow->resetTickets();
        ui->stackedWidget->setCurrentWidget(baseWindow);
    });


    connect(ui->summary, &summaryWindow::finished, this, [this](){
        baseWindow->resetTickets();
        ui->stackedWidget->setCurrentWidget(baseWindow);
    });
}

AppBase::~AppBase()
{
    delete ui;
}
