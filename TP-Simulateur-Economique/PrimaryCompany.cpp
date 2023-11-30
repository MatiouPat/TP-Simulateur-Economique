#include "PrimaryCompany.hpp"

PrimaryCompany::PrimaryCompany()
{
}

PrimaryCompany::PrimaryCompany(std::string _name, unsigned int _niveau, double _capital, std::vector<Employee> _listEmployee, std::map<int, Merchandise> _stock)
	: Company(_name, _niveau, _capital, _listEmployee, _stock)
{
}

void PrimaryCompany::create()
{
}
