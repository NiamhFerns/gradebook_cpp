#include "headers/course.hpp"

//Constructor for course object. Needs at least a courseID a courseName and the status/type of course.
Course::Course() {
    std::string tempInput;
    
    //unsigned int courseID, std::string courseName, bool hidden, bool passfail
    std::cout << "Course Name ~> ";
    getchar(); //clear buffer.
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

Course::Course(std::string courseData[]) {
    //input string from gradebook.txt: "name;id;subjectArea;status;hidden;passfail;roles"
    enum { //index for each value in courseData[]
        E_name = 0,
        E_id = 1,
        E_subject = 2,
        E_status = 3,
        E_hidden = 4,
        E_passFail = 5,
        E_roles = 6
    };

    courseName = courseData[E_name];
    courseID = stoi(courseData[E_id]);
    subjectArea = courseData[E_subject];
    courseStatus = courseData[E_status];
    hiddenCourse = stoi(courseData[E_hidden]);
    passFail = stoi(courseData[E_passFail]);
    for (int i = 0; i < 4; ++i) {
        roles[i] = courseData[E_roles][i];
    }
}

// General use. Will be used to make the assessment when creating a new assessment.
void Course::addAssessment() {
    std::string label = "", dueDate;
    unsigned short grade, weighting;
    
     //buffer clear;
    std::cout << "What is the assessment label? ~> ";
    getline(std::cin, label);
    std::cout << "When is this assessment due? ~> ";
    getline(std::cin, dueDate);
    std::cout << "What is the max grade and weighting for this course. ~> ";
    // This still needs error handling or it'll crash easily.
    std::cin >> grade >> weighting;

    assessments.emplace_back(label, dueDate, "none", 0, grade, weighting, 100); 
}

// Needs an array FULL with the data.
void Course::addAssessment(std::string assessmentData[]) {
    // This is gross... I'm sorry.
    // Key: 0 = label 1 = dueDate 2 = handinDate 3 = assessedGrade 4 = maxGrade, 5 = weighting, 6 = latePenalty.
    assessments.emplace_back(assessmentData[0], assessmentData[1], assessmentData[2], 
                             std::stoi(assessmentData[3]), std::stoi(assessmentData[4]),
                             std::stoi(assessmentData[5]), std::stoi(assessmentData[6]));
}

//GETTERS

std::string Course::getName() { return courseName; }

unsigned int Course::getID() { return courseID; }

std::string Course::getCurrentGrade() {
    return "";
}

std::string Course::getRoles() {
    return "Not written yet. c:";
}

unsigned short Course::getMarks(std::string assessment) {
    return 0;
}

std::string Course::getStatus() { return courseStatus; }

bool Course::getVisibility() {
    return hiddenCourse;
}

void Course::getAssessments() { // This is currently unused until port to ncurses.
    int i = 0;
    if (!assessments.empty()) {
        //convert this to a point pls...
        for (Assessment assessment : assessments) {
            
            //if the assessments are only one, print the maintainable as the only label. 
            //else print every label in assessment under the main label as the assessment name.
            // i - Main Label
            //    -> subassessment 1
            //    -> subassessment 2
            //    -> etc etc
            
            std::cout << i + 1 << " - " << assessment.getMainLabel() << std::endl;
            if (assessment.getNumberOfParts() > 1) {
                for (int j = 0; j < assessment.getNumberOfParts(); ++j) {
                    std::cout << "    " << assessment.getLabel(j);
                }
            }
            
            ++i;
        }
    }

    else {
        std::cout << "You currently have no assessments added to this course.\n";
    }
}

//SETTERS

void Course::setRoles() {

}

void Course::setVisibility() {
    hiddenCourse = !hiddenCourse;
}
