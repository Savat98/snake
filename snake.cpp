#include "snake.h"

Snake::Snake(){
    for(int i=0; i<3; i++){
        SnakePart* part = new SnakePart(10/2, 10/2 + i);
        snake.append(part);
    }
}

const QVector<SnakePart *> &Snake::getSnake() {
    return snake;
}

int Snake::getSize() const{
    return snake.length();
}

void Snake::moveAlong(int prevX, int prevY){
    int n = getSize();
    for(int i=1; i < n; i++){
        int xTmp = snake[i]->getX();
        int yTmp = snake[i]->getY();
        snake[i]->setCoordinates(prevX, prevY);
        prevX = xTmp;
        prevY = yTmp;
    }
}

void Snake::addTail(int tailX, int tailY){
    SnakePart* part = new SnakePart(tailX, tailY);
    snake.append(part);
}

void Snake::moveUp() {
    int prevX = snake[0]->getX();
    int prevY = snake[0]->getY();

    snake[0]->setCoordinates(snake[0]->getX() - 1, snake[0]->getY());

    moveAlong(prevX, prevY);
}

void Snake::moveDown()
{
    int prevX = snake[0]->getX();
    int prevY = snake[0]->getY();

    snake[0]->setCoordinates(snake[0]->getX() + 1, snake[0]->getY());

    moveAlong(prevX, prevY);
}

void Snake::moveLeft()
{
    int prevX = snake[0]->getX();
    int prevY = snake[0]->getY();

    snake[0]->setCoordinates(snake[0]->getX(), snake[0]->getY() - 1);

    moveAlong(prevX, prevY);
}

void Snake::moveRight()
{
    int prevX = snake[0]->getX();
    int prevY = snake[0]->getY();

    snake[0]->setCoordinates(snake[0]->getX(), snake[0]->getY() + 1);

    moveAlong(prevX, prevY);
}

void Snake::eatRight(){
    int size = getSize();
    int tailX = snake[size - 1]->getX();
    int tailY = snake[size - 1]->getY();

    moveRight();
    addTail(tailX, tailY);

}

void Snake::eatLeft()
{
    int size = getSize();
    int tailX = snake[size - 1]->getX();
    int tailY = snake[size - 1]->getY();

    moveLeft();
    addTail(tailX, tailY);

}

void Snake::eatUp()
{
    int size = getSize();
    int tailX = snake[size - 1]->getX();
    int tailY = snake[size - 1]->getY();

    moveUp();
    addTail(tailX, tailY);

}

void Snake::eatDown()
{
    int size = getSize();
    int tailX = snake[size - 1]->getX();
    int tailY = snake[size - 1]->getY();

    moveDown();
    addTail(tailX, tailY);

}


