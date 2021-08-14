#include "headers/init.hpp"

std::fstream GRADEBOOK;

bool bookInit() {
    GRADEBOOK.open("gradebook.txt", std::fstream::in | std::fstream::app);

    if (!GRADEBOOK.is_open()) std::cout << "Gradebook failed to open... :c\n";
    else loadCourses();

    CURRENTLY_VIEWING = -1;
    QUIT_REQUEST = 0;

    return 1;
}

void loadCourses() {
    std::string currentLine = "";
    CURRENTLY_VIEWING = 0;
    while(std::getline(GRADEBOOK, currentLine)) {
        std::string lineData[10] = {""};
        
        switch(currentLine[0]) {
            case '#':
                currentLine = currentLine.substr(1, currentLine.length());
                splitString(lineData, currentLine, ';');
                COURSE_LIST.emplace_back(lineData);
                CURRENTLY_VIEWING++;
                break;

            case '@':
                currentLine = currentLine.substr(1, currentLine.length());
                splitString(lineData, currentLine, ';');
                COURSE_LIST[CURRENTLY_VIEWING].addAssessment(lineData);
                break;

            default:
                break;
        }
    }
    CURRENTLY_VIEWING = -1;
}

void splitString(std::string output[], std::string input, char delim) {
    int i = 0;
    for (char ch : input) {
        if (ch == delim) ++i;
        else output[i] += ch;
    }
}