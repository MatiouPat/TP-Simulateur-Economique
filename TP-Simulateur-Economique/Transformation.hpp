// Transformation.hpp
#pragma once

#include "Merchandise.hpp"
#include "Company.hpp"

template <typename CompanyType>
class Transformation
{

public:

	Transformation(Merchandise _merchandiseProduced, Merchandise _merchandiseNeeded, CompanyType _company, float _sellPrice, unsigned int _prodByWeek);

private:

	Merchandise merchandiseProduced;
	Merchandise merchandiseNeeded;
	CompanyType company;
	float sellPrice;
	unsigned int prodByWeek;


};


/**
*
**/
template<typename CompanyType>
inline Transformation<CompanyType>::Transformation(Merchandise _merchandiseProduced, Merchandise _merchandiseNeeded, CompanyType _company, float _sellPrice, unsigned int _prodByWeek)
{
	merchandiseProduced = _merchandiseProduced;
	merchandiseNeeded = _merchandiseNeeded;
	company = _company;
	sellPrice = _sellPrice;
	prodByWeek = _prodByWeek;
}
