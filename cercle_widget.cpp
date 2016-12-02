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

    scene = new QGraphicsScene;
    qv = new QGraphicsView(scene);
    qv->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    qv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    qv->setStyleSheet( "QGraphicsView { border-style: none; }");
    c = new Cercle(0,0,qv->width());
    scene->addItem(c);
    qv->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QRect rec = QApplication::desktop()->availableGeometry();
    double r = qv->width();
    double h = qv->height()/3;
    if (rec.width() < rec.height())
        draw_aiguille(r,0,7,h);
    else
        draw_aiguille(r,0,7,20);
    layout->addWidget(aig,1,0);
    layout->addWidget(qv,2,0);

    duree = new QTime;

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


void Cercle_widget::mousePressEvent ( QMouseEvent * event ){
    this->grabMouse();
    duree->start();
}
void Cercle_widget::mouseReleaseEvent ( QMouseEvent * event ){
    this->releaseMouse();
    release_btn();
}

void Cercle_widget::release_btn(){
    timer->stop();
    int d =duree->elapsed() ;
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

void Cercle_widget::stop_rotation(){
    timer->stop();
    affiche_question();
}


void Cercle_widget::affiche_question(){
    int i = ceil(c->getAngle()/72.0);
    Question *question = new Question(i);
    question->setModal(true);
    question->showMaximized();
    connect(question,SIGNAL(game_over()),this,SLOT(close()));
}


int Cercle_widget::getAngle(){
    return c->getAngle();
}
