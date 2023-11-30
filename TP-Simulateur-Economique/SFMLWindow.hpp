// SFMLWindow.hpp
#pragma once

#include <vector>
#include "Board.hpp"	 

class SFMLWindow 
{
public:

	SFMLWindow();
	~SFMLWindow();
	void print(Board b, int echelle);
	float scaleValue(float value, float minBound, float maxBound, float newMinBound, float newMaxBound);

};