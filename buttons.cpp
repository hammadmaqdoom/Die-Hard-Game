#include"buttons.hpp"


Buttons::Buttons(int x, int y, int w, int h,string name){
    moverRect = {x, y, w, h};
    this -> name = name;
}

string Buttons::check(int x, int y){
    if (x < moverRect.w && x > moverRect.x){
        if (y < moverRect.h && y > moverRect.y){
            return name;
        }
    }

    return "false";
}