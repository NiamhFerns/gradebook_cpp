#include "headers/assessment.hpp"

PartStats::PartStats (std::string labelIn, unsigned short partGradeIn, 
                      unsigned short partMaxIn, std::string dueDateIn, 
                      std::string handinDateIn, bool dropped) 
{
    label = labelIn;
    partGrade = partGradeIn;
    partMax = partMaxIn;
    dueDate = dueDateIn;
    handinDate = handinDateIn;
    droppedFromScore = dropped;
};

Assessment::Assessment(std::string labelIn, std::string dueDateIn, 
                       std::string handinDateIn, unsigned short gradeIn,
                       unsigned short maxGradeIn, unsigned short weightingIn,
                       unsigned short latePenaltyIn)
{
    //define the base assessment
    //should there be only one assessment this will be the only part.
    assessmentStats.push_back(
        PartStats(
            "Part " + std::to_string(assessmentStats.size() + 1),
            0,
            100,
            dueDateIn,
            handinDateIn,
            0 
    ));

    //define the main label
    mainLabel = labelIn;
}

void Assessment::addPart() {
    assessmentStats.emplace_back(
        PartStats(
            "Part " + std::to_string(assessmentStats.size() + 1),
            0,
            100,
            "none",
            "none",
            0
    ));

    for (int i = 0; i < assessmentStats.size(); ++i) {
        // Keep track of individual weightings for each part and base them off
        // total base assessment's weighting. (This is almost always given in 
        // course syllabus.
        assessmentStats[i].weighting = weighting / assessmentStats.size();
    }
}

std::string Assessment::getMainLabel() {
    return mainLabel;
}

std::string Assessment::getLabel(int labelIndex) {
    return assessmentStats[labelIndex].label;
}

std::string Assessment::getDueDate(int indx) {
    return assessmentStats[indx].dueDate;
}

std::string Assessment::getHandInDate(int indx) {
    return assessmentStats[indx].handinDate;
}

bool Assessment::getDropped(int indx) {
    return assessmentStats[indx].droppedFromScore;
}

int Assessment::getNumberOfParts() {
    return assessmentStats.size();
}

unsigned short Assessment::getAssessedGrade(int assessmentIndex) {  
    return assessmentStats[assessmentIndex].partGrade;
}

void Assessment::setAssessedGrade(unsigned short grade, unsigned short part) {
    if (grade > assessmentStats[part].partMax) {
        std::cout << "That is not a valid grade. Please try again.\n";
        return;
    }

    if (!assessmentStats[part].droppedFromScore)
        assessmentStats[part].partGrade = grade;
    else
        assessmentStats[part].partGrade = 0.0f;
}

void Assessment::setWeighting(int indx) {
    if (indx == -1) {
        // Finish this method
    }

    // Finish this method.
}
