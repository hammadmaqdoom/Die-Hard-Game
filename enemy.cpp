#include"enemy.hpp"

Enemy::Enemy(){ //Enemy Create
    srcRect = {898, 76, 84, 142};
}

SDL_Rect* Enemy::getmover(){
    return &moverRect;
}

SDL_Rect* Enemy::getsrc(){
    return &srcRect;
}

void Enemy::draw(SDL_Renderer* renderer, SDL_Texture* tex) //Enemy Render
{
    asset = tex;
    SDL_RenderCopy(renderer, asset, &srcRect, &moverRect);
    srcRect = {898, 76, 84, 142};
}

void Enemy::reset()
{
    moverRect = {310, 350, 100, 150};
}

void Enemy::action() //enemy attack actions
{
    int x = rand()%15;
    if (x <= 4) 
    {   kick = true;
        srcRect = {660, 392, 142, 120};
    } //kick
    else if (x >= 5) {

        srcRect = {677, 574, 137, 110}; 
        punch = true;
        }
        //punch
 // else if (x >= 10) srcRect = {1106, 232, 64, 134}; //defend

}

void Enemy::move(){
    int randNum = (rand() % 3) + 1;

    int speed = 15;
    switch(randNum){
        case 1:
            if (moverRect.x <= 0)
                moverRect.x == 0;
            else{
                moverRect.x -= speed;
            }
            break;
        case 2:
            if (moverRect.x >= 900)
                moverRect.x == 900;
            else{
                moverRect.x += speed;
            }
            break;

        case 3:
            if (moverRect.y <= 285)
                moverRect.y == 285;
            else{
                moverRect.y -= speed;
                // moverRect.h-=5;
                // moverRect.w-=5;
            }
            break;

        case 4:
            if (moverRect.y >= 365)
                moverRect.y == 365;
            else{
                moverRect.y += speed;
                // moverRect.h+=5;
                // moverRect.w+=5;
            }
            break;
        
              
        }
}