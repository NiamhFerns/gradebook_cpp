#ifndef _INIT_H
#define _INIT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "menu.hpp"
#include "course.hpp"

bool bookInit(std::string path);
void loadCourses();


//our global variables
static std::fstream GRADEBOOK;
static std::vector<Course> COURSELIST;
static Course *CURRENTLY_VIEWING;

#endif