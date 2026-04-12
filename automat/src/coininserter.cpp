#include "coininserter.h"
#include "src/ui_coininserter.h"

CoinInserter::CoinInserter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CoinInserter)
{
    ui->setupUi(this);
}

CoinInserter::~CoinInserter()
{
    delete ui;
}
