#ifndef SNAKE_H
#define SNAKE_H
#include"snakepart.h"
#include<QVector>

class Snake
{
public:
    Snake();

    const QVector<SnakePart*>& getSnake();

    int getSize() const;

    void moveAlong(int prevX, int prevY);
    void addTail(int tailX,int tailY);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void eatRight();
    void eatLeft();
    void eatUp();
    void eatDown();

private:
    QVector<SnakePart*> snake;
};

#endif // SNAKE_H
