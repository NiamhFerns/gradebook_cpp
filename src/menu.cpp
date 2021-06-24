#include "headers/menu.hpp"

//------------------
//MAIN MENU OPTIONS:
//------------------
//List Courses
void MENU_Main::option1() {
    if (!Globals::COURSE_LIST.empty()) {
        for (Course course : Globals::COURSE_LIST) {
            std::cout << course.getID() << " - " <<course.getName() << std::endl;
            std::cout << "Status: " << course.getStatus() << " Current Grade: " << course.getCurrentGrade() << std::endl;
        }
    }

    else {
        std::cout << "You currently have no courses added. Menu option 'a' to add a course.\n";
    }
}

//View Course
void MENU_Main::option2() {

}

//Add Course
void MENU_Main::option3() {

}

//Remove Course
void MENU_Main::option4() {

}

//Toggle Hidden Courses
void MENU_Main::option5() {

}

void MENU_Main::quit() {

}

void MENU_Main::help() {

}

//------------------
//MAIN MENU OPTIONS:
//------------------
//List Assessments
void MENU_Main::option1() {

}

//Add Assessment
void MENU_CourseEntry::option2() {

}

//Remove Assessment
void MENU_CourseEntry::option3() {

}

//Change a grade.
void MENU_CourseEntry::option4() {

}

//Change Weighting
void MENU_CourseEntry::option5() {

}

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