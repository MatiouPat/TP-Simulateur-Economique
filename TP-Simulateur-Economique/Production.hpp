// Production.cpp
#pragma once

#include "Merchandise.hpp" 
#include "Company.hpp"

class Company;

class Production
{
public:

	//Production();
	Production(std::map<Merchandise, int> _incoming, Merchandise _outgoing, float _price, unsigned int _dailyProd, std::map<Merchandise,int> _prodCost, unsigned int _employee);
	~Production();
	std::map<Merchandise, int> getIncoming();
	Merchandise getOutgoing();
	/*Merchandise getIncomingByID(int n);*/
	std::map<Merchandise, int> getProdCost();
	Merchandise getOutgoing() const;
	unsigned int getDailyProd() const;

protected:

	std::map<Merchandise, int> incoming;
	Merchandise outgoing;
	float price;
	unsigned int dailyProd;
	std::map<Merchandise, int> prodCost;
	unsigned int employee;
};
