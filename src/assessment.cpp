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
    label = labelIn;
    dueDate = dueDateIn;
    handinDate = handinDateIn;
    assessedGrade = gradeIn;
    maxGrade = maxGradeIn;
    weighting = weightingIn;
    latePenalty = latePenaltyIn;
}

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