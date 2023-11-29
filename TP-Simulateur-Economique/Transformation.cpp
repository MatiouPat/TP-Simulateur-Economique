// Transformation.cpp
#pragma once

#include "Transformation.hpp"


/**
*
**/
Transformation::Transformation(Merchandise _merchandiseProduced, Merchandise _merchandiseNeeded, Company _company, float _sellPrice, unsigned int _prodByWeek)
{
	merchandiseProduced = _merchandiseProduced;
	merchandiseNeeded = _merchandiseNeeded;
	company = _company;
	sellPrice = _sellPrice;
	prodByWeek = _prodByWeek;
}
