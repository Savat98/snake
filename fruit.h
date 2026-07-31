#ifndef FRUIT_H
#define FRUIT_H
#include<QRandomGenerator>

class Fruit
{
public:
    Fruit(int screenSize);

    void spawn();

    void respawn();

    int getX() const;

    int getY() const;

private:
    int screenSize;
    int x;
    int y;
};

#endif // FRUIT_H
