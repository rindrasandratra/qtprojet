#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setAttribute(Qt::AA_SynthesizeMouseForUnhandledTouchEvents);

    MainWindow w;
    w.showMaximized();
    return a.exec();
}
