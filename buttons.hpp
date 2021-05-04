#pragma once
#include<SDL.h>
#include<iostream>
using namespace std;
class Buttons
{
   SDL_Rect moverRect = {0,0,0,0};
   string name;
   public:
   Buttons(int, int, int, int,string); //constructor
   string check(int , int); // checks if mouse  is clicked on button
};
