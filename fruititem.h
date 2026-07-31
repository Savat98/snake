#ifndef FRUITITEM_H
#define FRUITITEM_H
#include<QGraphicsEllipseItem>
#include<QPainter>

class FruitItem : public QGraphicsEllipseItem
{
public:
    FruitItem(int screenSize) : screenSize(screenSize) {
        setRect(0, 0, screenSize/20.0, screenSize/20.0);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        painter->setPen(QPen(Qt::black, 2));
        painter->setBrush(Qt::blue);

        painter->drawEllipse(rect());
    }

private:
    int screenSize;
};

#endif // FRUITITEM_H
