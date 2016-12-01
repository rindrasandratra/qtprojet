#ifndef CERCLE_WIDGET_H
#define CERCLE_WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <cercle.h>
#include <QGraphicsScene>
#include <QTime>
#include <QTimer>
#include "Question.h"


class Cercle_widget : public QWidget
{
    Q_OBJECT
    Cercle *c;
    QGraphicsScene *scene;
    QGraphicsView *qv;
    QTime *duree;
    QTimer *timer;
    QLabel *aig;
    int speed;

public:
    explicit Cercle_widget(QWidget *parent = 0);
    void define_speed(int);
    int getAngle();
    void draw_aiguille(int x, int y, int w, int h);
    void release_btn();

signals:

public slots:
    void anim_rotation();
    void stop_rotation();
    void update_interval();

protected:
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    void affiche_question();
};

#endif // CERCLE_WIDGET_H
