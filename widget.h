#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"snake.h"
#include"fruit.h"
#include<iostream>

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

private:

    void print() const{
        //auto vektor = snake->getSnake();
        for(int i=0; i<12; i++){
            for(int j=0; j<12; j++){
                if(i == 0 | j == 0 || i == 11 | j == 11){
                    std::cout<<"*";
                }
                else{



                    bool upisan = false;

                    if(fruit != nullptr){
                        if(fruit->getX() == i && fruit->getY() == j){
                            upisan = true;
                            std::cout<<"x";
                        }
                    }

                    for(SnakePart* part : snake->getSnake()){
                        if(part->getX() == i && part->getY() == j){
                            upisan = true;
                            std::cout<<"o";
                        }
                    }
                    if(!upisan)
                        std::cout<<" ";
                }
            }
            std::cout<<std::endl;
        }

    }

    Fruit *fruit;
    Snake* snake;
    Ui::Widget *ui;
};
#endif // WIDGET_H
