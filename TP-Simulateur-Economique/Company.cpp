// Company.hpp

#include "Company.hpp"



Company::Company()
{
}

Company::Company(std::string _name, unsigned int _niveau, double _capital, Square _position, std::vector<Employee> _listEmployee, std::map<Merchandise, int> _stock, std::map<Merchandise, int> _stockMax, std::vector<Merchandise> _entrant, std::vector<Merchandise> _sortant, unsigned int coutProd)
{
    name = _name;
    niveau = _niveau;
    capital = _capital;
    position = _position;
    listEmployee = _listEmployee;
    stock = _stock;
    stockMax = _stockMax;
    sortant = _sortant;
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
