#include "headers/menu.hpp"

//------------------
//MAIN MENU OPTIONS:
//------------------
//List Courses
void MENU_Main::option1() {
    if (!Globals::COURSE_LIST.empty()) {
        for (Course course : Globals::COURSE_LIST) {
            if (!course.getVisibility() || Globals::showHidden) {
                std::cout << course.getID() << " - " <<course.getName() << std::endl;
                std::cout << "Status: " << course.getStatus() << " Current Grade: " << course.getCurrentGrade() << std::endl;
            }
        }
    }

    else {
        std::cout << "You currently have no courses added. Menu option 'a' to add a course.\n";
    }
}

//View Course
void MENU_Main::option2() {
    std::cout << "VIEWING COURSE :D\n";
}

//Add Course
void MENU_Main::option3() {
    Globals::COURSE_LIST.emplace_back();
}

//Remove Course
void MENU_Main::option4() {
    int toRemove = 0, courseID;

    if (Globals::COURSE_LIST.empty()) {
        std::cout << "You currently have no courses added. Menu option 'a' to add a course.\n";
        return;
    }

    std::cout << "Which would would you like to remove (by ID)? ~> ";
    getchar();
    std::cin >> courseID;

    for (Course course : Globals::COURSE_LIST) {
        if (course.getID() == courseID) {
            Globals::COURSE_LIST.erase(Globals::COURSE_LIST.begin() + toRemove);
            return;
        }
        toRemove++;
    }

    std::cout << "You don't seem to have that as a course." 
    << "Make sure you have entered it in correctly or press 'l' to view current courses.\n";
    
}

//Toggle Hidden Courses
void MENU_Main::option5() {
    Globals::showHidden = !Globals::showHidden;
    
    std::cout << "Hidden courses are now ";
    if (Globals::showHidden) std::cout << "shown.\n";
    else std::cout << "not shown\n";

    MENU_Main::option1;
}

void MENU_Main::quit() {
    quitRequested(0);
}

void MENU_Main::help() {
    printHelp(0);
}

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

void MENU_Main::quit() {
    quitRequested(1);
}

void MENU_CourseEntry::help() {
    printHelp(1);
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