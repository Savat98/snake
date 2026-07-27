#ifndef SNAKEPART_H
#define SNAKEPART_H
#include<QPoint>

class SnakePart
{
public:
    SnakePart(int x, int y);
    SnakePart(const QPoint &p);

    int getX() const;

    int getY() const;

    void setCoordinates(int first, int second);

    QPoint getCoordinates() const;

private:
    int x;
    int y;
};



#endif // SNAKEPART_H
