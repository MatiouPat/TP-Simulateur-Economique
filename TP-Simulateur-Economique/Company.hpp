// Company.cpp
#pragma once
// Forward declarations if needed


#include <map>

#include "Employee.hpp" 
#include "Merchandise.hpp" 

class Square;
class Employee;
class Merchandise;

// Abstract class Company
class Company
{

public:

	Company();
	Company(const Company& c) {
		*this = c;
	}
	Company(std::string _name, unsigned int _level, double _capital, std::vector<Employee> _listEmployee, std::map<Merchandise, int> _stock, std::map<Merchandise, int> _stockMax);
	~Company();
	virtual std::string getName() const = 0;
	void addEmployee(Employee _employee);
	void levelUp();

protected:

	std::string name;
	unsigned int level;
	double capital;
	std::vector<Employee> listEmployee;
	std::map<Merchandise, int> stock;
	std::map<Merchandise, int> stockMax;

};