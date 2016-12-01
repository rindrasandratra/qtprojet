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
    QPushButton *btn_rotate;
    QGraphicsScene *scene;
    QGraphicsView *qv;
    QTime *duree;
    QTimer *timer;
    Cercle_widget *cw;
    int speed;

public:
    explicit Cercle_widget(QWidget *parent = 0);
    void define_speed(int);
    int getAngle();
    void plus_un_point();
    void avancer_parti();

signals:

public slots:
    void start_rotation();
    void release_btn();
    void anim_rotation();
    void stop_rotation();
    void update_interval();

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;

private:
    bool gestureEvent(QGestureEvent *event);
    void affiche_question();

    int score; //nombre de réponses justes du joueur
};

#endif // CERCLE_WIDGET_H
