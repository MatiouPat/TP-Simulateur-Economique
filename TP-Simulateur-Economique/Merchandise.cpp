#include "Merchandise.hpp"
// Merchandise.cpp

Merchandise::Merchandise()
{
	name = "";
	marketPrice = 0.0f;
	types = std::vector<MerchandiseType>();
}

Merchandise::Merchandise(std::string _name, float _marketPrice, std::vector<MerchandiseType> _types)
{
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
