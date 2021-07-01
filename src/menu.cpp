#include "headers/init.hpp"

void MENU_Main::option1() { //list courses.
    if (!COURSE_LIST.empty()) {
        int i = 1;
        for (Course course : COURSE_LIST) {
            if (course.getVisibility()) continue;
            std::cout << "<" << i << "> " << course.getID() << " - " <<course.getName() << std::endl;
            std::cout << " ┣  Status: " << course.getStatus() << std::endl;
            std::cout << " ┣  Current Grade: " << course.getCurrentGrade() << std::endl;
            std::cout << " ┗\n";
            ++i;
        }
    }

    else {
        std::cout << "You currently have no courses added.\n";
    }
}

void MENU_Main::option2() { //view course
    int id;
    std::cout << "Which course would you like to view? ~> ";
    std::cin >> id;

    for (int i = 0; i < COURSE_LIST.size(); ++i) {
        if (COURSE_LIST[i].getID() == id) {
            CURRENTLY_VIEWING = &COURSE_LIST[i];
            std::cout << "You are currently viewing " << id << " - " << CURRENTLY_VIEWING->getName() << std::endl;
        }
    }

    if (CURRENTLY_VIEWING == nullptr) std::cout << "That course could not be found.";
    
    while(!QUIT_REQUEST) {
        callMenu(COURSE_MENU, "[" + std::to_string(CURRENTLY_VIEWING->getID()) + "] ~> ");
    }
    
    CURRENTLY_VIEWING = nullptr;
    QUIT_REQUEST = 0; //back to main menu and reset QUIT_REQUEST flag.
}

void MENU_Main::option3() { //add a course
    COURSE_LIST.emplace_back();
}

void MENU_Main::option4() { //remove a course
    int id, i = 0;
    std::string confirmation = "";

    std::cout << "Which course would you like to remove? ~> ";
    std::cin >> id;

    std::cout << "Are you sure you would like to remove " << id << "? (y/N) ~> ";
    getchar();
    getline(std::cin, confirmation);

    if (confirmation == "y" || confirmation == "Y") {
        bool courseFound = 0;
        for (int i = 0; i < COURSE_LIST.size(); ++i) {
            if (COURSE_LIST[i].getID() == id) { 
                std::cout << id << " - " << COURSE_LIST[i].getName() << " has been removed.\n";
                COURSE_LIST.erase(COURSE_LIST.begin() + i);
                courseFound = 1;
                break;
            }
        }

        if (!courseFound) std::cout << "That course doesn't appear to be in the list.\n";
    }
}

void MENU_Main::option5() { //hide/unhide a course
    int id;
    std::string confirmation = "";

    std::cout << "Which course would you like to change the visibility of? ~> ";
    std::cin >> id;
    
    for (int i = 0; i < COURSE_LIST.size(); ++i) {
        if (COURSE_LIST[i].getID() == id) {
            CURRENTLY_VIEWING = &COURSE_LIST[i];
            CURRENTLY_VIEWING->setVisibility();

            std::cout << id << " is now set to ";
            if (CURRENTLY_VIEWING->getVisibility()) std::cout << "hidden.\n";
            else std::cout << "visible.\n";
            break; //If we've found the course, exit the loop
        }
    }

    if (CURRENTLY_VIEWING == nullptr) std::cout << "That course doesn't appear to be in the list.\n";
    else CURRENTLY_VIEWING = nullptr;
}

void MENU_Main::help() {
    std::cout << 
    "Commands:\n" <<
    "l - List Courses\n" <<
    "a - Add Course(s)\n" <<
    "r <courseID> - Remove a Course (You will be asked to confirm.)\n" <<
    "e <courseID> - View a Course (From here you can add/remove assessments.)\n"; 
}

void MENU_Course::option1() {

}

void MENU_Course::option2() {

}

void MENU_Course::option3() {

}

void MENU_Course::option4() {

}

void MENU_Course::option5() {

}

void MENU_Course::help() {
    std::cout << 
    "Commands:\n" <<
    "l - List assessments\n" <<
    "a - Add assessment(s)\n" <<
    "r <label> - Remove an assessment (You will be asked to confirm.)\n" <<
    "g <label> - Add assessed grade to an assessment.\n" <<
    "w <label> - Change the weighting of an assessment.\n" <<
    "m <label> - Change the max grade of an assessment.\n"; 
}

void quit() {
    QUIT_REQUEST = 1;
}