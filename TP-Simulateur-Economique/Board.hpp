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
    void addChessboardCase(Orientation orientation);
    void printBoard();
    void printBoard(std::vector<Company>& entreprises);
    std::deque <std::shared_ptr<Square>> searchShortestPath(int startX, int startY, int endX, int endY);
    float calculCost(std::shared_ptr<Square> s1, std::shared_ptr<Square> s2, std::shared_ptr<Square> dest);
    std::deque<std::shared_ptr<Square>> neighbours(int squareX, int squareY);
    void addCompany(std::shared_ptr<Company> c, int x, int y);
    void generateMap(float frequency);
    int getNbCol();
    int getNbRow();
    std::shared_ptr<Square> getSquare(int i, int j);

protected:

    void shiftColumns();
    void shiftLines();
    void shiftLinesAndColumns();

private:

    int sizeX;
    int sizeY;
    std::deque<std::deque<std::shared_ptr<Square>>> board;
};
