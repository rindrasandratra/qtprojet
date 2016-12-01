#ifndef AIGUILLE_H
#define AIGUILLE_H

#include <QWidget>
#include <QPainter>

class Aiguille : public QWidget
{
    Q_OBJECT
    double x,y,w,h;
public:
    explicit Aiguille(QWidget *parent = 0);
    void tracer();

protected:
    void paintEvent(QPaintEvent *e);

private :

signals:

public slots:
};

#endif // AIGUILLE_H
