#ifndef CERCLE_H
#define CERCLE_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QWidget>
#include <QPanGesture>

class Cercle : public QGraphicsPixmapItem
{
private:
    const double PI = 2*acos(0.0);
    int center_x, center_y, angle_rotation;
    double x,y,r;
    QPainter *painter;
public:
    Cercle();
    Cercle(double, double, double);
    void draw_cercle();
    void rotation_anim();
    int getAngle();
};

#endif // CERCLE_H
