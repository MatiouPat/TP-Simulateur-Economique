// Merchandise.hpp
#pragma once

#include "MerchandiseType.hpp"
#include <iostream>
#include <vector>

class Merchandise
{
public:

	Merchandise(std::string _name, float marketPrice, std::vector<MerchandiseType> type);

private:

	std::string name;
	float marketPrice;
	std::vector<MerchandiseType> type;

};