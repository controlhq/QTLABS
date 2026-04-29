#include "coininserter.h"
#include "ui_coininserter.h"

CoinInserter::CoinInserter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CoinInserter)
{
    ui->setupUi(this);
    connect(ui->pushButton_5zl, &QPushButton::clicked, this, [this](){ emit coinInserted(500); });
    connect(ui->pushButton_2zl, &QPushButton::clicked, this, [this](){ emit coinInserted(200); });
    connect(ui->pushButton_1zl, &QPushButton::clicked, this, [this](){ emit coinInserted(100); });
    connect(ui->pushButton_50gr, &QPushButton::clicked, this, [this](){ emit coinInserted(50); });
    connect(ui->pushButton_20gr, &QPushButton::clicked, this, [this](){ emit coinInserted(20); });
    connect(ui->pushButton_10gr, &QPushButton::clicked, this, [this](){ emit coinInserted(10); });
}

CoinInserter::~CoinInserter()
{
    delete ui;
}
