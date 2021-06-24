#ifndef _MENU_H
#define _MENU_H

#include <iostream>
#include <string>
#include <vector>
#include "course.hpp"
#include "globals.hpp"

class MENU_Main {
public:
    virtual void option1(); //List Courses
    virtual void option2(); //View Course
    virtual void option3(); //Add Course
    virtual void option4(); //Remove Course
    virtual void option5(); //Toggle hidden courses
    virtual void quit();
    virtual void help();
};

class MENU_CourseEntry : public MENU_Main {
    void option1(); //List Assessments
    void option2(); //Add Assessment
    void option3(); //Remove Assessment
    void option4(); //Change a grade.
    void option5(); //Change Weighting
};

template <typename T>
void callMenu(T menu);

#endif