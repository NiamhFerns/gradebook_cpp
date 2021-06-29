#include "headers/init.hpp"

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