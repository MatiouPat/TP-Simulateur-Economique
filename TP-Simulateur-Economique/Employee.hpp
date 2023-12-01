// Employee.hpp
#pragma once

#include <string>

class Employee
{

public:

	Employee(unsigned int _salary);
	int getSalary() const;

private:

	unsigned int salary;

};