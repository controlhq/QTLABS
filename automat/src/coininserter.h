#ifndef COININSERTER_H
#define COININSERTER_H

#include <QWidget>

namespace Ui {
class CoinInserter;
}

class CoinInserter : public QWidget
{
    Q_OBJECT

public:
    explicit CoinInserter(QWidget *parent = nullptr);
    ~CoinInserter();

private:
    Ui::CoinInserter *ui;

};

#endif // COININSERTER_H
