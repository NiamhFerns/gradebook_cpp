#ifndef _MENU_H
#define _MENU_H

#include <iostream>
#include "globals.hpp"

// template <typename T>
void callMenu();
void printHelp(unsigned char i);

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


#endif