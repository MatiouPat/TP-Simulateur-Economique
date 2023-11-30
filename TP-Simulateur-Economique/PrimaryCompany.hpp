// PrimaryCompany.hpp
#pragma once

#include "Company.hpp"

class PrimaryCompany : public Company
{
public:

	PrimaryCompany();
	PrimaryCompany(std::string _name, unsigned int _niveau, double _capital,
		std::vector<Employee> _listEmployee, std::map<int, Merchandise> _stock);

	void create();

private:

};

