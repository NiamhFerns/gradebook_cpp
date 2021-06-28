#ifndef _MENU_H
#define _MENU_H

#include <iostream>
#include <string>
#include <vector>
#include "course.hpp"
#include "misc.hpp"

class MENU_Main {
public:
    void option1();
    void option2();
    void option3();
    void option4();
    void option5();
    void help();
    void quit();
};

//initialise menus

//template <typename T>
void callMenu();

#endif