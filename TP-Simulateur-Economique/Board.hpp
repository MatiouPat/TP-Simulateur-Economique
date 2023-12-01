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
    template<typename CompanyType>
    void addCompany(std::shared_ptr<CompanyType> c, int x, int y);
    std::shared_ptr<Square> getSquare(int i, int j);
    void addChessboardCase(Orientation orientation);
    std::deque <std::shared_ptr<Square>> searchShortestPath(int startX, int startY, int endX, int endY);
    void generateMap(float frequency);
    void printBoard();
    std::shared_ptr<Company> findSupplier(std::shared_ptr<Merchandise> m);

    void addRound();

protected:

    void shiftColumns();
    void shiftLines();
    void shiftLinesAndColumns();
    float calculCost(std::shared_ptr<Square> s1, std::shared_ptr<Square> s2, std::shared_ptr<Square> dest);

private:
    unsigned int round;
    std::vector<std::shared_ptr<Square>> listCompanies;
    int sizeX;
    int sizeY;
    std::deque<std::deque<std::shared_ptr<Square>>> board;

};


/**
* Ajoute une company dans le square en position (x, y) dans le board
*
* @param c La company que l'on veut ajouter
* @param x La ligne a laquelle on veut ajouter la company
* @param y La colonne a laquelle on veut ajouter la company
**/
template<typename CompanyType>
void Board::addCompany(std::shared_ptr<CompanyType> c, int x, int y)
{
    board[x][y]->setState(UNTRAVERSABLE);
    board[x][y]->setCompany(c);

    listCompanies.push_back(board[x][y]);
}