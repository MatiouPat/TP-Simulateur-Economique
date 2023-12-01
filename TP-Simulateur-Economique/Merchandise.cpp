#include "Merchandise.hpp"
// Merchandise.cpp
int Merchandise::counter = 0;

Merchandise::Merchandise()
{
	id++;
	name = "";
	marketPrice = 0.0f;
	types = std::vector<MerchandiseType>();
}

Merchandise::Merchandise(std::string _name, float _marketPrice, std::vector<MerchandiseType> _types)
{
	id = counter++;
	name = _name;
	marketPrice = _marketPrice;
	types = _types;
}

float Merchandise::getMarketPrice() const
{
	return marketPrice;
}

std::string Merchandise::getName() const
{
	return name;
}

int Merchandise::getId() const
{
	return id;
}
