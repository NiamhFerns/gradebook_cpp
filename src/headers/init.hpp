#ifndef _INIT_H
#define _INIT_H

#include "menu.hpp"
#include "course.hpp"

bool bookInit(std::string path);
void loadCourses();


//our global variables
static std::fstream GRADEBOOK;
static std::vector<Course> COURSE_LIST;
extern Course *CURRENTLY_VIEWING;
extern bool QUIT_REQUEST;

static MENU_Main MAIN_MENU;

#endif