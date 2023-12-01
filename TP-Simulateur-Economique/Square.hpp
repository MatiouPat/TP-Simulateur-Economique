// Square.hpp
#pragma once

#include <iostream>
#include "SquareState.hpp"
#include "Company.hpp"
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
    int getX() const;
    void setX(int _x);
    int getY() const;
    void setY(int _y);
    int getHeuristic() const;
    void setHeuristic(int _heuristic);
    float getCost() const;
    void setCost(float _cost);
    SquareState getState() const;
    void setState(SquareState _state);
    std::shared_ptr<Company> getCompany() const;
    void setCompany(std::shared_ptr<Company> c);
    bool isCompany() const;
    float getValue() const;
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
