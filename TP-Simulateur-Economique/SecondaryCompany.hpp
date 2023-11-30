// SecondaryCompany.hpp
#pragma once

#include "Company.hpp"
#include "Transformation.hpp"

class SecondaryCompany : public Company
{
public:

	SecondaryCompany();
	SecondaryCompany(std::string _name, unsigned int _niveau, double _capital, 
		std::vector<Employee> _listEmployee, std::map<int, Merchandise> _stock);

	void transform();
	void buy();
	Company findSupplier(Transformation transfo);

};