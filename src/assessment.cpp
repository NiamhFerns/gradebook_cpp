#include "headers/assessment.hpp"

PartStats::PartStats (unsigned short partGradeIn,
                      std::string labelIn,
                      std::string dueDateIn,
                      std::string handinDateIn,
                      bool dropped) 
{
    label = labelIn;
    partGrade = partGradeIn;
    dueDate = dueDateIn;
    handinDate = handinDateIn;
    droppedFromScore = dropped;
};

Assessment::Assessment(std::string labelIn, 
                       std::string dueDateIn, 
                       std::string handinDateIn,
                       unsigned short gradeIn,
                       unsigned short maxGradeIn,
                       unsigned short weightingIn,
                       unsigned short latePenaltyIn)
{
    //define the base assessment
    //should there be only one assessment this will be the only part.
    assessmentStats.push_back(
        PartStats(
            0,
            "part-" + std::to_string(assessmentStats.size() + 1),
            dueDateIn,
            handinDateIn,
            0 
    ));


}

std::string Assessment::getMainLabel() {
    return mainLabel;
}

std::string Assessment::getLabel(int labelIndex) {
    return assessmentStats[labelIndex].label;
}

int Assessment::getNumberOfParts() {
    return assessmentStats.size();
}

unsigned short Assessment::getAssessedGrade(int assessmentIndex) {  
    return assessmentStats[assessmentIndex].partGrade;
}

void Assessment::setAssessedGrade(unsigned short grade) {
        if (grade > maxGrade) {
            std::cout << "That is not a valid grade. Please try again.\n";
            return;
        }
}

