#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "headers/globals.hpp"
#include "headers/menu.hpp"

int main() {
    std::string userIn = "", gradebookPath;

    //Select a gradebook.
    std::cout << "Please enter in a path to your Gradebook or 'Quit' to exit.\n~> ";
    getline(std::cin, gradebookPath);

    if(gradebookPath == "Quit") return 0;

    //Init gradebook file.
    gradebookPath += "/gradebook.txt";
    bookInit(gradebookPath);
    

    //Main program loop.
    userIn = "";
    std::cout << "*************************************\n";
    std::cout << "      Welcome to the Gradebook.\n";
    std::cout << "     What would you like to do?\n";
    std::cout << "*************************************\n";
    bool QuitRequested = 0;
    while(!QuitRequested) {
        callMenu();
    }

    //save the text file
    //close the text file

    return 0;
}