#include"goku.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Goku::Goku(int x, int y, int w, int h){
    srcRect = {x, y, w, h};
    kickSound = Mix_LoadWAV("audios//kick.wav");
	punchSound = Mix_LoadWAV("audios//goku-punch.wav");
	defendSound = Mix_LoadWAV("audios//Gok4.wav");
}
Goku::~Goku(){
    delete kickSound;
    delete punchSound;
    delete defendSound;
}
void Goku::action(int event){
        // cout<<"runing "<<"\n";

    if (event == 0){ // idle
        srcRect.y = 75;
        // srcRect.h = 150;
        srcRect.w = 145;
        srcRect.x = 30;
    }

    else if (event == 1){ // defence
        srcRect.y = 230;
        // srcRect.h = 140;
        srcRect.w = 110;
        if (srcRect.x ==30)
         Mix_PlayChannel(-1,defendSound,0);
        if (srcRect.x < 250){
            srcRect.x += 110;
        }
        else{
            defend = false;
        }

    }

    if (event == 2){ // kick
        
        srcRect.y = 385;
        // srcRect.h = 145;
        srcRect.w = 147;
        if (srcRect.x ==30)
         Mix_PlayChannel(-1,kickSound,0);
        if (srcRect.x < 765){
            srcRect.x += 147;
        }
        else{
            kick = false;
        }
        
    }

    if (event == 3){ // punch
        
        srcRect.y = 543;
        // srcRect.h = 140;
        srcRect.w = 173;
        if (srcRect.x ==30)
        Mix_PlayChannel(-1,punchSound,0);
        if (srcRect.x < 519){
            srcRect.x += 173;
        }
        else{
            punch = false;
        }

    }
    
}


