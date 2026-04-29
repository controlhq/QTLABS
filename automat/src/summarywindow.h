#ifndef SUMMARYWINDOW_H
#define SUMMARYWINDOW_H

#include <QWidget>

namespace Ui {
class summaryWindow;
}

class summaryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit summaryWindow(QWidget *parent = nullptr);
    ~summaryWindow();

    void displaySummary(int change, int normal, int reduced);

signals:
    void finished();

private:
    Ui::summaryWindow *ui;
};

#endif // SUMMARYWINDOW_H