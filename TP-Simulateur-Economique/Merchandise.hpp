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
	bool operator<(const Merchandise& other) const {
		return getMarketPrice() < other.getMarketPrice();
	}
	float getMarketPrice() const;
	std::string getName() const;

private:

	std::string name;
	float marketPrice;
	std::vector<MerchandiseType> types;

};