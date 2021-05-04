#pragma once
#include"player.hpp"
#include<SDL.h>

class Goku: public Player
{
    public:
    Goku (int, int, int, int); //constructor
    ~Goku(); //destructor
    void action(int); //perform actions
};

