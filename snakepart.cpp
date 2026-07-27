#include "snakepart.h"

SnakePart::SnakePart(int x, int y) : x(x),
    y(y)
{}

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
