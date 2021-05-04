#pragma once
#include<SDL.h>
#include<iostream>
#include <SDL_mixer.h>
#include<vector>
#include<random>
using namespace std;

class Enemy
{   
    public:
    bool punch = false;
    bool kick = false;
    SDL_Rect moverRect = {310, 300, 100, 150};
    SDL_Rect srcRect;
    SDL_Texture* asset;
    

    Enemy();
    SDL_Rect* getmover();
    SDL_Rect* getsrc();
    void reset();
    void action();
    void move();
    void draw(SDL_Renderer* renderer, SDL_Texture* tex);
    
    protected:
    Mix_Chunk *kickSound;
    Mix_Chunk *punchSound;
    Mix_Chunk *defendSound;
   
};
