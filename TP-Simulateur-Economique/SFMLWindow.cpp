//

#include "SFMLWindow.hpp"
#include <SFML/Graphics.hpp>


SFMLWindow::SFMLWindow()
{
}

SFMLWindow::~SFMLWindow()
{
}

/**
* Change l'echelle d'une valeur
* Exemple : On a une valeur compris entre -1 et 1 et on veut la passer entre -10 et 10
*
* @param value La valeur que l'on souhaite mettre a l'echelle
* @param minBound La valeur min que value peut prendre actuellement
* @param maxBound La valeur max que value peut prendre actuellement
* @param newMinBound La valeur min que pourra prendre value (apres traitement)
* @param newMaxBound La valeur max que pourra prendre value (apres traitement)
**/
float SFMLWindow::scaleValue(float value, float minBound, float maxBound, float newMinBound, float newMaxBound)
{
    return  ((value - (minBound)) / (maxBound - (minBound))) * (newMaxBound - newMinBound) + newMinBound;
}


/**
* Affiche dans une fenetre graphique une matrice de float 
**/
void SFMLWindow::print(std::vector<std::vector<float>> carte, int echelle)
{
    int n = carte.size();
    int m = carte.at(0).size();
    int windowSize = n * echelle;
    int windowSize2 = m * echelle;
    float cellSize = (float)windowSize / n;
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize2), "Carte");

    sf::RectangleShape cell;
    cell.setSize(sf::Vector2f(cellSize, cellSize));

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // il faut effacer avant de reafficher
        window.clear();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                //Point p = m.getPointByIndexes(i, j);

                float newValue = scaleValue(carte[i][j],  -3.8, 3.8, 0, 255);

                cell.setSize(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(j * cellSize, i * cellSize);
                //cell.setFillColor(sf::Color::White);
                //cell.setFillColor(0);
                //cell.setFillColor(0);
                window.draw(cell);

                //std::cout << carte[i][j] << std::endl;
                sf::Color color;
                /* white -> blue -> black
                if (newValue < 255)
                {
                    color = sf::Color(0, 0, newValue);
                }
                else if (newValue < 510)
                {
                    color = sf::Color(0, newValue-255, 255);
                }
                else
                {
                    color = sf::Color(newValue-510, 255, 255);
                }*/
               
                color = sf::Color(80, newValue, 255);

                cell.setFillColor(color);




                cell.setSize(sf::Vector2f(cellSize - 20, cellSize - 20));
                cell.setPosition((j * cellSize + 10), (i * cellSize) + 10);
                window.draw(cell);

            }
        }

        window.display();
    }
}

