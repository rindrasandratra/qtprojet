#include "cercle_widget.h"
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
    QGridLayout *layout = new QGridLayout(this);
    layout->setSpacing(0);


    aig = new QLabel;
    aig->setAlignment(Qt::AlignCenter);

    btn_rotate = new QPushButton("rotation");

    scene = new QGraphicsScene;
    qv = new QGraphicsView(scene);
    qDebug()<< "scene w : " << scene->width() << " h : " << scene->height();
    qv->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    qv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    qv->setSceneRect(0, 0, scene->width(), scene->height());
    qv->setStyleSheet( "QGraphicsView { border-style: none; }");
    c = new Cercle(0,0,qv->width());

    scene->addItem(c);


    double r = qv->width();
    double h = qv->height()/3;

    draw_aiguille(r,0,7,20);
    layout->addWidget(btn_rotate);
    layout->addWidget(aig,1,0);
    layout->addWidget(qv,2,0);

    duree = new QTime;
    connect(btn_rotate,SIGNAL(pressed()),this,SLOT(start_rotation()));
    connect(btn_rotate,SIGNAL(released()),this,SLOT(release_btn()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(anim_rotation()));

    this->setLayout(layout);
}


void Cercle_widget::draw_aiguille(int x, int y, int w, int h)
{
    int h_pix = h + w*2;
    QPixmap pix(w*3,h_pix);
    pix.fill(QColor(0,0,0,0));
    QPainter painter(&pix);

    painter.setPen(Qt::blue);
    painter.setBrush(Qt::blue);
    QRectF barre = QRectF(w/2,0,w,h);
    painter.drawRect(barre);

    QRectF fleche = QRectF(0, h, w*2, w*2);
    QPainterPath path;
    path.moveTo(fleche.left() + (fleche.width() / 2), fleche.bottom());
    path.lineTo(fleche.topRight());
    path.lineTo(fleche.topLeft());
    path.lineTo(fleche.left() + (fleche.width() / 2), fleche.bottom());
    painter.fillPath(path, QBrush(QColor ("blue")));
    aig->setPixmap(pix);
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
    qDebug() << "fin de la fonction";
    // question->setVisible(true);
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

void Cercle_widget::mousePressEvent ( QMouseEvent * event ){
    qDebug() << "niha";
}
void Cercle_widget::mouseReleaseEvent ( QMouseEvent * event ){
    qDebug() << "vfdk";
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
