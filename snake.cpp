#include "snake.h"
#include<unordered_set>
#include<QHash>

// 10 zameni sa mapsize
Snake::Snake(int screenSize) : screenSize(screenSize){
    for(int i=0; i<3; i++){
        SnakePart* part = new SnakePart(screenSize/2, screenSize/2 + i * screenSize/20);
        snake.push_back(part);
    }
}

Snake::~Snake() {
    for(auto part : snake){
        delete part;
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
    SnakePart *part = new SnakePart(headPoint.x() - screenSize/20, headPoint.y());
    snake.push_front(part);
    snake.pop_back();
}

void Snake::moveDown()
{
    QPoint headPoint = snake.front()->getCoordinates();
    SnakePart *part = new SnakePart(headPoint.x() + screenSize/20, headPoint.y());
    snake.push_front(part);
    snake.pop_back();
}

void Snake::moveLeft()
{
    QPoint headPoint = snake.front()->getCoordinates();
    SnakePart *part = new SnakePart(headPoint.x(), headPoint.y() - screenSize/20);
    snake.push_front(part);
    snake.pop_back();
}

void Snake::moveRight()
{
    QPoint headPoint = snake.front()->getCoordinates();
    SnakePart *part = new SnakePart(headPoint.x(), headPoint.y() + screenSize/20);
    snake.push_front(part);
    snake.pop_back();
}

SnakePart *Snake::getTail() const{
    return snake.back();
}


SnakePart *Snake::getHead() const{
    return snake.front();
}

// 10 zameni sa mapsize
struct QPointHash{
    int operator() (const QPoint &p) const{
        return qHash(p);
    }
};

bool Snake::ateItself() const{
    std::unordered_set<QPoint,  QPointHash> coordinates;
    for(auto *part : snake)
        coordinates.insert(part->getCoordinates());


    return getSize() != coordinates.size();
}


