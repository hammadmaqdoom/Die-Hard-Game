#pragma once
#include <SDL.h>


class TextureManager
{
public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* gRenderer); //loads textures
    static SDL_Texture* LoadTexture(const char* fileName, int R, int G, int B);
    static SDL_Texture* LoadTexture(const char* fileName);

};
