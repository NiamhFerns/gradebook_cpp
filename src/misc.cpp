#include "headers/misc.hpp"

void printHelp(unsigned char i) {
    switch (i) {
        case 0:
        std::cout << "Commands:\n" <<
        "l - List Courses\n" <<
        "a - Add Course(s)\n" <<
        "r <courseID> - Remove a Course (You will be asked to confirm.)\n" <<
        "e <courseID> - View a Course (From here you can add/remove assessments.)\n"; 
        break;

        case 1:
        std::cout << "No commands added yet. Case 1.\n";
        break;

        case 2:
        std::cout << "No commands added yet. Case 2.\n";
        break;

        case 3:
        std::cout << "No commands added yet. Case 3.\n";
        break;

        default:
        std::cout << "No commands added yet. Case 4.\n";
        break;
    }
}

bool bookInit(std::string path) {
    std::string userIn = "";
    GRADEBOOK.open(path.c_str());

    while(!GRADEBOOK.good()) {
        std::cout << "A gradebook could not be found in this directory. Would you like to make one? (y/N/Quit)\n~> ";
        getline(std::cin, userIn);
        
        //If the gradebook could not be found, alert user.
        if(userIn == "Quit" || userIn == "quit") {
            return 0;
        }
        else if (userIn == "y" || userIn == "Y") {
            GRADEBOOK.open(path.c_str(), std::fstream::out);
        }
        else {
            std::cout << "Please enter in a new path.\n~> ";
            getline(std::cin, path);
            path += "/gradebook.txt";
            GRADEBOOK.open(path.c_str());
        }
    }

    GRADEBOOK.open(path.c_str(), std::fstream::in | std::fstream::app);

    loadCourses();

    return 1;
}

void loadCourses() {

}