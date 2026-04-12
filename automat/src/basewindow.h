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
    explicit BaseWindow(QWidget *parent = nullptr);

    ~BaseWindow() override;

signals:
    void buyTicket();

private slots:
    void updateDataTime();
private:
    Ui::baseWindow *ui;
    QTimer timer;


    void updateSum();
    void addNormalTickedCount();
    void minusNormalTickedCount();
    void addDiscountTickerCount();
    void minusDiscountTickerCount();


};




#endif //AUTOMAT_BASEWINDOW_H