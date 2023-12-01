//

#include "SFMLWindow.hpp"
#include <SFML/Graphics.hpp>
#include "Board.hpp"


SFMLWindow::SFMLWindow(Board b, float scale, std::string name)
{
    board = std::make_shared<Board>(b);
    nbRow = b.getNbRow();
    nbCol = b.getNbCol();
    windowSizeX = nbRow * scale;
    windowSizeY = nbCol * scale;
    cellSize = (float)windowSizeX / nbRow;
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
void SFMLWindow::print() 
{
    sf::RectangleShape cell;
    cell.setSize(sf::Vector2f(cellSize, cellSize));

    sf::RenderWindow window(sf::VideoMode(windowSizeX, windowSizeY), name);


    // vector de square (contient les square associé a chaque company de la board)
    //std::vector<Square> vecCompanies;

    while (window.isOpen())
    {

        // il faut effacer avant de reafficher
        window.clear();

        for (int i = 0; i < nbRow; ++i)
        {
            for (int j = 0; j < nbCol; ++j)
            {

                float newValue = scaleValue(board->getSquare(i, j)->getValue(), -3.8, 3.8, 0, 255);

                cell.setFillColor(sf::Color(80, newValue, 10));

                // affichage de la couleur

                if (newValue<80)
                {
                    cell.setFillColor(sf::Color(60, 160, 210));

                }

                if (board->getSquare(i, j)->isCompany())
                {
                    vecCompanies.push_back(board->getSquare(i,j));
                    cell.setFillColor(sf::Color::Red);
                }

                cell.setSize(sf::Vector2f(cellSize, cellSize));
                cell.setPosition((j * cellSize), (i * cellSize));
                window.draw(cell);

                
            }
        }

        // afficher les noms des entreprises
        sf::Font font;
        if (!font.loadFromFile("Arial.ttf")) {
            // pb de lecture de la police
        }

        for (auto& val : vecCompanies) 
        {
            int x = val->getX();
            int y = val->getY();
            sf::Text text;
            text.setFont(font);
            std::shared_ptr<PrimaryCompany> castP = std::dynamic_pointer_cast<PrimaryCompany>(val->getCompany());
            if (castP)
            {
                text.setString(castP->getName());
            }
            else 
            {
                std::shared_ptr<SecondaryCompany> castS = std::dynamic_pointer_cast<SecondaryCompany>(val->getCompany());
                text.setString(castS->getName());
            }
            text.setCharacterSize(12);
            text.setFillColor(sf::Color::Black);
            //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
            text.setPosition(y * cellSize, (x - 1) * cellSize);
            //text.setPosition(20, 20);
            window.draw(text);
        }
       
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // evenement lies au clavier
            if (event.type == sf::Event::KeyPressed)
            {
                // touche T
                if (event.key.code == sf::Keyboard::T)
                {
                    // Afficher quelque chose dans la console
                    std::cout << "tour passe" << std::endl;
                    board->addRound();
                }
            }

            // evenement lies a la souris
            if (event.type == sf::Event::MouseButtonPressed)
            {
                // clic gauche
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int mouseX = static_cast<int>(event.mouseButton.x / 10);
                    int mouseY = static_cast<int>(event.mouseButton.y / 10);

                    std::shared_ptr<Square> s = getCompanyAtPos(mouseX, mouseY);
                    if (s)
                    {
                        s->getCompany()->print();

                    }
                 
                }
            }


        }


        window.display();
    }
}



std::shared_ptr<Square> SFMLWindow::getCompanyAtPos(int mouseX, int mouseY)
{
    for (auto& val : vecCompanies)
    {
        if ((val->getX() == mouseY)
            &&
            (val->getY() == mouseX))
        {
            return val;
        }
    }
    return nullptr;
}