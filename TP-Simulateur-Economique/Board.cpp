// Board.cpp
#include "Board.hpp"

#include <vector>
#include "PerlinNoise.hpp"


/**
* Initialisation d'un board de taille _sizeX ligne et _sizeY colonne
**/
Board::Board(int _sizeX, int _sizeY)
{
    sizeX = _sizeX;
    sizeY = _sizeY;

    board = std::deque<std::deque<std::shared_ptr<Square>>>(_sizeX, std::deque<std::shared_ptr<Square>>(_sizeY));

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            board[i][j] = std::shared_ptr<Square>(new Square(i, j, static_cast<float>(sizeX + sizeY), sizeX + sizeY, SquareState::UNKNOWN));
        }
    }
}


/**
* Initialise un board a partir d'un autre board
**/
Board::Board(std::deque<std::deque<std::shared_ptr<Square>>>& _board)
{
    sizeX = static_cast<int>(_board.size());
    if (sizeX != 0)
    {
        sizeY = static_cast<int>(_board[0].size());
    }
    else
    {
        sizeY = 0;
    }
    board = _board;
}


Board::~Board()
{

}


/**
* Parmi les entreprises presentes sur la carte, on souhaite
* trouver celle qui produit un certain type de marchandise
**/
std::shared_ptr<Company> Board::findSupplier(std::shared_ptr<Merchandise> m) 
{
    for (size_t i = 0; i < listCompanies.size(); ++i)
    {
        if (listCompanies[i]->getCompany()->getMerchandiseCreated().getName() == m->getName()) 
        {
            return listCompanies[i]->getCompany();
        }
    }
    return nullptr;
}


/**
* Retourne le nombre de ligne de la board
**/
int Board::getNbRow()
{
    return board.size();
}


/**
* Retourne le nombre de colonne de la board
**/
int Board::getNbCol()
{
    return board.at(0).size();
}


/**
* Retourne le square a la position (i, j) dans la board
**/
std::shared_ptr<Square> Board::getSquare(int i, int j)
{
    return board[i][j];
}


/**
* 0-Left : 0001 / 1-Top : 0010 / 2-Right : 0100 / 3-Bottom : 1000
*/
void Board::addChessboardCase(Orientation orientation)
{
    switch (orientation)
    {
    case WEST:
    {
        shiftColumns();
        for (int i = 0; i < sizeY; i++) {
            board[i].push_front(std::shared_ptr<Square>(new Square(i, 0, 0, 0, SquareState::UNKNOWN)));
        }
        sizeX++;
        break;
    }
    case NORTH:
    {
        shiftLines();
        std::deque<std::shared_ptr<Square>> newRow;
        for (int i = 0; i < sizeX; i++)
        {
            newRow.push_back(std::shared_ptr<Square>(new Square(0, i, 0, 0, SquareState::UNKNOWN)));
        }
        board.push_front(newRow);
        sizeY++;
        break;
    }
    case EAST:
    {
        for (int i = 0; i < sizeY; i++) {
            board[i].push_back(std::shared_ptr<Square>(new Square(i, sizeX, 0, 0, SquareState::UNKNOWN)));
        }
        sizeX++;
        break;
    }
    case SOUTH:
    {
        std::deque<std::shared_ptr<Square>> newRow;
        for (int i = 0; i < sizeX; i++)
        {
            newRow.push_back(std::shared_ptr<Square>(new Square(sizeY, i, 0, 0, SquareState::UNKNOWN)));
        }
        board.push_back(newRow);
        sizeY++;
        break;
    }
    case NORTH_WEST:
    {
        shiftLinesAndColumns();
        for (int i = 0; i < sizeY; i++) {
            board[i].push_front(std::shared_ptr<Square>(new Square(i + 1, 0, 0, 0, SquareState::UNKNOWN)));
        }
        sizeX++;
        std::deque<std::shared_ptr<Square>> newRow;
        for (int i = 0; i < sizeX; i++)
        {
            newRow.push_back(std::shared_ptr<Square>(new Square(0, i, 0, 0, SquareState::UNKNOWN)));
        }
        board.push_front(newRow);
        sizeY++;
        break;
    }
    case NORTH_EAST:
    {
        shiftLines();
        for (int i = 0; i < sizeY; i++) {
            board[i].push_back(std::shared_ptr<Square>(new Square(i + 1, sizeX, 0, 0, SquareState::UNKNOWN)));
        }
        sizeX++;
        std::deque<std::shared_ptr<Square>> newRow;
        for (int i = 0; i < sizeX; i++)
        {
            newRow.push_back(std::shared_ptr<Square>(new Square(0, i, 0, 0, SquareState::UNKNOWN)));
        }
        board.push_front(newRow);
        sizeY++;
        break;
    }
    case SOUTH_WEST:
    {
        shiftColumns();
        for (int i = 0; i < sizeY; i++) {
            board[i].push_front(std::shared_ptr<Square>(new Square(i, 0, 0, 0, SquareState::UNKNOWN)));
        }
        sizeX++;
        std::deque<std::shared_ptr<Square>> newRow;
        for (int i = 0; i < sizeX; i++)
        {
            newRow.push_back(std::shared_ptr<Square>(new Square(sizeY, i, 0, 0, SquareState::UNKNOWN)));
        }
        board.push_back(newRow);
        sizeY++;
        break;
    }
    case SOUTH_EAST:
    {
        for (int i = 0; i < sizeY; i++) {
            board[i].push_back(std::shared_ptr<Square>(new Square(i, sizeX, 0, 0, SquareState::UNKNOWN)));
        }
        sizeX++;
        std::deque<std::shared_ptr<Square>> newRow;
        for (int i = 0; i < sizeX; i++)
        {
            newRow.push_back(std::shared_ptr<Square>(new Square(sizeY, i, 0, 0, SquareState::UNKNOWN)));
        }
        board.push_back(newRow);
        sizeY++;
        break;
    }
    }
}


