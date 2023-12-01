// SFMLWindow.hpp
#pragma once

#include <vector>
#include "Board.hpp"	 
#include <SFML/Graphics.hpp>

class SFMLWindow 
{
public:

	SFMLWindow(Board b, float scale, std::string name);
	~SFMLWindow();
	void print();
	std::shared_ptr<Square> getCompanyAtPos(int x, int y);
	float scaleValue(float value, float minBound, float maxBound, float newMinBound, float newMaxBound) const;

private:
	std::shared_ptr<Board> board;
	std::vector<std::shared_ptr<Square>> vecCompanies;
	int nbRow;			// nb de row du board
	int nbCol;			// nb de col du board
	int windowSizeX;	// nb de px en largeur
	int windowSizeY;	// nb de px en hauteur
	float cellSize;		// taille en px d'une cellule
	std::string name;	// nom de la fenetre
};