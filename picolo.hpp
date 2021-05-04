#pragma once
#include"player.hpp"
#include<SDL.h>
class Picolo: public Player
{
    public:
    Picolo (int, int, int, int);
    ~Picolo();
    void action(int ); //perform action
};

