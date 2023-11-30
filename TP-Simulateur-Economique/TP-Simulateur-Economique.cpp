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




/**
* Permet d'importer la carte vers un fichier
* @param nameFile Nom du fichier
**/
void exporterCarte(const std::vector<std::vector<float>>& carte, const std::string& fileName) {
    std::ofstream fichier(fileName);

    if (fichier.is_open()) {
        for (const auto& ligne : carte) {
            for (float valeur : ligne) {
                fichier << valeur << " ";
            }
            fichier << std::endl;
        }

        std::cout << "Carte exportee avec succes vers : " << fileName << std::endl;
    }
    else {
        std::cerr << "Erreur lors de l'exportation du fichier." << std::endl;
    }
}


/**
* Permet d'importer la carte depuis un fichier
* @param nameFile Nom du fichier
**/
std::vector<std::vector<float>> importerCarte(const std::string& fileName) {
    std::vector<std::vector<float>> carte;
    std::ifstream fichier(fileName);

    if (fichier.is_open()) {
        float valeur;
        std::vector<float> ligne;

        while (fichier >> valeur) {
            ligne.push_back(valeur);
        }

        // Ajouter la ligne à la carte
        carte.push_back(ligne);

        std::cout << "Carte importee avec succes depuis : " << fileName << std::endl;
    }
    else {
        std::cerr << "Erreur lors de l'importation du fichier." << std::endl;
    }

    return carte;
}

/**
* Permet d'importer la liste des entreprises depuis un fichier
* @param fileName Nom du fichier depuis lequel on importe les company
**/ 
std::vector<std::vector<std::string>> importCompanies(const std::string& fileName) {
    std::vector<std::vector<std::string>> listCompanies;
    std::vector<std::string> row;
    std::string line, word;
    std::ifstream fichier(fileName);

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
        std::cout << "Import successful from : " << fileName << std::endl;
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


int main()
{
    // 1 case = combien de pixel 
    float scale = 10;


    // Generation de la board avec perlin
    Board b(50, 50);
    b.generateMap(0.05f);


    // Creation des Merchandise
    Merchandise bois1("Bois", 100.0f, std::vector<MerchandiseType>(MerchandiseType::RAW));
    Merchandise planche1("Planche", 100.0f, std::vector<MerchandiseType>(MerchandiseType::CONSUMMABLE));

    // Creation des Company
    std::shared_ptr<PrimaryCompany> scierie1 = std::make_shared<PrimaryCompany>(PrimaryCompany("Scierie", 1, 1000, std::vector<Employee>(), std::map<int, Merchandise>()));
    std::shared_ptr<SecondaryCompany> c2 = std::make_shared<SecondaryCompany>(SecondaryCompany("Usine de bateau", 1, 1000, std::vector<Employee>(), std::map<int, Merchandise>()));
    std::shared_ptr<PrimaryCompany> c3 = std::make_shared<PrimaryCompany>(PrimaryCompany("Ferme a coton", 1, 1000, std::vector<Employee>(), std::map<int, Merchandise>()));
    std::shared_ptr<SecondaryCompany> c4 = std::make_shared<SecondaryCompany>(SecondaryCompany("Usine de textile", 1, 1000, std::vector<Employee>(), std::map<int, Merchandise>()));
    std::shared_ptr<SecondaryCompany> c5 = std::make_shared<SecondaryCompany>(SecondaryCompany("Usine de meuble", 1, 1000, std::vector<Employee>(), std::map<int, Merchandise>()));

    b.addCompany(scierie1, 1, 2);
    b.addCompany(c2, 10, 3);
    b.addCompany(c3, 6, 6);
    b.addCompany(c4, 5, 17);
    b.addCompany(c5, 20, 20);


    // Creation des Transformation
    Transformation transfo_bois_table(planche1, bois1, *scierie1, 110.0f, 1);

    

    // Print
    b.printBoard();
    SFMLWindow().print(b, scale);
  
    return 0;

}
