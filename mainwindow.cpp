#include "mainwindow.h"
#include "aiguille.h"
#include <cercle_widget.h>
#include <QVBoxLayout>
#include "Acceuil.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Acceuil *cx = new Acceuil(this);
    setCentralWidget(cx);



//    QVBoxLayout *lay = new QVBoxLayout;
//    cx->setLayout(lay);

//    Aiguille *aig = new Aiguille();
//    lay->addWidget(aig);

    cx->grabGesture(Qt::PanGesture);
    cx->grabGesture(Qt::SwipeGesture);
    cx->grabGesture(Qt::PinchGesture);
   // cx->grabGesture(Qt::TapGesture);
    cx->grabGesture(Qt::TapAndHoldGesture);
}


MainWindow::~MainWindow()
{

}
