#include "Square.hpp"

Square::Square()
{
}

Square::Square(int _x, int _y, int _cost, int _heuristic, SquareState _state)
{
    x = _x;
    y = _y;
    cost = _cost;
    heuristic = _heuristic;
    state = _state;
}


Square::~Square()
{

}


int Square::getX()
{
    return x;
}


void Square::setX(int _x)
{
    x = _x;
}


int Square::getY()
{
    return y;
}


void Square::setY(int _y)
{
    y = _y;
}


int Square::getHeuristic()
{
    return heuristic;
}


void Square::setHeuristic(int _heuristic)
{
    heuristic = _heuristic;
}


float Square::getCost()
{
    return cost;
}


void Square::setCost(float _cost)
{
    cost = _cost;
}


SquareState Square::getState()
{
    return state;
}