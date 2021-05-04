#include"menu.hpp"

Menu::Menu(){};
Menu::~Menu(){};
void Menu::add_btns(Buttons *btn){
    btn_Lst.push_back(btn);
}

string Menu::check(int x, int y){
    string id, var = "FALSE";
    for (auto i: btn_Lst){
        id = i->check(x, y);
        if (id != "false"){
            var = id;

        }
    }
    return var;
}