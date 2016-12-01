#include "cercle_widget.h"
#include "aiguille.h"
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>
#include "Question.h"
#include "score.h"


Cercle_widget::Cercle_widget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *lay = new QVBoxLayout;
    this->setLayout(lay);


    Aiguille *aigue = new Aiguille();

    lay->addWidget(aigue);

    btn_rotate = new QPushButton("rotation");
    lay->addWidget(btn_rotate);

    scene = new QGraphicsScene(this);

    qv = new QGraphicsView(scene);
    qv->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    qv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    qv->setSceneRect(0, 0, scene->width(), scene->height());
    c = new Cercle(0,0,qv->width());

    scene->addItem(c);

    double r = scene->width() * 3 /2;
    double h = scene->height();

    lay->addWidget(qv);
    //aigue->raise();
    //aigue->tracer();

    duree = new QTime;
    connect(btn_rotate,SIGNAL(pressed()),this,SLOT(start_rotation()));
    connect(btn_rotate,SIGNAL(released()),this,SLOT(release_btn()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(anim_rotation()));
}

void Cercle_widget::anim_rotation(){
    c->rotation_anim();
}

void Cercle_widget::start_rotation(){
    btn_rotate->setText("attente appui");
    duree->start();
}

void Cercle_widget::release_btn(){
    timer->stop();
    int d =duree->elapsed() ;
    btn_rotate->setText("Duree rotation : "+QString::number(d));
    qDebug() << "Duree rotation" << duree->elapsed() << "milliseconds";
    speed = 10;
    timer->start(speed);
    define_speed(d);
    QTimer::singleShot(d, this, SLOT(stop_rotation()));
}

void Cercle_widget::define_speed(int d){
    for (int i = 5; i > 0; i--)
    {
        QTimer::singleShot(d/i, this, SLOT(update_interval()));
        speed = speed +5;
    }
}

void  Cercle_widget::update_interval()
{
    timer->setInterval(speed);
}


void Cercle_widget::affiche_question(){

    int i = 1;
    if (c->getAngle() < 72) i =1;
    else if (c->getAngle() < 144) i = 2;
    else if (c->getAngle() < 216) i = 3;
    else if (c->getAngle() < 288) i = 4;
    else if (c->getAngle() < 360) i = 5;
    //qDebug() << i;
    Question *question = new Question(i);
    question->setModal(true);
    //question->setSizePolicy(QSizePolicy::Maximum);
    question->showMaximized();
    if (question->getTour() ==1)
    {
        if (question->getReponse() == 1) plus_un_point();
    }
    qDebug() << "fin de la fonction";
   // question->setVisible(true);
}

void Cercle_widget::plus_un_point()
{
    score += 1;
    qDebug() <<"le score est de " << score << "/10";
}



void Cercle_widget::stop_rotation(){
    qDebug() << "fini";
    timer->stop();
    affiche_question();
}
bool Cercle_widget::event(QEvent *event)
{
    if (event->type() == QEvent::Gesture)
        return gestureEvent(static_cast<QGestureEvent*>(event));
    return QWidget::event(event);
}

bool Cercle_widget::gestureEvent(QGestureEvent *event){

    qDebug() << "gestureEvent():" << event;
//    if (QGesture *swipe = event->gesture(Qt::SwipeGesture))
//    {
//         qDebug() << "SwipeGesture";
//         return true;
//    }
//    if (QGesture *pan = event->gesture(Qt::PanGesture))
//    {
//        qDebug() << "PanGesture";
//        return true;
//    }
//    if (QGesture *pinch = event->gesture(Qt::PinchGesture))
//    {
//        qDebug() << "PinchGesture";
//        return true;
//    }
//    if (QGesture *tap = event->gesture(Qt::TapGesture))
//    {
//        qDebug() << "TapGesture";
//        return true;
//    }
//    if (QGesture *taphold = event->gesture(Qt::TapAndHoldGesture))
//    {
//        qDebug() << "TapAndHoldGesture";
//        return true;
//    }
}

int Cercle_widget::getAngle(){
    return c->getAngle();
}
