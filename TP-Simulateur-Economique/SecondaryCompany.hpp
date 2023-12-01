// SecondaryCompany.hpp
#pragma once

#include "Company.hpp"
#include "Transformation.hpp"

class SecondaryCompany : public Company
{
public:

	SecondaryCompany();
	SecondaryCompany(std::string _name, unsigned int _level, double _capital,
		std::vector<Employee> _listEmployee, std::map<Merchandise, int> _stock, std::map<Merchandise, int> _stockMax);
	~SecondaryCompany();
	std::string getName();
	void addEmployee(Employee _employee);
	void transform(Company* pCompany);
	void buy();
	template <typename CompanyType>
	Company findSupplier(Transformation<CompanyType> transfo);

};

/**
*
**/
template <typename CompanyType>
Company SecondaryCompany::findSupplier(Transformation<CompanyType> transfo)
{
	return Company();
}