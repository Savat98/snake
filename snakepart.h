#ifndef SNAKEPART_H
#define SNAKEPART_H

class SnakePart
{
public:
    SnakePart(int x, int y);

    int getX() const;

    int getY() const;

    void setCoordinates(int first, int second);

private:
    int x;
    int y;
};



#endif // SNAKEPART_H
