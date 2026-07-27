#ifndef FRUIT_H
#define FRUIT_H
#include<QRandomGenerator>

class Fruit
{
public:
    Fruit();
    Fruit(int x, int y) : x(x), y(y) {}

    void spawn();

    void respawn();

    int getX() const;

    int getY() const;

private:
    int x;
    int y;
};

#endif // FRUIT_H
