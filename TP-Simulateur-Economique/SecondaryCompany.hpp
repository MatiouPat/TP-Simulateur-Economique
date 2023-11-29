// SecondaryCompany.hpp
#pragma once

#include "Company.hpp"
#include "Transformation.hpp"

class SecondaryCompany : public Company
{
public:

	void transform();
	void buy();
	Company findSupplier(Transformation transfo);

};