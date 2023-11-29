// Transformation.hpp
#pragma once

#include "Merchandise.hpp"
#include "Company.hpp"

class Transformation
{

public:

	Transformation(Merchandise merchandiseProduced, Merchandise merchandiseNeeded, Company company, float sellPrice, unsigned int prodByWeek);

private:

	Merchandise merchandiseProduced;
	Merchandise merchandiseNeeded;
	Company company;
	float sellPrice;
	unsigned int prodByWeek;


};
