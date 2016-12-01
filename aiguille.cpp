#include "aiguille.h"
#include <QDebug>
Aiguille::Aiguille( QWidget *parent) : QWidget(parent)
{
    qDebug() << "yeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeesssssssssssss";
}


void Aiguille::paintEvent(QPaintEvent *event){
    qDebug() << "ggggggggggggggggggggggggggggg";
//    QPainter paint (this);
//    paint.setPen(QPen(Qt::blue,5));
//    paint.setBrush(Qt::black);
//    paint.drawRect(x,y,w,h);

    /*QRect rectangle(10.0, 20.0, 80.0, 60.0);
            QPainter p;
            p.begin(this);
            p.drawRect(rectangle);
            p.end();
*/
    qDebug() << "nnnnnnnnnnnnooooooooooooooooooooonnnnnnnnnnnnnnn";
}


//    void Aiguille::tracer(){
//        qDebug() << "ggggggggggggggggggggggggggggg";
//        QPainter paint (this);
//        paint.setPen(QPen(Qt::blue,5));
//        paint.setBrush(Qt::black);
//        paint.drawRect(x,y,w,h);
//        qDebug() << "nnnnnnnnnnnnooooooooooooooooooooonnnnnnnnnnnnnnn";
//    }

