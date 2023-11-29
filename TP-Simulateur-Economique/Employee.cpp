#include "Employee.hpp"

Employee::Employee(unsigned int _salary)
{
	salary = _salary;
}


/**
* Retourne le salaire d'un employee
**/
int Employee::getSalary()
{
	return salary;
}
