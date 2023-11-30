// PerlinNoise.hpp
#pragma once

class PerlinNoise
{
    // graine permettant de generer une carte aleatoire
    float seed;

public :

    PerlinNoise();
    float lerp(float a, float b, float t);
    float perlinNoise1D(int x);
    float fade(float t);
    float perlinNoise2D(float x, float y);
    float grad(int hash, float x, float y);

};