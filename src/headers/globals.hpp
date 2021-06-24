#ifndef _GLOBALS_H
#define _GLOBALS_H

#include <iostream>
#include <vector>
#include <string>
#include "course.hpp"
#include "menu.hpp"

struct Globals {
    static std::vector<Course> COURSE_LIST;
    static MENU_Main MAIN_MENU;
    static Course *CURRENTLY_VIEWING;
    static bool showHidden;
};

void quitRequested(unsigned short mode);

#endif