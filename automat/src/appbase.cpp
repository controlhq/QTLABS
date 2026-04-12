#include "appbase.h"
#include "basewindow.h"
#include "ui_appbase.h"

AppBase::AppBase(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AppBase)
{
    ui->setupUi(this);
    baseWindow = new BaseWindow(ui->stackedWidget);
    ui->stackedWidget->addWidget(baseWindow);
    ui->stackedWidget->setCurrentWidget(baseWindow);

    connect(baseWindow, &BaseWindow::buyTicket,[this](){
        ui->stackedWidget->setCurrentWidget(ui->payment);
    });
}

AppBase::~AppBase()
{
    delete ui;
}
