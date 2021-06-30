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

    CURRENTLY_VIEWING = nullptr;
    QUIT_REQUEST = 0;

    return 1;
}

void loadCourses() {
    std::string currentLine;
    while(getline(GRADEBOOK, currentLine)) {
        std::string lineData[10] = {""};
        switch(currentLine[0]) {
            case '#':
                currentLine = currentLine.substr(1, currentLine.length());
                splitString(lineData, currentLine, ';');
                COURSE_LIST.emplace_back(lineData);
                CURRENTLY_VIEWING = &COURSE_LIST[COURSE_LIST.size()];
                break;

            case '@':
                currentLine = currentLine.substr(1, currentLine.length());
                splitString(lineData, currentLine, ';');
                CURRENTLY_VIEWING->addAssessment(lineData);
                break;

            default:
                break;
        }
    }
    CURRENTLY_VIEWING = nullptr;
}

void splitString(std::string output[], std::string input, char delim) {
    int i = 0;
    for (char ch : input) {
        if (ch == delim) ++i;
        else output[i] += ch;
    }
}