#include "headers/menu.hpp"

//------------------
//MAIN MENU OPTIONS:
//------------------
//List Courses

//TODO
//Ideally each class would handle it's own help commands. This can be sorted out later.
//Add help to callMenu function as menu.help(menu.help);
//'help' will be an array of strings with all the help values.
//cycle through with a foreach loop.
//handle quit in the same way.

//------------------
//MAIN MENU OPTIONS:
//------------------
//List Assessments
// void MENU_Main::option1() {

// }

// //Add Assessment
// void MENU_CourseEntry::option2() {

// }

// //Remove Assessment
// void MENU_CourseEntry::option3() {

// }

// //Change a grade.
// void MENU_CourseEntry::option4() {

// }

// //Change Weighting
// void MENU_CourseEntry::option5() {

// }

// void MENU_Main::quit() {
//     quitRequested(1);
// }

// void MENU_CourseEntry::help() {
//     printHelp(1);
// }

//template <typename T>
void callMenu() {
    int optionSelection;
    std::cin >> optionSelection;

    switch (optionSelection) {
        case 1:
            std::cout << "Option 1";
            break;
        
        case 2:
            std::cout << "Option 2";
            break;
        
        case 3:
            std::cout << "Option 3";
            break;
        
        case 4:
            std::cout << "Option 4";
            break;

        case 5:
            std::cout << "Option 5";
            break;

        case -1:
            std::cout << "Option quit";
            break;

        default:
            std::cout << "Option help";
            break;
    }
}