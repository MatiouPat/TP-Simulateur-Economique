// Square.hpp
#pragma once

#include "SquareState.hpp"

/**
* Represente une case de la board 
*/
class Square
{

public:

    Square();
    Square(int _x, int _y, int _cost, int _heuristic, SquareState _state);
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

private:

    int x;
    int y;
    float cost;
    int heuristic;
    bool isVisited;
    SquareState state;

};
