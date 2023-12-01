// PrimaryCompany.hpp
#pragma once

#include "Company.hpp"

class PrimaryCompany : public Company
{
public:

	PrimaryCompany();
	PrimaryCompany(std::string _name, unsigned int _level, double _capital,
		std::vector<Employee> _listEmployee, std::map<Merchandise, int> _stock, std::map<Merchandise, int> _stockMax);
	~PrimaryCompany();
	std::string getName() const override;
	void addEmployee(Employee _employee);
	void create();

private:

};

