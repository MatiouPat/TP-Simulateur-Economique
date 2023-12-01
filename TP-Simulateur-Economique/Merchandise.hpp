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
	std::string getName();

private:

	std::string name;
	float marketPrice;
	std::vector<MerchandiseType> types;

};