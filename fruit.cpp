#include "fruit.h"

Fruit::Fruit() {
    spawn();
}

void Fruit::spawn() {
    x =QRandomGenerator::global()->bounded(0, 10);
    y =QRandomGenerator::global()->bounded(0, 10);
}

void Fruit::respawn() {
    int prevX = x;
    int prevY = y;

    do {
        spawn();
    }while(x == prevX && y == prevY);
}

int Fruit::getX() const{
    return x;
}

int Fruit::getY() const{
    return y;
}
