#ifndef _COURSE_H
#define _COURSE_H

#include <iostream>
#include <string>
#include <vector>
#include "assessment.hpp"

class Course {
protected:
    std::string courseName, subjectArea, courseStatus = "In Progress...";
    unsigned int courseID;
    //Course roles: [0] Major, [1] Minor, [2] Elective, [3] Prerequisit Course
    bool hiddenCourse, passFail = 0, roles[4]; 
    std::vector<Assessment> assessments;

public:
    Course();
    Course(std::string courseData[]);

    void addAssessment(); //user add
    void addAssessment(std::string assessmentData[]); //when loading

    void setRoles();
    void setVisibility();

    std::string getName();
    unsigned int getID();
    int getCurrentGrade();
    std::string getRoles();
    unsigned short getMarks(std::string assessment);
    std::string getStatus();
    bool getVisibility();

    void getAssessments();
};

void removeCourse(int courseID);
void addCourse(std::string courseName, int courseID, unsigned char role);
void viewCourse(int courseID);
void listCourses(bool showHidden);

#endif