// SFMLWindow.hpp
#pragma once

#include <vector>

class SFMLWindow 
{
public:

	SFMLWindow();
	~SFMLWindow();
	void print(std::vector<std::vector<float>> carte, int echelle);
	float scaleValue(float value, float minBound, float maxBound, float newMinBound, float newMaxBound);

};