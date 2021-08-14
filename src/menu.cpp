#include "headers/init.hpp"

//list courses.
void MENU_Main::option1() { 
    if (!COURSE_LIST.empty()) {
        int i = 1;
        for (Course course : COURSE_LIST) {
            if (course.getVisibility()) continue;
            std::cout << "<" << i << "> " << course.getID() << " - " << course.getName() << std::endl;
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

// Select a course to view.
void MENU_Main::option2() { 
    int id;
    std::cout << "Which course would you like to view? ~> ";
    std::cin >> id;

    // Find course in COURSE_LIST
    for (int i = 0; i < COURSE_LIST.size(); ++i) {
        if (COURSE_LIST[i].getID() == id) {
            CURRENTLY_VIEWING = i;
            std::cout << "You are currently viewing " << id << " - " << COURSE_LIST[CURRENTLY_VIEWING].getName() << std::endl;
        }
    }

    if (CURRENTLY_VIEWING == -1) std::cout << "That course could not be found.";
    
    // Enter into COURSE_MENU loop. Leave on quit request.
    while(!QUIT_REQUEST) {
        callMenu(COURSE_MENU, "[" + std::to_string(COURSE_LIST[CURRENTLY_VIEWING].getID()) + "] ~> ");
    }
    
    // Reset CURRENTLY_VIEWING and QUIT_REQUEST flag.
    CURRENTLY_VIEWING = -1;
    QUIT_REQUEST = 0; 
}

// Add a course.
void MENU_Main::option3() { 
    COURSE_LIST.emplace_back();
}

// Remove a course.
void MENU_Main::option4() { 
    int id, i = 0;
    std::string confirmation = "";

    // Get course and confirmation.
    std::cout << "Which course would you like to remove? ~> ";
    std::cin >> id;

    std::cout << "Are you sure you would like to remove " << id << "? (y/N) ~> ";
    getchar();
    getline(std::cin, confirmation);

    // Find course and print unfound error if needed.
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

// Set a courses hidden flag. (Toggle)
void MENU_Main::option5() { 
    int id;
    std::string confirmation = "";

    std::cout << "Which course would you like to change the visibility of? ~> ";
    std::cin >> id;
    
    // Find the course and 
    for (int i = 0; i < COURSE_LIST.size(); ++i) {
        if (COURSE_LIST[i].getID() == id) {
            // Set visibility and use CURRENTLY_VIEWING as a found/unfound check.
            CURRENTLY_VIEWING = i;
            COURSE_LIST[CURRENTLY_VIEWING].setVisibility();

            std::cout << id << " is now set to ";
            if (COURSE_LIST[CURRENTLY_VIEWING].getVisibility()) std::cout << "hidden.\n";
            else std::cout << "visible.\n";
            break; //If we've found the course, exit the loop
        }
    }

    if (CURRENTLY_VIEWING == -1) std::cout << "That course doesn't appear to be in the list.\n";
    else CURRENTLY_VIEWING = -1;
}

void MENU_Main::help() {
    std::cout << 
    "Commands:\n" <<
    "l - List Courses\n" <<
    "a - Add Course(s)\n" <<
    "r <courseID> - Remove a Course (You will be asked to confirm.)\n" <<
    "e <courseID> - View a Course (From here you can add/remove assessments.)\n"; 
}

// List assessments. (THIS WILL CALL A SEPERATE FUNCTION ON PORT TO NCURSES.)
void MENU_Course::option1() { 
    if (!COURSE_LIST[CURRENTLY_VIEWING].assessments.empty()) {
        int i = 1;
        for (Assessment assessment : COURSE_LIST[CURRENTLY_VIEWING].assessments) {
            std::cout << "<" << i << "> " << assessment.getMainLabel() << std::endl;
            //If    the number of assessment part is == 1, list assessment under mainLabel then 
            //      continue the loop.
            //Else  Loop through each assessmentPart and list them one by one.
            if (assessment.getNumberOfParts() == 1) {
                std::cout << " ┣  Status: [DUE/OVERDUE/GRADED/SUBMITTED/LATE SUBMISSION]\n";
                std::cout << " ┣  Current Grade: " << assessment.getAssessedGrade(i) << std::endl;
                std::cout << " ┗\n";
                continue;
            }

            for (int i = 0; i < assessment.getNumberOfParts(); ++i) {
                std::cout << " ┗ " << assessment.getMainLabel() << std::endl;
                std::cout << "  ┣  Current Grade: " << assessment.getAssessedGrade(i) << std::endl;
                std::cout << "  ┗\n";
                ++i;
            }
        }
    }

    else {
        std::cout << "You currently have no assessments added.\n";
    }
}

// Add an assessment.
void MENU_Course::option2() {
    std::string userIn; bool found = 0; int i;
    getchar();
    std::cout << "Is this a main assessment? ~> ";
    std::getline(std::cin, userIn);
    
    // Add main assessment label
    if (tolower(userIn[0]) == 'y') {
        COURSE_LIST[CURRENTLY_VIEWING].addAssessment();
        return;
    }

    // Loop through to find mainLabel then add assessmentPart
    userIn = "";
    std::cout << "Which group is this assessment part under? ~> ";
    std::getline(std::cin, userIn);
    for (i = 0; i < COURSE_LIST[CURRENTLY_VIEWING].assessments.size(); ++i) {
        if (COURSE_LIST[CURRENTLY_VIEWING].assessments[i].getMainLabel() == userIn) found = 1;
        std::cout << "FOUND!\n";
    }

    // If not found return.
    if (!found) {
        std::cout << "That doesn't appear to be an assessment in this course or " 
        << "you have no assessments added. Please check spelling and try again.\n";
        return;
    }

    std::cout << i << std::endl;
    COURSE_LIST[CURRENTLY_VIEWING].assessments[i - 1].addPart();
}

// Remove an assessment.
// TODO: Add ability to differentiate between assessmentParts and assessments.
void MENU_Course::option3() {
    std::string toRemove = "";
    getchar();
    std::cout << "Which course would you like to remove? ~> ";
    std::getline(std::cin, toRemove);
    bool found = 0;

    for (int i = 0; i < COURSE_LIST[CURRENTLY_VIEWING].assessments.size(); ++i) {
        if (COURSE_LIST[CURRENTLY_VIEWING].assessments[i].getMainLabel() == toRemove) {
            found = true;
            COURSE_LIST[CURRENTLY_VIEWING].assessments.erase(COURSE_LIST[CURRENTLY_VIEWING].assessments.begin() + i);
            std::cout << toRemove << " has been deleted.\n";
            break;
        }
    }

    if (!found) std::cout << "Sorry, but we could not find that assessment.\n";
}

void MENU_Course::option4() {

}

void MENU_Course::option5() {

}

void MENU_Course::option6() {

}

void MENU_Course::option7() {

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
