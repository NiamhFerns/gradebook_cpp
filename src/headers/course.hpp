#include <iostream>
#include <string>
#include <vector>
#include "assessment.hpp"

class Course {
protected:
    std::string courseName, subjectArea, coordinators[10];
    short numberOfCoords = 1;
    unsigned short courseID;
    unsigned char role;
    
    std::vector<Assessment> assessments;
public:
    Course();

    void addAssessment();
    void setRole();
    void addCoordinator();
};