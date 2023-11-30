// Square.hpp
#pragma once

#include <iostream>
#include "SquareState.hpp"
#include "Company.hpp"




/**
* Represente une case de la board 
*/
class Square
{

public:

    Square();
    Square(int _x, int _y);
    Square(int _x, int _y, float _cost, int _heuristic);
    Square(int _x, int _y, float _cost, int _heuristic, SquareState _state);
    ~Square();
    int getX();
    void setX(int _x);
    int getY();
    void setY(int _y);
    int getHeuristic();
    void setHeuristic(int _heuristic);
    float getCost();
    void setCost(float _cost);
    SquareState getState();
    void setState(SquareState _state);
    std::shared_ptr<Company> getCompany();
    void setCompany(std::shared_ptr<Company> c);
    bool isCompany();
    float getValue();
    void setValue(float);

private:

    int x;
    int y;
    float cost;
    int heuristic;
    SquareState state;
    float value;
    std::shared_ptr<Company> company;
};
