#include <iostream>
#include <string>
#include <vector>
#include "assessment.hpp"

class Course {
protected:
    std::string courseName, subjectArea;
    unsigned short courseID;
    unsigned char role;
    bool hiddenCourse;
    
    std::vector<Assessment> assessments;
public:
    Course();

    void setRole();

    void addAssessment();
    void addCoordinator();

    int getCurrentGrade();

};

void removeCourse(int courseID);
void addCourse(std::string courseName, int courseID, unsigned char role);
void viewCourse(int courseID);
void listCourses(bool showHidden);