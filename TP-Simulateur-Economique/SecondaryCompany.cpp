#include "SecondaryCompany.hpp"

/**
*
**/
void SecondaryCompany::transform()
{
	auto getincom = prod->getIncoming();
	auto curseur = getincom.begin();
	Merchandise op = curseur->first;
	//std::cout << op.getName() << curseur->second << std::endl;
	/*for (int i = 0; i <= size(prod->getIncoming()); i++)
	{
		if (stock[prod->getIncoming()[i]] - prod->getProdCost()[prod->getIncoming()[i]] >= 0) {
			if (pCompany->stock[pCompany->sortant] + 1 <= pCompany->stockMax[pCompany->sortant])
			{
				for (int i = 0; i <= size(prod->getIncoming()); i++)
				{
					pCompany->stock[pCompany->entrant[i]] -= pCompany->coutProd[pCompany->entrant[i]];
				}
				pCompany->stock[pCompany->sortant] += 1;
			}
			else
			{
				std::cerr << "Outgoing products storage full. " << std::endl;
			}
		}
		else
		{
			std::cerr << "Empty storage for incoming products. " << std::endl;
		}
	}	*/
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



