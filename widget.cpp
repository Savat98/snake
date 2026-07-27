#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);
    snake = new Snake();
    fruit = new Fruit(6, 2);

    print();
    std::cout<<std::endl<<std::endl;

    snake->moveLeft();
    print();
    std::cout<<std::endl<<std::endl;

    snake->moveLeft();
    print();
    std::cout<<std::endl<<std::endl;

    snake->moveLeft();
    print();
    std::cout<<std::endl<<std::endl;

    snake->eatDown();
    fruit = nullptr;
    print();
    std::cout<<std::endl<<std::endl;



}

Widget::~Widget()
{
    delete ui;
}
