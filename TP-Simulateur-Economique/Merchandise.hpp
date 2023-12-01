// Merchandise.hpp
#pragma once

#include "MerchandiseType.hpp"
#include <iostream>
#include <vector>

class Merchandise
{
public:

	Merchandise();
	Merchandise(std::string _name, float _marketPrice, std::vector<MerchandiseType> _types);

private:

	std::string name;
	float marketPrice;
	std::vector<MerchandiseType> types;

};