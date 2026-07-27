#ifndef SNAKE_H
#define SNAKE_H
#include"snakepart.h"
#include<deque>

class Snake
{
public:
    Snake();

    const std::deque<SnakePart*>& getSnake();

    int getSize() const;

    void addTail(const QPoint &point);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void eatRight();
    void eatLeft();
    void eatUp();
    void eatDown();

    bool ateItself() const;

private:
    std::deque<SnakePart*> snake;
};


#endif // SNAKE_H
