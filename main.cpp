#include "MainScene.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::testAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainScene w;
    w.show();
    return a.exec();
}
