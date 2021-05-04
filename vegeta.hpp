#pragma once
#include"player.hpp"
#include<SDL.h>

class Vegeta: public Player
{
   SDL_Rect moverRect = {700, 300, 100, 150};
   public:

   Vegeta (int, int, int, int);
   ~Vegeta();
   void action(int); //perfom actions
};

