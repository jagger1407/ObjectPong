#include "pong.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Pong w;
    w.show();

    return app.exec();
}

