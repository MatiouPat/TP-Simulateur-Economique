#include "PrimaryCompany.hpp"

void PrimaryCompany::create(Company* _company)
{
	if (pCompany->stock[pCompany->sortant] + 1 <= pCompany->stockMax[pCompany->sortant])
	{
		pCompany->stock[pCompany->sortant] += 1;
	}
	else
	{
		std::cerr << "Outgoing products storage full. " << std::endl;
	}
}
