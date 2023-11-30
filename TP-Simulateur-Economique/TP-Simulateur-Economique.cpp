#include <iostream>
#include <deque>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

#include "PrimaryCompany.hpp"
#include "SecondaryCompany.hpp"
#include "Square.hpp"
#include "Board.hpp"
#include "Company.hpp"
#include "PerlinNoise.hpp"

#include "SFMLWindow.hpp"

/*
* Générer une carte avec du bruit de Perlin
*/
std::deque<std::deque<std::shared_ptr<Square>>> generateMap(int largeur, int hauteur, float frequence)
{
    std::deque<std::deque<std::shared_ptr<Square>>> map(largeur, std::deque<std::shared_ptr<Square>>(hauteur));
    PerlinNoise perlinN;

    for (int x = 0; x < largeur; ++x)
    {
        for (int y = 0; y < hauteur; ++y)
        {
            float bitState = perlinN.perlinNoise2D(x * frequence, y * frequence);
            std::shared_ptr<Square> square(new Square(x, y, x + y, x + y));

            if (bitState < -0.8)
            {
                square->setState(SquareState::UNTRAVERSABLE);
            }
            else
            {
                square->setState(SquareState::TRAVERSABLE);
            }
            map[x][y] = square;
        }
    }

    return map;
}

// Fonction pour exporter la carte vers un fichier
void exporterCarte(const std::vector<std::vector<float>>& carte, const std::string& nomFichier) {
    std::ofstream fichier(nomFichier);

    if (fichier.is_open()) {
        for (const auto& ligne : carte) {
            for (float valeur : ligne) {
                fichier << valeur << " ";
            }
            fichier << std::endl;
        }

        std::cout << "Carte exportee avec succes vers : " << nomFichier << std::endl;
    }
    else {
        std::cerr << "Erreur lors de l'exportation du fichier." << std::endl;
    }
}

void afficherCarte(const std::vector<std::vector<float>>& carte,  std::vector<Company>& entreprises) {
    for (int y = 0; y < carte[0].size(); ++y) {
        for (int x = 0; x < carte.size(); ++x) {
            char character = ' ';

            auto it = std::find_if(entreprises.begin(), entreprises.end(),
                [x, y](Company& e) { return e.getPositionX() == x && e.getPositionY() == y; });

            if (it != entreprises.end()) {
                if (it->getName() == "scierie") {
                    character = 'S';
                }
                else if (it->getName() == "usine_meuble") {
                    character = 'M';
                }
                else if (it->getName() == "ferme_coton") {
                    character = 'C';
                }
                else if (it->getName() == "usine_textile") {
                    character = 'T';
                }
                else if (it->getName() == "usine_bateaux") {
                    character = 'B';
                }
            }
            else {
                float valeur = carte[x][y];

                if (valeur < -0.8) {
                    character = '#';
                }
                else if (valeur < -0.2) {
                    character = '°';
                }
                else if (valeur < 0.2) {
                    character = '.';
                }
                else if (valeur < 0.4) {
                    character = ',';
                }
                else if (valeur < 0.6) {
                    character = ':';
                }
                else if (valeur < 0.8) {
                    character = ';';
                }
                else {
                    character = '!';
                }
            }

            std::cout << character << ' ';
        }
        std::cout << std::endl;
    }
}

// Fonction pour importer la carte depuis un fichier
std::vector<std::vector<float>> importerCarte(const std::string& nomFichier) {
    std::vector<std::vector<float>> carte;
    std::ifstream fichier(nomFichier);

    if (fichier.is_open()) {
        float valeur;
        std::vector<float> ligne;

        while (fichier >> valeur) {
            ligne.push_back(valeur);
        }

        // Ajouter la ligne à la carte
        carte.push_back(ligne);

        std::cout << "Carte importee avec succes depuis : " << nomFichier << std::endl;
    }
    else {
        std::cerr << "Erreur lors de l'importation du fichier." << std::endl;
    }

    return carte;
}

