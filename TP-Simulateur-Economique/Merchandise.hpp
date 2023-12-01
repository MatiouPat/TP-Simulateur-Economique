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
		return getId() < other.getId();
	}
	float getMarketPrice() const;
	std::string getName() const;
	int getId() const;

private:
	static int counter;
	int id;
	std::string name;
	float marketPrice;
	std::vector<MerchandiseType> types;

};