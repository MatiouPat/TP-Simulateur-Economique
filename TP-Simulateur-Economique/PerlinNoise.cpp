// PerlinNoise.cpp

#include "PerlinNoise.hpp"
#include <cmath>
#include <iostream>

// Fonction pour interpoler linéairement entre deux valeurs
float PerlinNoise::lerp(float a, float b, float t) {
    return a + t * (b - a);
}

// Fonction pour générer un bruit de Perlin 1D
float PerlinNoise::perlinNoise1D(int x) {
    int n = x * 57;
    n = (n << 13) ^ n;
    return static_cast<float>((1.0 - ((n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0));
}

// Fonction pour interpoler le bruit de Perlin
float PerlinNoise::fade(float t) {
    return t * t * t * (t * (t * 6 - 15) + 10);
}

// Fonction pour générer le bruit de Perlin 2D
float PerlinNoise::perlinNoise2D(float x, float y) {
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

    // Mélanger la table de permutation
    for (int i = 0; i < 512; ++i) {
        int j = i + perlinNoise1D(i) * 255;
        j = j & 255; // Assurez-vous que j reste dans les limites de 0 à 255
        std::swap(p[i], p[j]);
    }

    int A = p[X] + Y;
    int B = p[X + 1] + Y;

    return lerp(lerp(grad(p[A], x, y), grad(p[B], x - 1, y), u),
        lerp(grad(p[A + 1], x, y - 1), grad(p[B + 1], x - 1, y - 1), u), v);
}

// Fonction pour calculer le gradient
float PerlinNoise::grad(int hash, float x, float y) {
    int h = hash & 15;
    float grad = 1 + (h & 7); // Gradient value 1-8
    if (h & 8) grad = -grad; // Randomly invert half of them
    return (grad * x); // Gradient value times x distance
}
