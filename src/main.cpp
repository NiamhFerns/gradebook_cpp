#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::string userIn = "", gradebookPath;

    //Select a gradebook.
    std::cout << "Please enter in a path to your Gradebook or 'Quit' to exit.\n~> ";
    getline(std::cin, gradebookPath);

    if(gradebookPath == "Quit") return 0;

    //Init gradebook file.
    gradebookPath += "/gradebook.txt";
    std::fstream gradebook(gradebookPath);
    while(!gradebook.good()) {
        std::cout << "A gradebook could not be found in this directory. Would you like to make one? (y/N/Quit)\n~> ";
        getline(std::cin, userIn);
        
        //If the gradebook could not be found, alert user.
        if(userIn == "Quit") {
            return 0;
        }
        else if (userIn == "y" || userIn == "Y") {
            gradebook.open(gradebookPath.c_str(), std::fstream::out);
        }
        else {
            std::cout << "Please enter in a new path.\n~> ";
            getline(std::cin, gradebookPath);
            gradebookPath += "/gradebook.txt";
            gradebook.open(gradebookPath.c_str());
        }
    }
    gradebook.open(gradebookPath.c_str(), std::fstream::in | std::fstream::app);

    //Main program loop.
    userIn = "";
    std::cout << "*************************************\n";
    std::cout << "      Welcome to the Gradebook.\n";
    std::cout << "     What would you like to do?\n";
    std::cout << "*************************************\n";
    bool QuitRequested = 0;
    while(!QuitRequested) {
        std::cout << "~> ";
        getline(std::cin, userIn);

        for (int i = 0; i < userIn.length(); ++i) {
            userIn[i] = tolower(userIn[i]);
        }
        if (userIn == "quit") {
            QuitRequested = 1;
        }
        //This is gross but I'm bad and can't think of a better way...
        
        if (userIn == "l") {
            std::cout << userIn << std::endl;
        } 
        else if (userIn == "e") {
            std::cout << userIn << std::endl;
        }
        else if (userIn == "a") {
            std::cout << userIn << std::endl;
        }
        else if (userIn == "r") {
            std::cout << userIn << std::endl;
        }
        else {
            std::cout << "Oops! That is not an option. ('h' for help)\n";
        }
        
    }
    return 0;
}