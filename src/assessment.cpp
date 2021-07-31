#include "headers/assessment.hpp"

Assessment::Assessment
(
    std::string labelIn, 
    std::string dueDateIn, 
    std::string handinDateIn,
    unsigned short gradeIn,
    unsigned short maxGradeIn,
    unsigned short weightingIn,
    unsigned short latePenaltyIn
)
{
    
}

std::string Assessment::getLabel() {
}

unsigned short Assessment::getAssessedGrade() { return assessedGrade; }

void Assessment::setAssessedGrade(unsigned short grade) {
        if (grade > maxGrade) {
            std::cout << "That is not a valid grade. Please try again.\n";
            return;
        }

        assessedGrade = grade;
}

