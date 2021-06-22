#include <iostream>
#include <string>
#include <vector>
#include "assessment.hpp"

class Course {
    enum rolesIndex {
        major = 0,
        minor = 1,
        elective = 2,
        Prerequisit = 3
    };

protected:
    std::string courseName, subjectArea;
    unsigned int courseID;
    //Course roles: [0] Major, [1] Minor, [2] Elective, [3] Prerequisit Course
    bool hiddenCourse, passFail, roles[3]; 
    std::vector<Assessment> assessments;
public:
    Course(unsigned int courseID, std::string courseName, bool hidden, bool passfail);

    void setRoles();

    void addAssessment(std::string name, unsigned short maxGrade, unsigned short weighting);

    int getCurrentGrade();
    int getCourseRoles();
    unsigned short getMarks(std::string assessment);

    void listAssessments();
};

void removeCourse(int courseID);
void addCourse(std::string courseName, int courseID, unsigned char role);
void viewCourse(int courseID);
void listCourses(bool showHidden);