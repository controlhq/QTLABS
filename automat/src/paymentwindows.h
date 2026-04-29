//
// Created by Filip on 19.10.2025.
//

#ifndef AUTOMAT_PAYMENTWINDOWS_H
#define AUTOMAT_PAYMENTWINDOWS_H

#include "coininserter.h"
#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class PaymentWindows;
}

QT_END_NAMESPACE

class PaymentWindows : public QWidget {
    Q_OBJECT

public:
    explicit PaymentWindows(QWidget *parent = nullptr);
    void setAmountToPay(int amountInGrosze, int normal, int reduced);
    ~PaymentWindows() override;

private:
    int normalTicketsCount = 0;
    int reducedTicketsCount = 0;
    Ui::PaymentWindows *ui;
    int totalToPay=0;
    int amountPaid=0;
    void updateLabels();
    QTimer *clockTimer;

    CoinInserter coinInserter;

private slots:
    void handleCoin(int coinValue);
    void updateDataTime();
    void onReturnClicked();

signals:
    void resetAndReturnToMain();
    void paymentSuccessful(int change, int normal, int reduced);

    // QWidget interface
protected:
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
};


#endif //AUTOMAT_PAYMENTWINDOWS_H
