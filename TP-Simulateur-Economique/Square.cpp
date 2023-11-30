#include "Square.hpp"
#include "Company.hpp"
#include "SquareState.hpp"
#include <iostream>

Square::Square()
{
    company = std::make_shared<Company>();
}


Square::Square(int _x, int _y)
{
    x = _x;
    y = _y;
    company = std::make_shared<Company>();
    company = nullptr;
}

Square::Square(int _x, int _y, float _cost, int _heuristic)
{
    x = _x;
    y = _y;
    cost = _cost;
    heuristic = _heuristic;
    state = SquareState::UNKNOWN;
    company = std::make_shared<Company>();
    company = nullptr;

}

Square::Square(int _x, int _y, float _cost, int _heuristic, SquareState _state)
{
    x = _x;
    y = _y;
    cost = _cost;
    heuristic = _heuristic;
    state = _state;
    company = std::make_shared<Company>();
    company = nullptr;

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

void Square::setState(SquareState _state)
{
    state = _state;
}

void Square::setCompany(std::shared_ptr<Company> c)
{
    std::cout << "company" << std::endl;
    std::cout << (company == nullptr) << std::endl;
    company = c;
    std::cout << (company == nullptr) << std::endl;

}
bool Square::isCompany()
{
    if (company != nullptr)
    {
        return true;
    }
    return false;
}

float Square::getValue()
{
    return value;
}

void Square::setValue(float _value)
{
    value = _value;
}