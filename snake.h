#ifndef SNAKE_H
#define SNAKE_H
#include"snakepart.h"
#include<deque>

class Snake
{
public:
    Snake(int screenSize);
    ~Snake();

    const std::deque<SnakePart*>& getSnake();

    int getSize() const;

    void addTail(const QPoint &point);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    SnakePart* getHead() const;
    SnakePart* getTail() const;

    bool ateItself() const;

private:

    std::deque<SnakePart*> snake;
    int screenSize;
};


#endif // SNAKE_H
