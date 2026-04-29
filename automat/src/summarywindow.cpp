#include "summarywindow.h"
#include "ui_summarywindow.h"
#include <QTimer>

summaryWindow::summaryWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::summaryWindow)
{
    ui->setupUi(this);
}

summaryWindow::~summaryWindow()
{
    delete ui;
}

void summaryWindow::displaySummary(int change, int normal, int reduced) {
    ui->label_normaltickets->setText(QString::number(normal));
    ui->label_discounttickets->setText(QString::number(reduced));
    ui->label_change->setText(QString("%1,%2 zł").arg(change/100).arg(change%100, 2, 10, QChar('0')));

    QTimer::singleShot(10000, this, [this]() {
        emit finished();
    });
}