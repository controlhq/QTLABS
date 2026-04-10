#include "widget.h"
#include "./ui_lab1layout.h"

Widget::Widget(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}