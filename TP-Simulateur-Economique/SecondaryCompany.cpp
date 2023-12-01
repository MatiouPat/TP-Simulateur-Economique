#include "SecondaryCompany.hpp"

/**
*
**/
void SecondaryCompany::transform()
{
	bool isPossible = true;
	for (int i = 0; i < size(prod->getIncoming()); i++)
	{
		std::map <Merchandise, int> marchandises = prod->getIncoming();
		auto ressource = marchandises.begin();
		std::advance(ressource, i);

		if (stock[ressource->first] - ressource->second * prod->getDailyProd() <= 0) {
			if (stock[prod->getOutgoing()] + prod->getDailyProd() >= stockMax[prod->getOutgoing()] + prod->getDailyProd())
			{
				isPossible = isPossible && false;
				std::cerr << "Outgoing products storage full. " << std::endl;
			}
			isPossible = isPossible && false;
			std::cerr << "Empty storage for incoming products. " << std::endl;
		}
	}
	if (isPossible)
	{
		std::map <Merchandise, int> marchandises = prod->getIncoming();
		auto ressource = marchandises.begin();
		while (ressource != marchandises.end())
		{
			stock[ressource->first] -= ressource->second * prod->getDailyProd();
			ressource++;
		}
		ressource = marchandises.begin();

		stock[prod->getOutgoing()] += prod->getDailyProd();
	}
}

SecondaryCompany::SecondaryCompany()
{
}

SecondaryCompany::SecondaryCompany(std::string _name, unsigned int _level, double _capital, std::vector<Employee> _listEmployee, std::map<Merchandise, int> _stock, std::map<Merchandise, int> _stockMax, std::shared_ptr<Production> _production) : Company(_name, _level, _capital, _listEmployee, _stock, _stockMax, _production)
{
}


SecondaryCompany::~SecondaryCompany()
{
}


/**
*
**/
std::string SecondaryCompany::getName()
{
	return name;
}


/**
*
**/
void SecondaryCompany::addEmployee(Employee _employee)
{

}


/**
*
**/
void SecondaryCompany::buy()
{
}



