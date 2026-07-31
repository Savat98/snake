#include "fruit.h"
#include<QDebug>

Fruit::Fruit(int screenSize) : screenSize(screenSize){
    spawn();
}


void Fruit::spawn() {
    x =QRandomGenerator::global()->bounded(0, 20) * screenSize / 20 ;
    y =QRandomGenerator::global()->bounded(0, 20) * screenSize / 20;
    if(x > 500 || y > 500||x < 0 || y < 0){
        qDebug()<<"spawn bug";
    }
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
