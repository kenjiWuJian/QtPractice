#ifndef MYITEM_H
#define MYITEM_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QRandomGenerator>

class MyItem:public QGraphicsItem
{
public:
    MyItem();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
protected:
    void advance(int phase) override;
private:
    qreal _angle;
    qreal _speed;
    void DoCollision();
};

#endif // MYITEM_H
