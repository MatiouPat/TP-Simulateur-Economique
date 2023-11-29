// Merchandise.hpp
#pragma once

#include "MerchandiseType.hpp"
#include <iostream>
#include <vector>

class Merchandise
{
public:


private:
	std::string name;
	float marketPrice;
	std::vector<MerchandiseType> type;
};