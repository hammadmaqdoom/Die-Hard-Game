#include"vegeta.hpp"

Vegeta::Vegeta(int x, int y, int w, int h){
    srcRect = {x, y, w, h};
    kickSound = Mix_LoadWAV("audios//Veg7.wav");
	punchSound = Mix_LoadWAV("audios//veg-punch.wav");
    defendSound = Mix_LoadWAV("audios//Veg3.wav");
	
}
Vegeta::~Vegeta(){
    delete kickSound;
    delete punchSound;
    delete defendSound;
}
void Vegeta::action(int event){
    // cout<<"runing "<<"\n";

    if (event == 0){ // idle
        srcRect.y = 75;
        srcRect.h = 155;
        srcRect.w = 110;
        srcRect.x = 30;
    }

    else if (event == 1 && defend){ // defence
        srcRect.y = 230;
        // srcRect.h = 140;
        srcRect.w = 105;
        if (srcRect.x ==30)
         Mix_PlayChannel(-1,defendSound,0);
        if (srcRect.x < 235){
            srcRect.x += 105;
        }
        else{
            defend = false;
        }

    }

    if (event == 2 && kick) // kick
    {
        srcRect.y = 385;
        // srcRect.h = 145;
        srcRect.w = 174;
        if (srcRect.x ==30)
         Mix_PlayChannel(-1,kickSound,0);
        if (srcRect.x < 696){
            srcRect.x += 174;
        }
        else{
            kick = false;
        }

    }

    if (event == 3 && punch){ // punch
        srcRect.y = 543;
        // srcRect.h = 140;
        srcRect.w = 168;
        if (srcRect.x ==30)
         Mix_PlayChannel(-1,punchSound,0);
        if (srcRect.x < 504){
            srcRect.x += 168;
        }
        else{
            punch = false;
        }

    }
    
}



