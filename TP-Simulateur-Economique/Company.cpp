// Company.hpp

#include "Company.hpp"



Company::Company()
{
}

Company::Company(std::string name, unsigned int niveau, double capital, Square position, std::vector<Employee> listEmployee, std::map<int, Merchandise> stock)
{
}

Company::~Company()
{
}

std::string Company::getName()
{
    return name;
}

int Company::getPositionX()
{
    return position.getX();
}

int Company::getPositionY()
{
    return position.getY();
}