/**
* Print board in the console
*/
void Board::printBoard()
{
    for (int x = 0; x < board.size(); x++)
    {
        for (int y = 0; y < board[x].size(); y++)
        {
            char character{};

            switch (board[x][y]->getState())
            {
            case UNKNOWN:
                character = '?';
                break;
            case TRAVERSABLE:
                character = 'o';
                break;
            case UNTRAVERSABLE:
                character = 'x';
                break;
            }
            std::cout << character << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n' << std::endl;
}


/**
* 
**/
std::deque < std::shared_ptr<Square>> Board::searchShortestPath(int startX, int startY, int endX, int endY)
{
    std::shared_ptr<Square> cursor = board[startX][startY];
    std::vector<std::shared_ptr<Square>> squareCalculed = {};
    std::vector<std::shared_ptr<Square>> squareVisited = {};

    while (cursor->getX() != board[endX][endY]->getX() || cursor->getY() != board[endX][endY]->getY())
    {
        /*Calcul des heuristiques des noeuds voisins*/
        for (int i = -1; i < 2; i = i++)
        {
            for (int j = -1; j < 2; j = j++)
            {
                if (cursor->getX() + i >= 0 && cursor->getX() + i < sizeX && cursor->getY() + j >= 0 && cursor->getY() + j < sizeY)
                {
                    std::shared_ptr<Square> target = board[cursor->getX() + i][cursor->getY() + j];
                    if (target->getState() != SquareState::UNTRAVERSABLE && (i != 0 || j != 0))
                    {
                        float newCost = calculCost(cursor, target, board[endX][endY]);
                        if (newCost + cursor->getHeuristic() + 1 < target->getCost()) {
                            target->setCost(cursor->getCost() + newCost);
                            target->setHeuristic(cursor->getHeuristic() + 1);
                        }
                        bool isAlreadyPresent = false;
                        bool isAlreadyVisited = false;
                        for (int x = 0; x < squareCalculed.size(); x++)
                        {
                            if (target == squareCalculed[x])
                            {
                                isAlreadyPresent = true;
                            }
                        }
                        for (int y = 0; y < squareVisited.size(); y++)
                        {
                            if (target == squareVisited[y])
                            {
                                isAlreadyVisited = true;
                            }
                        }
                        if (!isAlreadyPresent && !isAlreadyVisited)
                        {
                            squareCalculed.push_back(target);
                        }
                    }
                }
            }
        }
        
        /*Si aucun acc�s possible � l'arriv�, arr�t de la recherche*/
        if (squareCalculed.size() == 0 && squareVisited.size() == 0)
        {
            return {};
        }

        /*Recherche des noeuds visit�s avec le cout le plus faible*/
        std::shared_ptr<Square> futureNode = squareCalculed[0];
        int lowestGlobalCost = squareCalculed[0]->getCost() + squareCalculed[0]->getHeuristic();

        for (int i = 0; i < squareCalculed.size(); i++)
        {
            if ((squareCalculed[i]->getCost() + squareCalculed[i]->getHeuristic()) < lowestGlobalCost)
            {
                futureNode = squareCalculed[i];
                lowestGlobalCost = squareCalculed[i]->getCost() + squareCalculed[i]->getHeuristic();
            }
        }

        /*D�placement vers le noeud avec le cout le plus faible*/
        squareVisited.push_back(cursor);
        cursor = futureNode;
        for (int i = 0; i < squareCalculed.size(); i++)
        {
            if (cursor == squareCalculed[i])
            {
                squareCalculed.erase(squareCalculed.begin() + i);
            }
        }
    }
    // On refait le chemin pour le noter
    std::deque<std::shared_ptr<Square>> path;
    std::shared_ptr<Square> traveler = board[startX][startY];
    path.push_back(traveler);
    printBoard();
    while (traveler->getX() != board[endX][endY]->getX() || traveler->getY() != board[endX][endY]->getY())
    {
        float localCost = static_cast<float>(sizeX * sizeY);
        std::shared_ptr<Square> futureNode;
        /*Recherche du noeud voisin avec le cout le plus faible*/
        for (int i = -1; i < 2; i = i++)
        {
            for (int j = -1; j < 2; j = j++)
            {
                int cursorX = traveler->getX() + i;
                int cursorY = traveler->getY() + j;
                if (cursorX >= 0 && cursorX < sizeX && cursorY >= 0 && cursorY < sizeY && (cursorX != traveler->getX() || cursorY != traveler->getY()))
                {
                    if (std::find(path.begin(), path.end(), board[cursorX][cursorY]) == path.end())
                    {
                        if (board[cursorX][cursorY]->getCost() < localCost && board[cursorX][cursorY]->getState() != SquareState::UNTRAVERSABLE)
                        {
                            localCost = board[cursorX][cursorY]->getCost();
                            futureNode = board[cursorX][cursorY];
                        }
                    }
                }
            }
        }
        traveler = futureNode;
        path.push_back(futureNode);
    }
    return path;
}


/*
* On compare la distance entre s1 et dest et s2 et dest
* Si s1 est plus pr�s que s2 -> 1
* Si s1 est plus pr�s que s2 -> 0
* Si s1 est plus pr�s que s2 -> 1
*/
float Board::calculCost(std::shared_ptr<Square> s1, std::shared_ptr<Square> s2, std::shared_ptr<Square> dest)
{
    int diffS1X = abs(dest->getX() - s1->getX());
    int diffS2X = abs(dest->getX() - s2->getX());
    int diffS1Y = abs(dest->getY() - s1->getY());
    int diffS2Y = abs(dest->getY() - s2->getY());
    if (diffS1X < diffS2X && diffS1Y < diffS2Y)
    {
        return (float)sqrt(2);
    }
    else if (diffS1X < diffS2X && diffS1Y == diffS2Y || diffS1X == diffS2X && diffS1Y < diffS2Y)
    {
        return 1.0f;
    }
    else if (diffS1X > diffS2X && diffS1Y < diffS2Y || diffS1X < diffS2X && diffS1Y > diffS2Y)
    {
        return 0.0f;
    }
    else if (diffS1X > diffS2X && diffS1Y > diffS2Y)
    {
        return (float)-sqrt(2);
    }
    else
    {
        return -1.0;
    }
}


/**
* Definit les state et les value de tous les square de la board
* en utilisant le bruit de perlin
**/
void Board::generateMap(float frequency)
{
  
    PerlinNoise perlinN;

    for (int x = 0; x < board.size(); ++x)
    {
        for (int y = 0; y < board.at(x).size(); ++y)
        {
            float bitState = perlinN.perlinNoise2D(x * frequency, y * frequency);
            std::shared_ptr<Square> square(new Square(x, y, static_cast<float>(x + y), x + y));

            square->setValue(bitState);
            if (bitState < -0.8)
            {
                square->setState(SquareState::UNTRAVERSABLE);
            }
            else
            {
                square->setState(SquareState::TRAVERSABLE);
            }
            board[x][y] = square;
        }
    }

    
}


/**
*
**/
void Board::shiftColumns()
{
    for (std::deque<std::shared_ptr<Square>> row : board)
    {
        for (std::shared_ptr<Square> square : row)
        {
            square->setY(square->getY() + 1);
        }
    }
}


/**
*
**/
void Board::shiftLines()
{
    for (std::deque<std::shared_ptr<Square>> row : board)
    {
        for (std::shared_ptr<Square> square : row)
        {
            square->setX(square->getX() + 1);
        }
    }
}


/**
*
**/
void Board::shiftLinesAndColumns()
{
    for (std::deque<std::shared_ptr<Square>> row : board)
    {
        for (std::shared_ptr<Square> square : row)
        {
            square->setX(square->getX() + 1);
            square->setY(square->getY() + 1);
        }
    }
}
