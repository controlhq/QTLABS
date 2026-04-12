//
// Created by Filip on 19.10.2025.
//

#ifndef AUTOMAT_PAYMENTWINDOWS_H
#define AUTOMAT_PAYMENTWINDOWS_H

#include <CoinInserter.h>
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

    ~PaymentWindows() override;

private:
    Ui::PaymentWindows *ui;

    CoinInserter coinInserter;

    // QWidget interface
protected:
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
};


#endif //AUTOMAT_PAYMENTWINDOWS_H
