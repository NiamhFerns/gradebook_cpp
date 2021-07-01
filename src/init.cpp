#include "headers/init.hpp"

std::fstream GRADEBOOK;

bool bookInit() {
    GRADEBOOK.open("gradebook.txt", std::fstream::in | std::fstream::app);

    if (!GRADEBOOK.is_open()) std::cout << "Gradebook failed to open... :c\n";
    else loadCourses();

    CURRENTLY_VIEWING = nullptr;
    QUIT_REQUEST = 0;

    return 1;
}

void loadCourses() {
    std::string currentLine = "";
    while(std::getline(GRADEBOOK, currentLine)) {
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