// Fonction pour importer la liste des entreprises depuis un fichier
std::vector<std::vector<std::string>> importCompanies(const std::string& nameFile) {
    std::vector<std::vector<std::string>> listCompanies;
    std::vector<std::string> row;
    std::string line, word;
    std::ifstream fichier(nameFile);

    if (fichier.is_open()) {
        while (fichier >> line) {
            row.clear();
            std::stringstream str(line);
            while (getline(str, word, ';'))
            {
                row.push_back(word);
            }
            listCompanies.push_back(row);
        }
        std::cout << "Import successful from : " << nameFile << std::endl;
    }
    else {
        std::cerr << "Error from importing." << std::endl;
    }
    for (int i = 0; i < listCompanies.size(); i++)
    {
        for (int j = 0; j < listCompanies[i].size(); j++)
        {
            std::cout << listCompanies[i][j] << " ";
        }
        std::cout << "\n";
    }
    return listCompanies;
}


float min(std::vector<std::vector<float>> vec)
{
    float min = 10000;
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec.at(0).size(); ++j)
        {
            if (vec[i][j] < min)
            {
                min = vec[i][j];
            }
        }
    }
    return min;
}
float max(std::vector<std::vector<float>> vec)
{
    float max = 0;
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec.at(0).size(); ++j)
        {
            if (vec[i][j] > max)
            {
                max = vec[i][j];
            }
        }
    }
    return max;
}

int main()
{

    const int largeur = 20;
    const int hauteur = 20;
    const float frequence = 0.1f;
    std::deque<std::deque<std::shared_ptr<Square>>> carte = generateMap(largeur, hauteur, frequence);
    std::vector<Company> entreprises;
    Company entreprise = Company("scririe", 0, 0, Square(4, 8, 0, 0), {}, {});
    entreprises.push_back(entreprise);
    Board board(carte);
    board.printBoard(entreprises);
    std::deque<std::shared_ptr<Square>> cheminTest = board.searchShortestPath(19, 2, 4, 8);
    std::cout << "Chemin recommande pour aller de  (" << 19 << "," << 2 << ") a (" << 4 << "," << 8 << ") : \n";
    for (auto i : cheminTest)
    {
        std::cout << "  ( " << i->getX() << " , " << i->getY() << " ) \n";
    }
    //afficherCarte(carte, entreprises);
    
    /*

    std::cout << "Choisissez une option : " << std::endl;
    std::cout << "1. Generer une nouvelle carte" << std::endl;
    std::cout << "2. Importer une carte depuis un fichier" << std::endl;

    int choix;
    std::cin >> choix;

    std::shared_ptr<Board> board = std::shared_ptr<Board>(new Board(5, 5));
    //board->addChessboardCase(SOUTH_EAST);
    board->printChessboard();
    int startX = 1;
    int startY = 1;
    int endX = 4;
    int endY = 4;
    std::deque<std::shared_ptr<Square>> cheminTest = board->searchShortestPath(startX, startY, endX, endY);
    std::cout << "Chemin recommande pour aller de  (" << startX << "," << startY << ") a (" << endX << "," << endY << ") : \n";
    for (auto i : cheminTest)
    {
        std::cout << "  ( " << i->getX() << " , " << i->getY() << " ) \n";
    }

    std::cout << " \n" << std::endl;
    */


    /*if (choix == 1) {
        // GÃ©nÃ©rer une nouvelle carte avec du bruit de Perlin
        std::vector<std::vector<float>> carte = genererCarte(largeur, hauteur, frequence);

        // Afficher la carte generÃ©e
        std::cout << "Carte gÃ©nÃ©rÃ©e :" << std::endl;
        //afficherCarte(carte);

        // Exporter la carte vers un fichier
        exporterCarte(carte, "carte.txt");
    }
    else if (choix == 2) {
        // Importer une carte depuis un fichier
        std::vector<std::vector<float>> carteImportee = importerCarte("carte.txt");

        // Afficher la carte importÃ©e
        std::cout << "Carte importÃ©e :" << std::endl;
        //afficherCarte(carteImportee);
    }
    else {
        std::cerr << "Option non valide." << std::endl;
        return 1;
    }*/


    // Tests affichage graphique

    std::vector<std::vector<float>> carte;
    carte = genererCarte(200, 200, 0.02f);
    std::vector<Company> test;
    Company comp("name", 1, 1000, Square(2, 2), std::vector<Employee>(), std::map<int, Merchandise>());
    test.push_back(comp);
    //afficherCarte(carte, test);
    std::cout << min(carte) << std::endl;
    std::cout << max(carte) << std::endl;
    SFMLWindow().print(carte, 4);

    return 0;

}
