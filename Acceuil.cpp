#include "Acceuil.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include "cercle_widget.h"



Acceuil::Acceuil(QWidget *parent) : QWidget(parent)
{
    QLabel  *label_img  = new QLabel(this);
    QPixmap *pixmap_img = new QPixmap(":/ressource/images.jpeg");
    label_img->setPixmap(*pixmap_img);
    label_img->setAlignment(Qt::AlignCenter);


    demarer = new QPushButton("démarrer la partie");

    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(demarer);
    lay->addWidget(label_img);
    lay->addWidget(new QLabel("Réalisr par :\nFavre Clément\nRamanamahefa Rindra"));
    lay->setAlignment(Qt::AlignCenter);

    setLayout(lay);


    connect(demarer,SIGNAL(clicked()),this,SLOT(slotDemarer()));
}



void Acceuil::slotDemarer()
{
    Cercle_widget game;
    game.show();
}
