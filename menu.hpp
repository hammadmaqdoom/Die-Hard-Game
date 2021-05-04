#pragma once
#include"buttons.hpp"
#include<list>
#include<iostream>
using namespace std;
class Menu
{
    list<Buttons*> btn_Lst; //button list
    public:
    Menu();
    ~Menu();
    void add_btns(Buttons*); //adds buttons
    string check(int, int); //returns the id of button if clicked
};