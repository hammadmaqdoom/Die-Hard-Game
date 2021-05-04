#include "health.hpp"
#include <iostream>

using namespace std;

Health::Health()
{
    // health_mover = {2, 2, 150, 60};
    health_src = {0, 0, 633, 153};
}

Health::Health(int x, int y, int w, int h)
{
    health_mover = {x, y, w, h};
    health_src = {0, 0, 633, 153};
}
void Health::draw(SDL_Renderer* renderer, SDL_Texture* tex)
{
    asset = tex;
    SDL_RenderCopy(renderer, asset, &health_src, &health_mover);
}

Health& Health::operator--(int) {
    count--;
    return *this;
}

// int Health::operator--(int) {
//     count--;
//     return count;
// }
// void Health::operator=(const int &i) {
//     count = i;
// }
bool Health::below0(){
    return count<=0;
}
int Health::getCount() {
    return count;
}

void Health::reset(){
    count = 4;
}