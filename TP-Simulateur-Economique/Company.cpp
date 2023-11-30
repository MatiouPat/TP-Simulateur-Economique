// Company.hpp

#include "Company.hpp"
#include <string>
#include <vector>
#include <map>
#include "Employee.hpp"
#include "Merchandise.hpp"


Company::Company()
{
}

Company::Company(std::string _name, unsigned int _niveau, double _capital, std::vector<Employee> _listEmployee, std::map<int, Merchandise> _stock)
{
    name = _name;
    niveau = _niveau;
    capital = _capital;
    listEmployee = _listEmployee;
    stock = _stock;
}

Company::~Company()
{
}



