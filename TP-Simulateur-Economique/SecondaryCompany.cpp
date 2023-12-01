#include "SecondaryCompany.hpp"

SecondaryCompany::SecondaryCompany()
{
}

SecondaryCompany::SecondaryCompany(std::string _name, unsigned int _level, double _capital, std::vector<Employee> _listEmployee, std::map<Merchandise, int> _stock)
	: Company(_name, _level, _capital, _listEmployee, _stock)
{
}


SecondaryCompany::~SecondaryCompany()
{
}


/**
*
**/
std::string SecondaryCompany::getName()
{
	return name;
}


/**
*
**/
void SecondaryCompany::addEmployee(Employee _employee)
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



