#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"snake.h"
#include"fruit.h"
#include<QGraphicsScene>
#include<iostream>
#include<QVector>
#include"snakebodyitem.h"
#include"fruititem.h"
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void onUpArrow();
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void exit();
    void restart();
    void clearMemory();
    void move();

private:
    enum class Dirrection{
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    bool fruitSpawnedOnSnake() const;
    bool hitWall() const;
    void initGame();
    void gameOver();
    void updateSnake();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void respawnFruit();
    void addTail(QPoint p);


    int gameSpeed = 8;
    Dirrection direction = Dirrection::LEFT;
    int screenSize = 500;
    FruitItem *fruitItem;
    QVector<SnakeBodyItem*> bodyItems;
    QGraphicsScene *scene;
    QGraphicsView *view;
    Fruit *fruit;
    Snake* snake;
    QTimer *timer;
    Ui::Widget *ui;
};
#endif // WIDGET_H
