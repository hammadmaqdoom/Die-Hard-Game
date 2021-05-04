#include"player.hpp"

Player::Player(int x, int y, int w, int h){
    srcRect = {x, y, w, h};
}

Player::Player(int x, int y, int w, int h, string name){
    srcRect = {x, y, w, h};
    player_name = name;
}

Player::Player(){
    srcRect = {30, 75, 110, 155};
}

Player::~Player(){
    delete kickSound;
    delete punchSound;
    delete defendSound;
}

SDL_Rect* Player::getmover(){
    return &moverRect;
}

SDL_Rect* Player::getsrc(){
    return &srcRect;
}


void Player::move(SDL_Event* event){
    
    int speed = 15;
    switch(event->key.keysym.sym){
        case SDLK_LEFT:
            if (moverRect.x <= 0)
                moverRect.x == 0;
            else{
                cout<<"LEFT"<<endl;
                moverRect.x -= speed;
            }
            cout<<"speed "<<speed<<endl;
            break;
        case SDLK_RIGHT:
            if (moverRect.x >= 900)
                moverRect.x == 900;
            else{
                moverRect.x += speed;
                cout<<"RIGHT"<<endl;
            }
            cout<<"speed "<< speed<<endl;
            break;

        case SDLK_UP:
            if (moverRect.y <= 285)
                moverRect.y == 285;
            else{
                moverRect.y -= speed;
                moverRect.h-=5;
                moverRect.w-=5;
                cout<<"RIGHT"<<endl;
            }
            cout<<"speed "<< speed<<endl;
            break;

        case SDLK_DOWN:
            if (moverRect.y >= 365)
                moverRect.y == 365;
            else{
                moverRect.y += speed;
                moverRect.h+=5;
                moverRect.w+=5;
                cout<<"RIGHT"<<endl;
            }
            cout<<"speed "<< speed<<endl;
            break;
        
              
        }   
         
}


void Player::action(int event){       

}

void Player::reset(){
    moverRect = {700, 300, 100, 150};
    // health reset
    // Health::count =4;
}

