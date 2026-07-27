#include "snake.h"
#include<unordered_set>


// 10 zameni sa mapsize
Snake::Snake(){
    for(int i=0; i<3; i++){
        SnakePart* part = new SnakePart(10/2, 10/2 + i);
        snake.push_back(part);
    }
}

const std::deque<SnakePart *> &Snake::getSnake() {
    return snake;
}

int Snake::getSize() const{
    return snake.size();
}

void Snake::addTail(const QPoint& point){
    SnakePart* part = new SnakePart(point);
    snake.push_back(part);
}

void Snake::moveUp() {
    QPoint headPoint = snake.front()->getCoordinates();
    SnakePart *part = new SnakePart(headPoint.x() - 1, headPoint.y());
    snake.push_front(part);
    snake.pop_back();
}

void Snake::moveDown()
{
    QPoint headPoint = snake.front()->getCoordinates();
    SnakePart *part = new SnakePart(headPoint.x() + 1, headPoint.y());
    snake.push_front(part);
    snake.pop_back();
}

void Snake::moveLeft()
{
    QPoint headPoint = snake.front()->getCoordinates();
    SnakePart *part = new SnakePart(headPoint.x(), headPoint.y() - 1);
    snake.push_front(part);
    snake.pop_back();
}

void Snake::moveRight()
{
    QPoint headPoint = snake.front()->getCoordinates();
    SnakePart *part = new SnakePart(headPoint.x(), headPoint.y() + 1);
    snake.push_front(part);
    snake.pop_back();
}

void Snake::eatRight(){

    QPoint headPoint = snake.front()->getCoordinates();
    snake.push_front(new SnakePart(headPoint.x(), headPoint.y() + 1));
}

void Snake::eatLeft()
{
    QPoint headPoint = snake.front()->getCoordinates();
    snake.push_front(new SnakePart(headPoint.x(), headPoint.y() - 1));

}

void Snake::eatUp()
{
    QPoint headPoint = snake.front()->getCoordinates();
    snake.push_front(new SnakePart(headPoint.x() - 1, headPoint.y()));

}

void Snake::eatDown()
{
    QPoint headPoint = snake.front()->getCoordinates();
    snake.push_front(new SnakePart(headPoint.x() + 1, headPoint.y()));

}

// 10 zameni sa mapsize
struct QPointHash{
    int operator() (const QPoint &p1) const{
        return p1.x() * 10 + p1.y();
    }
};

bool Snake::ateItself() const{
    std::unordered_set<QPoint, QPointHash> coordinates;
    for(auto *part : snake)
        coordinates.insert(part->getCoordinates());


    return getSize() != coordinates.size();
}


