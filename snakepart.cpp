#include "snakepart.h"

SnakePart::SnakePart(int x, int y) : x(x),
    y(y)
{}

SnakePart::SnakePart(const QPoint &p){
    x = p.x();
    y = p.y();
}

int SnakePart::getX() const{
    return x;
}

int SnakePart::getY() const{
    return y;
}

void SnakePart::setCoordinates(int first, int second){
    x = first;
    y = second;
}

QPoint SnakePart::getCoordinates() const{
    return QPoint(x, y);
}
