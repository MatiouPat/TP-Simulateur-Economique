#include "Square.hpp"
#include "Company.hpp"
#include "SquareState.hpp"
#include <iostream>

Square::Square()
{
    company = nullptr;
}


Square::Square(int _x, int _y)
{
    x = _x;
    y = _y;
    company = nullptr;
}

Square::Square(int _x, int _y, float _cost, int _heuristic)
{
    x = _x;
    y = _y;
    cost = _cost;
    heuristic = _heuristic;
    state = SquareState::UNKNOWN;
    company = nullptr;

}

Square::Square(int _x, int _y, float _cost, int _heuristic, SquareState _state)
{
    x = _x;
    y = _y;
    cost = _cost;
    heuristic = _heuristic;
    state = _state;
    company = nullptr;

}

Square::~Square()
{

}


int Square::getX() const
{
    return x;
}


void Square::setX(int _x)
{
    x = _x;
}


int Square::getY() const
{
    return y;
}


void Square::setY(int _y) 
{
    y = _y;
}


int Square::getHeuristic() const 
{
    return heuristic;
}


void Square::setHeuristic(int _heuristic)
{
    heuristic = _heuristic;
}


float Square::getCost() const
{
    return cost;
}


void Square::setCost(float _cost)
{
    cost = _cost;
}


SquareState Square::getState() const
{
    return state;
}

void Square::setState(SquareState _state)
{
    state = _state;
}

std::shared_ptr<Company> Square::getCompany() const
{
    return company;
}

void Square::setCompany(std::shared_ptr<Company> c)
{
    company = c;
}
bool Square::isCompany() const
{
    if (company != nullptr)
    {
        return true;
    }
    return false;
}

float Square::getValue() const
{
    return value;
}

void Square::setValue(float _value)
{
    value = _value;
}