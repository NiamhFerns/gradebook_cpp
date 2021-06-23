#include "headers/menu.hpp"

template <typename T>
void callMenu(T menu) {
    int optionSelection;
    std::cin >> optionSelection;

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