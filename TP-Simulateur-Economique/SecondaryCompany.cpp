#include "SecondaryCompany.hpp"

SecondaryCompany::SecondaryCompany()
{
}

SecondaryCompany::SecondaryCompany(std::string _name, unsigned int _niveau, double _capital, std::vector<Employee> _listEmployee, std::map<int, Merchandise> _stock)
	: Company(_name, _niveau, _capital, _listEmployee, _stock)
{
}

/**
*
**/
void SecondaryCompany::transform()
{
}


/**
*
**/
void SecondaryCompany::buy()
{
}


/**
*
**/
Company SecondaryCompany::findSupplier(Transformation transfo)
{
	return Company();
}
