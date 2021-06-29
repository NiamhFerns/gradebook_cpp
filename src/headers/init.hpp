#ifndef _INIT_H
#define _INIT_H

#include "menu.hpp"
#include "course.hpp"

bool bookInit(std::string path);
void loadCourses();


//our global variables
static std::fstream GRADEBOOK;
static std::vector<Course> COURSELIST;
static Course *CURRENTLY_VIEWING = nullptr;
static bool QUIT_REQUEST = 0;

static MENU_Main MAIN_MENU;

#endif