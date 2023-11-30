#include "SecondaryCompany.hpp"


SecondaryCompany::SecondaryCompany(std::vector<Merchandise> _entrant, std::map<Merchandise, int> _coutProd)
{
	entrant = _entrant;
	coutProd = _coutProd;
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


/**
*
**/
Company SecondaryCompany::findSupplier(Transformation transfo)
{
	return Company();
}
