#include "SecondaryCompany.hpp"

SecondaryCompany::SecondaryCompany(std::vector<Merchandise> _entrant, std::map<Merchandise, int> _coutProd)
{
	entrant = _entrant;
	coutProd = _coutProd;
}
/**
*
**/
void SecondaryCompany::transform(Company* pCompany)
{
	for (int i = 0, i <= size(pCompany->entrant), i++)
	{
		if (pCompany->stock[pCompany->entrant[i]] - pCompany->coutProd[pCompany->entrant[i]] >= 0) {
			if (pCompany->stock[pCompany->sortant] + 1 <= pCompany->stockMax[pCompany->sortant])
			{
				for (int i = 0, i <= size(pCompany->entrant), i++)
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
	}	
SecondaryCompany::SecondaryCompany()
{
}

SecondaryCompany::SecondaryCompany(std::string _name, unsigned int _level, double _capital, std::vector<Employee> _listEmployee, std::map<Merchandise, int> _stock)
	: Company(_name, _level, _capital, _listEmployee, _stock)
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
void SecondaryCompany::transform()
{
}


/**
*
**/
void SecondaryCompany::buy()
{
}



