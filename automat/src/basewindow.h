//
// Created by Filip on 16.10.2025.
//

#ifndef AUTOMAT_BASEWINDOW_H
#define AUTOMAT_BASEWINDOW_H

#include <QTimer>
#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class baseWindow;
}

QT_END_NAMESPACE

class BaseWindow : public QWidget {
    Q_OBJECT

public:
    void resetTickets();
    explicit BaseWindow(QWidget *parent = nullptr);

    ~BaseWindow() override;

signals:
    void buyTicket(int kwotaDoZaplaty, int normalne, int ulgowe);

private slots:
    void updateDataTime();
    void processPurchase();
private:
    Ui::baseWindow *ui;
    QTimer timer;


    void updateSum();
    void addNormalTickedCount();
    void minusNormalTickedCount();
    void addDiscountTickerCount();
    void minusDiscountTickerCount();
    bool isticketcount0();


};




#endif //AUTOMAT_BASEWINDOW_H