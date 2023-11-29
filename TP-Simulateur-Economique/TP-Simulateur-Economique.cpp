#include <iostream>
#include <deque>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>

#include "Square.hpp"
#include "Board.hpp"


// Fonction pour interpoler linÃ©airement entre deux valeurs
float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

// DÃ©claration de la fonction grad
float grad(int hash, float x, float y);

// Fonction pour gÃ©nÃ©rer un bruit de Perlin 1D
float perlinNoise1D(int x) {
    int n = x * 57;
    n = (n << 13) ^ n;
    return static_cast<float>((1.0 - ((n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0));
}

// Fonction pour interpoler le bruit de Perlin
float fade(float t) {
    return t * t * t * (t * (t * 6 - 15) + 10);
}

// Fonction pour gÃ©nÃ©rer le bruit de Perlin 2D
float perlinNoise2D(float x, float y) {
    int X = static_cast<int>(std::floor(x)) & 255;
    int Y = static_cast<int>(std::floor(y)) & 255;

    x -= std::floor(x);
    y -= std::floor(y);

    float u = fade(x);
    float v = fade(y);

    int p[512]; // Tableau de permutation
    for (int i = 0; i < 512; ++i) {
        p[i] = i;
    }

    // MÃ©langer la table de permutation
    for (int i = 0; i < 512; ++i) {
        int j = i + perlinNoise1D(i) * 255;
        j = j & 255; // Assurez-vous que j reste dans les limites de 0 Ã  255
        std::swap(p[i], p[j]);
    }

    int A = p[X] + Y;
    int B = p[X + 1] + Y;

    return lerp(lerp(grad(p[A], x, y), grad(p[B], x - 1, y), u),
        lerp(grad(p[A + 1], x, y - 1), grad(p[B + 1], x - 1, y - 1), u), v);
}

// Fonction pour calculer le gradient
float grad(int hash, float x, float y) {
    int h = hash & 15;
    float grad = 1 + (h & 7); // Gradient value 1-8
    if (h & 8) grad = -grad; // Randomly invert half of them
    return (grad * x); // Gradient value times x distance
}

// Fonction pour gÃ©nÃ©rer une carte avec du bruit de Perlin
std::vector<std::vector<float>> genererCarte(int largeur, int hauteur, float frequence) {
    std::vector<std::vector<float>> carte(largeur, std::vector<float>(hauteur));

    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            carte[x][y] = perlinNoise2D(x * frequence, y * frequence);
        }
    }

    return carte;
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

        std::cout << "Carte exportÃ©e avec succÃ¨s vers : " << nomFichier << std::endl;
    }
    else {
        std::cerr << "Erreur lors de l'exportation du fichier." << std::endl;
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

        // Ajouter la ligne Ã  la carte
        carte.push_back(ligne);

        std::cout << "Carte importÃ©e avec succÃ¨s depuis : " << nomFichier << std::endl;
    }
    else {
        std::cerr << "Erreur lors de l'importation du fichier." << std::endl;
    }

    return carte;
}

// Fonction pour afficher la carte
void afficherCarte(const std::vector<std::vector<float>>& carte) {
    for (const auto& ligne : carte) {
        for (float valeur : ligne) {
            char character = ' ';

            // Utiliser diffÃ©rents caractÃ¨res pour reprÃ©senter les hauteurs
            if (valeur < -0.8) {
                character = '#';  // CaractÃ¨re plein pour les basses altitudes
            }
            else if (valeur < -0.6) {
                character = 'H';
            }
            else if (valeur < -0.4) {
                character = 'h';
            }
            else if (valeur < -0.2) {
                character = 'h';
            }
            else if (valeur < 0.2) {
                character = '.';
            }
            else if (valeur < 0.4) {
                character = ':';
            }
            else if (valeur < 0.6) {
                character = 'o';
            }
            else if (valeur < 0.8) {
                character = 'O';
            }
            else {
                character = '#';  // CaractÃ¨re plein pour les hautes altitudes
            }

            std::cout << character << ' ';
        }
        std::cout << std::endl;
    }
}


int main()
{
    const int largeur = 40;
    const int hauteur = 20;
    const float frequence = 0.1f;

    std::cout << "Choisissez une option : " << std::endl;
    std::cout << "1. Generer une nouvelle carte" << std::endl;
    std::cout << "2. Importer une carte depuis un fichier" << std::endl;

    int choix;
    std::cin >> choix;

    std::shared_ptr<Board> board = std::shared_ptr<Board>(new Board(5, 5));
    board->addChessboardCase(SOUTH_EAST);
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

    if (choix == 1) {
        // GÃ©nÃ©rer une nouvelle carte avec du bruit de Perlin
        std::vector<std::vector<float>> carte = genererCarte(largeur, hauteur, frequence);

        // Afficher la carte generÃ©e
        std::cout << "Carte gÃ©nÃ©rÃ©e :" << std::endl;
        afficherCarte(carte);

        // Exporter la carte vers un fichier
        exporterCarte(carte, "carte.txt");
    }
    else if (choix == 2) {
        // Importer une carte depuis un fichier
        std::vector<std::vector<float>> carteImportee = importerCarte("carte.txt");

        // Afficher la carte importÃ©e
        std::cout << "Carte importÃ©e :" << std::endl;
        afficherCarte(carteImportee);
    }
    else {
        std::cerr << "Option non valide." << std::endl;
        return 1;
    }

    return 0;

}