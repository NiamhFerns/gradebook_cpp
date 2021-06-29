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

template <typename T>
void callMenu(T menu) {
    int optionSelection;
    std::cin >> optionSelection; //DO NOT ENTER LETTERS

    switch (optionSelection) {
        case 1:
            std::cout << "Option 1\n";
            break;
        
        case 2:
            std::cout << "Option 2\n";
            break;
        
        case 3:
            std::cout << "Option 3\n";
            break;
        
        case 4:
            std::cout << "Option 4\n";
            break;

        case 5:
            std::cout << "Option 5\n";
            break;

        case -1:
            std::cout << "Option quit\n";
            break;

        default:
            printHelp(0);
            break;
    }
}

#endif