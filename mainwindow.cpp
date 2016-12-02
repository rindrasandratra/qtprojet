#include "mainwindow.h"
#include <QVBoxLayout>
#include "Acceuil.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Acceuil *cx = new Acceuil(this);
    setCentralWidget(cx);
}


MainWindow::~MainWindow()
{

}
