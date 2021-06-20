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
    while(userIn != "Quit") {
        std::cout << "~> ";
        getline(std::cin, userIn);
        while (userIn.length() > 1 ) {
            std::cout << "Oops! That is not an option. ('h' for help)\n~> ";
            getline(std::cin, userIn);
        }

        // switch(/*USER AN ENUM HERE*/ 1) {
        //     case List courses:

        //         break;

        //     case Add course:
                
        //         break;

        //     case View course:
                
        //         break;

            
        //     case Delete course:

        //         break;

        //     case Quit:
        //         //save user output to txt document.
        //         std::cout << "Closing the GradeBook.\nGoodbye! c:"
        //         break;
        // }

    }
    return 0;
}