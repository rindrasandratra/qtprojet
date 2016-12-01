#include "Acceuil.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include "cercle_widget.h"
#include <QPalette>
#include <QSize>


Acceuil::Acceuil(QWidget *parent) : QWidget(parent)
{
    QLabel *espace = new QLabel("\n\n\n");
    espace->setMaximumHeight(50);
    espace->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QLabel  *label_img  = new QLabel(this);
    QPixmap *pixmap_img = new QPixmap(":/ressource/images.jpeg");
    label_img->setPixmap(*pixmap_img);
    label_img->setAlignment(Qt::AlignCenter);
    label_img->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


    demarer = new QPushButton("Démarrer la partie");

    QFont font = demarer->font();

    font.setBold(1);

    QPalette palette;
    palette.setColor(QPalette::Button, QColor(194,22,22));
    palette.setColor(QPalette::ButtonText, Qt::white);
    demarer->setPalette(palette);
    demarer->setFont(font);
    demarer->setMaximumHeight(75);
    demarer->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(demarer);
    lay->addWidget(label_img);
    QLabel *copyright = new QLabel("Réalisé par :\nFavre Clément\nRamanamahefa Rindra");
    copyright->setAlignment(Qt::AlignCenter);


    lay->addWidget(espace);
    lay->addWidget(copyright);
    lay->setAlignment(Qt::AlignCenter);

    setLayout(lay);

    Cercle_widget *game = new Cercle_widget;
    connect(demarer,SIGNAL(clicked()),this->window(),SLOT(close()));
    connect(demarer,SIGNAL(clicked()),game,SLOT(showMaximized()));
}
