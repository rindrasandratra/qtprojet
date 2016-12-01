#include "Acceuil.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "cercle_widget.h"



Acceuil::Acceuil(QWidget *parent) : QWidget(parent)
{
    QLabel  *label_img  = new QLabel(this);
    QPixmap *pixmap_img = new QPixmap(":/images.jpg");
    label_img->setPixmap(*pixmap_img);
    demarer = new QPushButton("démarrer la partie");

    QVBoxLayout lay = new QVBoxLayout;
    lay->addwidget(label_img);
    lay->addwidget(demarrer);
    setLayout(lay);


    connect(demarer,SIGNAL(clicked()),this,SLOT(slotDemarer()));
}



void Acceuil::slotDemarer()
{
    Cercle_widget game = new Cercle_Widget();
}
