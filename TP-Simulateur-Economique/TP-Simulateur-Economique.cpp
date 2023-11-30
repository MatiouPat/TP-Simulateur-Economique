#include <iostream>
#include <deque>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

#include "Employee.hpp"
#include "Company.hpp"
#include "PrimaryCompany.hpp"
#include "SecondaryCompany.hpp"
#include "Square.hpp"
#include "Board.hpp"
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
            std::shared_ptr<Square> square(new Square(x, y, static_cast<float>(x + y), x + y));

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

            /*
            auto it = std::find_if(entreprises.begin(), entreprises.end(),
                [x, y](Company& e) { return e.getPositionX() == x && e.getPositionY() == y; });
            */

            /*if (it != entreprises.end()) {
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
            else {*/
            if (true) {
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
    // 1 case = combien de pixel 
    float scale = 20;

    Board b(30, 30);
    b.generateMap(0.1f);

    std::vector<Company> companiesList;


    std::shared_ptr<Company> c = std::make_shared<Company>(Company("Scierie", 1, 1000, std::vector<Employee>(), std::map<int, Merchandise>()));
    b.addCompany(c, 1, 2);

    std::shared_ptr<Company> c2 = std::make_shared<Company>(Company("Scierie 2", 1, 1000, std::vector<Employee>(), std::map<int, Merchandise>()));
    b.addCompany(c2, 10, 3);
    
    b.printBoard();
    SFMLWindow().print(b, 30);
  
    return 0;

}
