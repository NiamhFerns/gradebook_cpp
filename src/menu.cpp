#include "headers/menu.hpp"

void MENU_Main::option1() { //list courses.

}

void MENU_Main::option2() { //view course

}

void MENU_Main::option3() { //add a course

}

void MENU_Main::option4() { //remove a course

}

void MENU_Main::option5() { //hide/unhide a course

}

void MENU_Main::help() {

}

void MENU_Main::quit() {

}

void callMenu() {
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

//TODO
//Ideally each class would handle it's own help commands. This can be sorted out later.
//Add help to callMenu function as menu.help(menu.help);
//'help' will be an array of strings with all the help values.
//cycle through with a foreach loop.
//handle quit in the same way.