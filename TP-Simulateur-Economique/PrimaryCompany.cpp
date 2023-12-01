#include "PrimaryCompany.hpp"

PrimaryCompany::PrimaryCompany()
{
}

PrimaryCompany::PrimaryCompany(std::string _name, unsigned int _level, double _capital, std::vector<Employee> _listEmployee, std::map<Merchandise, int> _stock)
	: Company(_name, _level, _capital, _listEmployee, _stock)
{
}

PrimaryCompany::~PrimaryCompany() {

}

std::string PrimaryCompany::getName()
{
	return name;
}

void PrimaryCompany::addEmployee(Employee _employee)
{

}


void PrimaryCompany::create()
{
}
