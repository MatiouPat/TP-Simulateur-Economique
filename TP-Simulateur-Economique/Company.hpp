// Company.cpp
#pragma once
// Forward declarations if needed


#include <map>

#include "Employee.hpp" 
#include "Merchandise.hpp" 

class Square;
class Employee;
class Merchandise;


class Company
{

public:

	Company();
	Company(std::string _name, unsigned int _niveau, double _capital, std::vector<Employee> _listEmployee, std::map<int, Merchandise> _stock);
	~Company();
	std::string getName();


private:

	std::string name;
	unsigned int niveau;
	double capital;
	std::vector<Employee> listEmployee;
	std::map<int, Merchandise> stock;
};