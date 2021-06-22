#include "headers/course.hpp"

//Constructor for course object. Needs at least a courseID a courseName and the status/type of course.
Course::Course() {
    std::string tempInput;
    
    //unsigned int courseID, std::string courseName, bool hidden, bool passfail
    std::cout << "Course Name ~> ";
    getline(std::cin, courseName);
    
    std::cout << "Course ID ~> ";
    getline(std::cin, tempInput);
    courseID = stoi(tempInput);
    
    //Is this a pass/fail course?
    std::cout << "Is this a pass/fail course (y/N)? ~> ";
    getline(std::cin, tempInput);
    
    tempInput = tolower(tempInput[0]);
    if (tempInput == "y") {
        passFail = 1;
    }
}

// void Course::addAssessment(std::string name, unsigned short maxGrade, unsigned short weighting) {

// }

// void Course::setRoles() {

// }

std::string Course::getName() { return courseName; }

unsigned int Course::getID() { return courseID; }

// int Course::getCurrentGrade() {
//     return 0;
// }

// std::string Course::getRoles() {
//     return "Not written yet. c:";
// }

unsigned short Course::getMarks(std::string assessment) {
    return 0;
}

std::string Course::getStatus() { return courseStatus; }

void Course::listAssessments() {
    int i = 0;
    if (!assessments.empty()) {
        for (Assessment assessment : assessments) {
            std::cout << i + 1 << " - " << assessment.getLabel() << std::endl;
            ++i;
        }
    }

    else {
        std::cout << "You currently have no assessments added to this course.\n";
    }
}

// void removeCourse(int courseID) {
    
// }

// void viewCourse(int courseID) {

// }

// void listCourses(bool showHidden) {

// }

