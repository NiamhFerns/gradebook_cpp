#include "headers/assessment.hpp"

std::string Assessment::getLabel() {
    return label;
}

void Assessment::setAssessedGrade(unsigned short grade) {
        if (grade > maxGrade) {
            std::cout << "That is not a valid grade. Please try again.\n";
            return;
        }

        assessedGrade = grade;
}