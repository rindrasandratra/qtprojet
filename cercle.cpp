#include "cercle.h"
#include <QPainter>
#include <QPixmap>
#include <QColor>
#include <QPainterPath>
#include <QRectF>
#include <ctime>
#include <QDebug>
Cercle::Cercle()
{

}
Cercle::Cercle(double x, double y, double r)
{
    this->x = x;
    this->y = y;
    this->r = r;
    center_x = r/2;
    center_y = r/2;
    angle_rotation = 0;

    srand(time(0));
    draw_cercle();
}

void Cercle::draw_cercle(){
    QPixmap *pix;
    pix = new QPixmap(r,r);
    pix->fill(QColor(144,44,0));
    //pix->fill(QColor(0,0,0,0));
    painter =  new QPainter(pix);

    painter->setRenderHint(QPainter::Antialiasing, true);

    QRectF rect(0,0,r,r);
    int nb_section = 5;
    int spanAngle = (360/nb_section) * 16;
    int startAngle = 0;
    painter->setPen(QPen(Qt::white,5));

    for (int i=1; i<=nb_section; i++)
    {
        painter->setBrush(QColor(rand()%255,rand()%255,rand()%255));
        painter->drawPie(rect, startAngle, spanAngle);
        startAngle += spanAngle;
    }

    startAngle = 0;

    for (int i=1; i<=nb_section; i++)
    {
        float deg_texte_deg = (startAngle + spanAngle/2) / 16;
        float deg_texte = deg_texte_deg * PI / 180.0;
        float x_text = (r/3)*cos(deg_texte) + center_x;
        float y_text = (r/3)*sin(deg_texte) + center_y;

        float dim = r/35.0;
        painter->setPen(QPen(Qt::white));
        painter->setBrush(Qt::white);
        painter->drawEllipse(QPointF(x_text+2,y_text-2),dim,dim);

        painter->setPen(QPen(Qt::black));
        painter->drawText(x_text,y_text,QString::number(i));

        startAngle += spanAngle;
    }

    setTransformOriginPoint(center_x,center_y);

    setPixmap(*pix);
}

void Cercle::rotation_anim(){
    angle_rotation += 10;
    setRotation(angle_rotation);
}

bool Cercle::event(QEvent *event)
{
    qDebug() << "event";
    if (event->type() == QEvent::Gesture)
        return gestureEvent(static_cast<QGestureEvent*>(event));
    return Cercle::event(event);
}

bool Cercle::gestureEvent(QGestureEvent *event)
{

    qDebug() << "gest event";
    if (QGesture *pan = event->gesture(Qt::PanGesture))
        panTriggered(static_cast<QPanGesture *>(pan));
    return true;
}

void Cercle::panTriggered(QPanGesture*)
{
    qDebug() << "paaaaaaaaaaaaaaaaan";
}


int Cercle::getAngle()
{
    if (angle_rotation <= 360) return angle_rotation;
    else
    {
        int mult = angle_rotation/360;
        //qDebug() << mult;
        //qDebug() << angle_rotation;
        angle_rotation = angle_rotation - mult*360;
        return angle_rotation;
    }
}
