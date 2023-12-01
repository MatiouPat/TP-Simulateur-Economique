// SFMLWindow.hpp
#pragma once

#include <vector>
#include "Board.hpp"	 

class SFMLWindow 
{
public:

	SFMLWindow();
	~SFMLWindow();
	void print(Board b, float echelle) const;
	float scaleValue(float value, float minBound, float maxBound, float newMinBound, float newMaxBound) const;

};