#include "headers/init.hpp"

void MENU_Main::option1() { //list courses.
    std::cout << "Option 1\n";
}

void MENU_Main::option2() { //view course
    std::cout << "Option 2\n";
    QUIT_REQUEST = 0;
}

void MENU_Main::option3() { //add a course
    std::cout << "Option 3\n";
}

void MENU_Main::option4() { //remove a course
     std::cout << "Option 4\n";
}

void MENU_Main::option5() { //hide/unhide a course
    std::cout << "Option 5\n";
}

void MENU_Main::help() {
    std::cout << 
    "Commands:\n" <<
    "l - List Courses\n" <<
    "a - Add Course(s)\n" <<
    "r <courseID> - Remove a Course (You will be asked to confirm.)\n" <<
    "e <courseID> - View a Course (From here you can add/remove assessments.)\n"; 
}

void MENU_Main::quit() {
    QUIT_REQUEST = 1;
}