#include <QApplication>
#include "appbase.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    AppBase app;

    app.show();

    return QApplication::exec();
}
