#include "headers/misc.hpp"

void printHelp(unsigned char i) {
    switch (i) {
        case '0':
        std::cout << "Commands:\n" <<
        "l - List Courses\n" <<
        "a - Add Course(s)\n" <<
        "r <courseID> - Remove a Course (You will be asked to confirm.)\n" <<
        "e <courseID> - View a Course (From here you can add/remove assessments.)\n"; 
        break;

        case '1':
        std::cout << "No commands added yet. Case 1.\n";
        break;

        case '2':
        std::cout << "No commands added yet. Case 2.\n";
        break;

        case '3':
        std::cout << "No commands added yet. Case 3.\n";
        break;

        case '4':
        std::cout << "No commands added yet. Case 4.\n";
        break;
    }
}