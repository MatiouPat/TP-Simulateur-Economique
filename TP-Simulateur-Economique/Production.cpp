// Company.hpp

#include "Production.hpp"
#include <string>
#include <vector>
#include <map>
#include "Company.hpp"
#include "Merchandise.hpp"

Production::Production(std::map<Merchandise, int> _incoming, Merchandise _outgoing, float _price, unsigned int _dailyProd, std::map<Merchandise, int> _prodCost, unsigned int _employee)
{
	incoming = _incoming;
	outgoing = _outgoing;
	price = _price;
	dailyProd = _dailyProd;
	prodCost = _prodCost;
	employee = _employee;
}

Production::~Production()
{
}

std::map<Merchandise, int> Production::getIncoming()
{
	return incoming;
}


//Merchandise Production::getIncomingByID(int n)
//{
//	std::pair<Merchandise, int> retour = incoming.begin();
//	std::advance(retour, n);
//	return retour.first;
//}

std::map<Merchandise, int> Production::getProdCost()
{
	return prodCost;
}

Merchandise Production::getOutgoing() const
{
	return outgoing;
}

unsigned int Production::getDailyProd() const
{
	return dailyProd;
}

