#include "TextureManager.h"
#include "game.hpp"
#include <SDL.h>
#include <SDL_image.h>

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* renderer)
{
    SDL_Surface* tempSurface = IMG_Load(fileName);
    Uint32 colorkey = SDL_MapRGB(tempSurface->format, 0,255,80); //removes black background
    SDL_SetColorKey(tempSurface, 1, colorkey);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}

SDL_Texture* TextureManager::LoadTexture(const char* fileName, int R, int G, int B)
{
    SDL_Surface* tempSurface = IMG_Load(fileName);
    Uint32 colorkey = SDL_MapRGB(tempSurface->format, R, G, B);
    SDL_SetColorKey(tempSurface, 1, colorkey);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::gRenderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}


SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
    SDL_Surface* tempSurface = IMG_Load(fileName);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::gRenderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}
