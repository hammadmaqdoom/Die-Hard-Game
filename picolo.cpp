#include"picolo.hpp"

Picolo::Picolo(int x, int y, int w, int h){
    srcRect = {x, y, w, h};
    kickSound = Mix_LoadWAV("audios//pic-kick.wav");
	punchSound = Mix_LoadWAV("audios//pic-punch.wav");
	defendSound  = Mix_LoadWAV("audios//pic-defence.wav");
}
Picolo::~Picolo(){
    delete kickSound;
    delete punchSound;
    delete defendSound;
}
void Picolo::action(int event){
        // cout<<"runing "<<"\n";

    if (event == 0){ // idle
        srcRect.y = 75;
        srcRect.h = 150;
        srcRect.w = 130;
        srcRect.x = 30;
    }

    else if (event == 1){ // defence
        srcRect.y = 230;
        // srcRect.h = 140;
        srcRect.w = 127;
        if (srcRect.x ==30)
         Mix_PlayChannel(-1,defendSound,0);
        if (srcRect.x < 254){
            srcRect.x += 127;
        }
        else{
            defend = false;
        }

    }

    else if (event == 2){ // kick
        srcRect.y = 385;
        // srcRect.h = 145;
        srcRect.w = 157;
        if (srcRect.x ==30)
         Mix_PlayChannel(-1,kickSound,0);
        if (srcRect.x < 785){
            srcRect.x += 157;
        }
        else{
            kick = false;
        }

    }

    else if (event == 3){ // punch
        srcRect.y = 543;
        // srcRect.h = 140;
        srcRect.w = 164;
        if (srcRect.x ==30)
         Mix_PlayChannel(-1,punchSound,0);
        if (srcRect.x < 656){
            srcRect.x += 164;
        }
        else{
            punch = false;
        }

    }
}

