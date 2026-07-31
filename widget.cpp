#include "widget.h"
#include "./ui_widget.h"
#include<QMessageBox>
#include<QKeyEvent>
#include<QPushButton>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);


    scene = new QGraphicsScene(this);
    view = ui->graphicsView;
    scene->setSceneRect(0, 0, screenSize, screenSize);
    view->setFixedWidth(screenSize + 2);
    view->setFixedHeight(screenSize + 2);
    setFixedWidth(screenSize + 20);
    setFixedHeight(screenSize + 20);
    view->setScene(scene);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::move);
    timer->start(1000/gameSpeed);
    initGame();


}

Widget::~Widget()
{
    delete ui;
}


void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
        case Qt::Key_W : {
            if(direction != Dirrection::DOWN)
                direction = Dirrection::UP;
            break;
        }
        case Qt::Key_A : {
            if(direction != Dirrection::RIGHT)
                direction = Dirrection::LEFT;
            break;
        }
        case Qt::Key_S : {
            if(direction != Dirrection::UP)
                direction = Dirrection::DOWN;
            break;
        }
        case Qt::Key_D : {
            if(direction != Dirrection::LEFT)
                direction = Dirrection::RIGHT;
            break;
        }
    }
}

void Widget::exit()
{
    clearMemory();
    this->close();
}

void Widget::restart(){
    clearMemory();
    initGame();
}

void Widget::clearMemory()
{
    delete snake;
    snake = nullptr;
    delete fruit;
    fruit = nullptr;
    qDeleteAll(bodyItems);
    bodyItems.clear();
    delete fruitItem;
}

bool Widget::fruitSpawnedOnSnake() const
{
    auto snakeParts = snake->getSnake();
    for(auto part: snakeParts){
        if(part->getX() == fruit->getX() && part->getY() == fruit->getY())
            return true;
    }
    return false;
}

bool Widget::hitWall() const
{
    auto headCoordinates = snake->getHead()->getCoordinates();
    if(screenSize <= headCoordinates.x() || screenSize <= headCoordinates.y() || headCoordinates.x() < 0 || headCoordinates.y() < 0)
        return true;
    return false;
}

void Widget::initGame()
{
    snake = new Snake(screenSize);
    fruit = new Fruit(screenSize);
    while(fruitSpawnedOnSnake())
        fruit->respawn();
    fruitItem = new FruitItem(screenSize);
    fruitItem->setPos(fruit->getY(), fruit->getX());
    scene->addItem(fruitItem);


    auto parts = snake->getSnake();
    for(auto part: parts){
        SnakeBodyItem* item = new SnakeBodyItem(screenSize);
        bodyItems.push_back(item);
        item->setPos(part->getY(), part->getX());
        scene->addItem(item);
    }
}

void Widget::gameOver()
{
    QMessageBox message(this);
    message.setText("Game Over");
    QPushButton *exitButton = new QPushButton("Exit");
    QPushButton *restartButton = new QPushButton("Restart");
    connect(exitButton, &QPushButton::clicked, this, exit);
    connect(restartButton, &QPushButton::clicked, this, restart);
    message.addButton(exitButton, QMessageBox::RejectRole);
    message.addButton(restartButton, QMessageBox::ActionRole);
    message.exec();
}

void Widget::updateSnake()
{
    if(snake->ateItself() || hitWall())
        gameOver();
    auto parts = snake->getSnake();
    int n = parts.size();
    for(int i = 0; i < n; i++){
        bodyItems[i]->setPos(parts[i]->getY(), parts[i]->getX());
    }
}

void Widget::move()
{
    QPoint prevTail = snake->getTail()->getCoordinates();
    switch(direction){
        case Dirrection::UP : {
            snake->moveUp();
            break;
        }
        case Dirrection::DOWN : {
            snake->moveDown();
            break;
        }
        case Dirrection::RIGHT : {
            snake->moveRight();
            break;
        }
        case Dirrection::LEFT : {
            snake->moveLeft();
            break;
        }
    }
    auto head = snake->getHead();
    if(head->getX() == fruit->getX() && head->getY() == fruit->getY()){
        addTail(prevTail);
        respawnFruit();
    }
    updateSnake();
}

void Widget::moveUp()
{
    QPoint prevTail = snake->getTail()->getCoordinates();
    snake->moveUp();
    auto head = snake->getHead();
    if(head->getX() == fruit->getX() && head->getY() == fruit->getY()){
        addTail(prevTail);
        respawnFruit();
    }
    updateSnake();
}

void Widget::moveDown()
{
    QPoint prevTail = snake->getTail()->getCoordinates();
    snake->moveDown();
    auto head = snake->getHead();
    if(head->getX() == fruit->getX() && head->getY() == fruit->getY()){
        addTail(prevTail);
        respawnFruit();
    }
    updateSnake();
}

void Widget::moveLeft()
{
    QPoint prevTail = snake->getTail()->getCoordinates();
    snake->moveLeft();
    auto head = snake->getHead();
    if(head->getX() == fruit->getX() && head->getY() == fruit->getY()){
        addTail(prevTail);
        respawnFruit();
    }
    updateSnake();
}

void Widget::moveRight()
{
    QPoint prevTail = snake->getTail()->getCoordinates();
    snake->moveRight();
    auto head = snake->getHead();
    if(head->getX() == fruit->getX() && head->getY() == fruit->getY()){
        addTail(prevTail);
        respawnFruit();
    }
    updateSnake();
}


void Widget::respawnFruit() {
    fruit->respawn();
    while(fruitSpawnedOnSnake())
        fruit->respawn();
    fruitItem->setPos(fruit->getY(), fruit->getX());
}

void Widget::addTail(QPoint p){
    snake->addTail(p);
    SnakeBodyItem *item = new SnakeBodyItem(screenSize);
    item->setPos(p.y(), p.x());
    bodyItems.push_back(item);
    scene->addItem(item);
}
