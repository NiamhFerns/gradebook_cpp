#include <iostream>
#include <string>
#include <vector>
#include "assessment.hpp"

class Course {
    enum rolesIndex {
        major = 0,
        minor = 1,
        elective = 2,
        prereq = 3
    };

protected:
    std::string courseName, subjectArea, courseStatus = "In Progress...";
    unsigned int courseID;
    //Course roles: [0] Major, [1] Minor, [2] Elective, [3] Prerequisit Course
    bool hiddenCourse, passFail = 0, roles[4]; 
    std::vector<Assessment> assessments;

public:
    Course();

    void setRoles();

    void addAssessment(std::string name, unsigned short maxGrade, unsigned short weighting);

    std::string getName();
    unsigned int getID();
    int getCurrentGrade();
    std::string getRoles();
    unsigned short getMarks(std::string assessment);
    std::string getStatus();

    void listAssessments();
};

void removeCourse(int courseID);
void addCourse(std::string courseName, int courseID, unsigned char role);
void viewCourse(int courseID);
void listCourses(bool showHidden);
