// Company.cpp
#pragma once
// Forward declarations if needed


#include <map>

#include "Employee.hpp" 
#include "Merchandise.hpp" 
#include "Production.hpp"

class Square;
class Employee;
class Merchandise;
class Production;

// Abstract class Company
class Company
{

public:

	Company();
	Company(const Company& c) {
		*this = c;
	}
	Company(std::string _name, unsigned int _level, double _capital, std::vector<Employee> _listEmployee, std::map<Merchandise, int> _stock, std::map<Merchandise, int> _stockMax, std::shared_ptr<Production> _production);
	virtual ~Company();
	virtual std::string getName()  const { return "None";};
	virtual void addEmployee(Employee _employee) {};

	Merchandise getMerchandiseCreated() const;

	// methodes de PrimaryCompany
	virtual void create() { std::cout << "create called" << std::endl; };
	// methodes de SecondaryCompany
	void print();

protected:

	std::string name;
	unsigned int level;
	double capital;
	std::vector<Employee> listEmployee;
	std::map<Merchandise, int> stock;
	std::map<Merchandise, int> stockMax;
	std::shared_ptr<Production> prod;

};
