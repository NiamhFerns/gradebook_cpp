#ifndef _INIT_H
#define _INIT_H

#include "menu.hpp"
#include "course.hpp"

bool bookInit();
void loadCourses();
void splitString(std::string output[], std::string input, char delim);

//our global variables
extern std::fstream GRADEBOOK;
extern std::vector<Course> COURSE_LIST;
extern Course *CURRENTLY_VIEWING;
extern bool QUIT_REQUEST;

static MENU_Main MAIN_MENU;
static MENU_Course COURSE_MENU;

#endif