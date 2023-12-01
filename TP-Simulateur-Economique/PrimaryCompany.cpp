#include "PrimaryCompany.hpp"

PrimaryCompany::PrimaryCompany()
{
}

PrimaryCompany::PrimaryCompany(std::string _name, unsigned int _level, double _capital, std::vector<Employee> _listEmployee, std::map<Merchandise, int> _stock, std::map<Merchandise, int> _stockMax)
	: Company(_name, _level, _capital, _listEmployee, _stock, _stockMax)
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
	/*if (pCompany->stock[pCompany->sortant] + 1 <= pCompany->stockMax[pCompany->sortant])
	{
		pCompany->stock[pCompany->sortant] += 1;
	}
	else
	{
		std::cerr << "Outgoing products storage full. " << std::endl;
	}*/
}
