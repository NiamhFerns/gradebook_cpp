#ifndef _GLOBALS_H
#define _GLOBALS_H

#include <iostream>
#include <vector>
#include <string>
#include "course.hpp"
#include "menu.hpp"

class Globals {
public:
    static std::vector<Course> COURSE_LIST;
    static MENU_Main MAIN_MENU;
    static Course *CURRENTLY_VIEWING;
};

#endif