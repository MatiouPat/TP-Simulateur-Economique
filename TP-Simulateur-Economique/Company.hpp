// Company.cpp
#pragma once

#include "Square.hpp"
#include <string>
#include <vector>
#include <map>
#include "Employee.hpp"
#include "Merchandise.hpp"

class Company
{

public:

	Company();
	Company(std::string name, unsigned int niveau, double capital, Square position, std::vector<Employee> listEmployee, std::map<int, Merchandise> stock);
	~Company();
	std::string getName();
	int getPositionX();
	int getPositionY();


private:

	std::string name;
	unsigned int niveau;
	double capital;
	Square position;
	std::vector<Employee> listEmployee;
	std::map<int, Merchandise> stock;
};