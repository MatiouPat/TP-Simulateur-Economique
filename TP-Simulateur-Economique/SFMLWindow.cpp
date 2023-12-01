//

#include "SFMLWindow.hpp"
#include <SFML/Graphics.hpp>
#include "Board.hpp"


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
float SFMLWindow::scaleValue(float value, float minBound, float maxBound, float newMinBound, float newMaxBound) const
{
    return  ((value - (minBound)) / (maxBound - (minBound))) * (newMaxBound - newMinBound) + newMinBound;
}


/**
* Affiche dans une fenetre graphique un board
**/
void SFMLWindow::print(Board b, float echelle) const
{
    int n = b.getNbRow();
    int m = b.getNbCol();
    int windowSize = n * echelle;
    int windowSize2 = m * echelle;
    float cellSize = (float)windowSize / n;
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize2), "Carte");

    sf::RectangleShape cell;
    cell.setSize(sf::Vector2f(cellSize, cellSize));

    // vector de square (contient les square associé a chaque company de la board)
    std::vector<Square> vecCompanies;

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


                /* ancien truc
                cell.setSize(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(j * cellSize, i * cellSize);
                window.draw(cell);*/

                float newValue = scaleValue(b.getSquare(i, j)->getValue(), -3.8, 3.8, 0, 255);

                cell.setFillColor(sf::Color(80, newValue, 10));

                // affichage de la couleur

                if (newValue<80)
                {
                    cell.setFillColor(sf::Color(60, 160, 210));

                }

                if (b.getSquare(i, j)->isCompany())
                {
                    vecCompanies.push_back(*(b.getSquare(i,j)));
                    cell.setFillColor(sf::Color::Red);
                }
                /*ancien truc
                cell.setSize(sf::Vector2f(cellSize - 20, cellSize - 20));
                cell.setPosition((j * cellSize + 10), (i * cellSize) + 10);
                window.draw(cell);*/

                cell.setSize(sf::Vector2f(cellSize, cellSize));
                cell.setPosition((j * cellSize), (i * cellSize));
                window.draw(cell);

                
            }
        }

        // afficher les noms des entreprises
             // affichage des noms des entreprises
        sf::Font font;
        if (!font.loadFromFile("Arial.ttf")) {
            // pb de lecture de la police
        }
        for (auto& val : vecCompanies) {
            int x = val.getX();
            int y = val.getY();
            sf::Text text;
            text.setFont(font);
            text.setString(val.getCompany()->getName());
            text.setCharacterSize(12);
            text.setFillColor(sf::Color::Black);
            //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
            text.setPosition(y * cellSize, (x - 1) * cellSize);
            //text.setPosition(20, 20);
            window.draw(text);
        }
       
        



        window.display();
    }
}

