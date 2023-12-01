// Company.hpp

#include "Company.hpp"
#include <string>
#include <vector>
#include <map>
#include "Employee.hpp"
#include "Merchandise.hpp"
#include "Production.hpp"


Company::Company()
{
    name = "";
    level = 1;
    capital = 0.0f;
    listEmployee = std::vector<Employee>();
    stock = std::map<Merchandise, int>();
}

Company::Company(std::string _name, unsigned int _level, double _capital, std::vector<Employee> _listEmployee, std::map<Merchandise, int> _stock, std::map<Merchandise, int> _stockMax)
{
    name = _name;
    level = _level;
    capital = _capital;
    listEmployee = _listEmployee;
    stock = _stock;
    stockMax = _stockMax;
}

Company::~Company()
{
}

void Company::addEmployee(Employee _employee)
{
}

void Company::levelUp()
{
    level++;
}
