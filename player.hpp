#pragma once
#include<SDL.h>
#include<iostream>
#include <SDL_mixer.h>
#include<vector>
#include"health.hpp"
using namespace std;

class Player
{   
    public:

    bool defend = false;
    bool punch = false;
    bool kick = false;
    SDL_Rect moverRect = {700, 300, 100, 150};
    SDL_Rect srcRect;
    string player_name;
    
    

    Player(int, int, int, int);
    Player(int, int, int, int, string);
    Player();
   ~Player();
    SDL_Rect* getmover(); // returns moverRect 
    SDL_Rect* getsrc(); // returns srcrect
    void move(SDL_Event*); //method for movement
    virtual void action(int ) = 0; //virtual method for actions
    void reset(); //resets the game
    int getHealth();
    protected:
    Mix_Chunk *kickSound;
    Mix_Chunk *punchSound;
    Mix_Chunk *defendSound;
   
};

