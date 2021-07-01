#ifndef _MENU_H
#define _MENU_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void quit();

template <typename T>
void callMenu(T menu, std::string prompt) {
    int optionSelection;
    std::cout << prompt;
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
            quit();
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
    void printPrompt();
};

class MENU_Course {
public:
    void option1();
    void option2();
    void option3();
    void option4();
    void option5();
    void help();
    void printPrompt();
};

#endif