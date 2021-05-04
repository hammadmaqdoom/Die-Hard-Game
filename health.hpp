#include "SDL.h"
// #include"player.hpp"
#pragma once

class Health{
    SDL_Rect health_mover; //Position of each heart
    SDL_Rect health_src;
    SDL_Texture* asset;
    

public:
    int count = 4; //Initial number of lives
    Health();
    Health(int, int, int, int);
    void draw(SDL_Renderer*, SDL_Texture*);
    Health& operator -- (int); //Decrement count when life object decrement
    // void operator = (const int&); //Assign integer value to count
    // int operator -- (int);
    bool below0(); //Check if life has become 0
    int getCount(); //Get number of lives
    void reset();
};