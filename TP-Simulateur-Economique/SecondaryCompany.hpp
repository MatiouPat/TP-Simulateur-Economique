// SecondaryCompany.hpp
#pragma once

#include "Company.hpp"
#include "Transformation.hpp"
#include "Production.hpp"

class SecondaryCompany : public Company
{
public:

	SecondaryCompany();
	SecondaryCompany(std::string _name, unsigned int _level, double _capital,
		std::vector<Employee> _listEmployee, std::map<Merchandise, int> _stock, std::map<Merchandise, int> _stockMax, std::shared_ptr<Production> _production);
	~SecondaryCompany();
	std::string getName();
	void addEmployee(Employee _employee);
	void transform();
	void buy();

};

