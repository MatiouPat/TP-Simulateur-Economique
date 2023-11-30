// Board.hpp
#pragma once

#include <iostream>
#include <deque>
#include "Square.hpp"
#include "Orientation.hpp"
#include "Company.hpp"

class Board
{

public:

    Board(int _sizeX, int _sizeY);
    Board(std::deque<std::deque<std::shared_ptr<Square>>>& _board);
    ~Board();    
    int getNbCol();
    int getNbRow();    
    void addCompany(std::shared_ptr<Company> c, int x, int y);
    std::shared_ptr<Square> getSquare(int i, int j);
    void addChessboardCase(Orientation orientation);
    std::deque <std::shared_ptr<Square>> searchShortestPath(int startX, int startY, int endX, int endY);
    void generateMap(float frequency);
    void printBoard();
    void printBoard(std::vector<Company>& entreprises);

protected:

    void shiftColumns();
    void shiftLines();
    void shiftLinesAndColumns();
    float calculCost(std::shared_ptr<Square> s1, std::shared_ptr<Square> s2, std::shared_ptr<Square> dest);

private:

    int sizeX;
    int sizeY;
    std::deque<std::deque<std::shared_ptr<Square>>> board;

};
