#ifndef SNAKEBODYITEM_H
#define SNAKEBODYITEM_H
#include<QGraphicsRectItem>
#include<QPainter>

class SnakeBodyItem : public QGraphicsRectItem
{

public:
    SnakeBodyItem(int screenSize , QGraphicsItem *parent = nullptr) : QGraphicsRectItem(parent), screenSize(screenSize) {
        setRect(0, 0, screenSize/20.0, screenSize/20.0);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        painter->setPen(QPen(Qt::black, 2));
        painter->setBrush(Qt::red);

        painter->drawRect(rect());
    }

private:
    int screenSize;

};

#endif // SNAKEBODYITEM_H
