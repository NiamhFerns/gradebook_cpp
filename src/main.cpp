#include "headers/init.hpp"

std::vector<Course> COURSE_LIST;
int CURRENTLY_VIEWING = -1;
bool QUIT_REQUEST = 0;

int main() {
    std::string userIn = "", gradebookPath;

    //Init gradebook file.
    bookInit();
    

    //Main program loop.
    userIn = "";
    std::cout << "*************************************\n";
    std::cout << "      Welcome to the Gradebook.\n";
    std::cout << "     What would you like to do?\n";
    std::cout << "*************************************\n";
    while(!QUIT_REQUEST) {
        callMenu(MAIN_MENU, "[/] ~> ");
    }

    //save the text file
    //close the text file

    return 0;
}