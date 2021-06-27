#ifndef _MISC_H
#define _MISC_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

static std::fstream GRADEBOOK;

void printHelp(unsigned char i);
bool bookInit(std::string path);

#endif