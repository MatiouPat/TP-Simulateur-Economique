// Production.cpp
#pragma once

#include "Merchandise.hpp" 
#include "Company.hpp"

class Company;

class Production
{
public:

	//Production();
	Production(std::map<Merchandise, int> _incoming, Merchandise _outgoing, std::shared_ptr<Company> _company, float _price, unsigned int _dailyProd, std::map<Merchandise,int> _prodCost, unsigned int _employee);
	~Production();
	std::map<Merchandise, int> getIncoming();
	/*Merchandise getIncomingByID(int n);*/
	std::map<Merchandise, int> getProdCost();

protected:

	std::map<Merchandise, int> incoming;
	Merchandise outgoing;
	std::shared_ptr<Company> company;
	float price;
	unsigned int dailyProd;
	std::map<Merchandise, int> prodCost;
	unsigned int employee;
};
