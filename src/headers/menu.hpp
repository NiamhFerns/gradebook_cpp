#ifndef _MENU_H
#define _MENU_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

template <typename T>
void callMenu(T menu) {
    int optionSelection;
    std::cin >> optionSelection; //DO NOT ENTER LETTERS

    switch (optionSelection) {
        case 1:
            menu.option1();
            break;
        
        case 2:
            menu.option2();
            break;
        
        case 3:
            menu.option3();
            break;
        
        case 4:
           menu.option4();
            break;

        case 5:
            menu.option5();
            break;

        case -1:
            menu.quit();
            break;

        default:
            menu.help();
            break;
    }
}

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

#endif