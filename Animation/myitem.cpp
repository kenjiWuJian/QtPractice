#include "myitem.h"
#include <QDebug>

MyItem::MyItem()
{
    _angle = QRandomGenerator::global()->generate() % 360;
    setRotation(_angle);
    _speed = 5;
    int StartX = 0;
    int StartY = 0;
    if(QRandomGenerator::global()->generate()%2)
    {
        StartX = QRandomGenerator::global()->generate() % 200;
        StartY = QRandomGenerator::global()->generate() % 200;
        qDebug() << "pos" << StartX<<StartY;
    }
    else
    {
        StartX = QRandomGenerator::global()->generate() % 100;
        StartY = QRandomGenerator::global()->generate() % 100;
        qDebug() << "neg" << StartX<<StartY;
    }
    setPos(mapToParent(StartX,StartY));
}

QRectF MyItem::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush brush(Qt::gray);

    //basic collision detection
    if(scene()->collidingItems(this).isEmpty())
    {
        //no collision
        brush.setColor(Qt::green);
    }
    else
    {
        //collision
        brush.setColor(Qt::red);
        DoCollision();
    }
    painter->fillRect(rect,brush);
    painter->drawRect(rect);
}

void MyItem::advance(int phase)
{
    if(!phase) return;
    //QPointF location = this->pos();
    setPos(mapToParent(0,-_speed));
}

void MyItem::DoCollision()
{
    if(QRandomGenerator::global()->generate()%2)
    {
        setRotation(rotation() + 180 + QRandomGenerator::global()->generate()%10);
    }
    else
    {
        setRotation(rotation() + 180 + QRandomGenerator::global()->generate()%-10);
    }
    QPointF newPoint = mapToParent(-(boundingRect().width()),-(boundingRect().width()) +2);
    if(!scene()->sceneRect().contains(newPoint))
    {
        newPoint = mapToParent(0,0);
    }
    else
    {
        setPos(newPoint);
    }
}
