#ifndef APPBASE_H
#define APPBASE_H

#include "basewindow.h"

#include <QWidget>

namespace Ui {
class AppBase;
}

class AppBase : public QWidget
{
    Q_OBJECT

public:
    explicit AppBase(QWidget *parent = nullptr);
    ~AppBase();


private:
    Ui::AppBase *ui;

    BaseWindow* baseWindow;
};

#endif // APPBASE_H
