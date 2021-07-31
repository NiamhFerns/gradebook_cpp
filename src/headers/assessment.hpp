#ifndef _ASSESSMENT_H
#define _ASSESSMENT_H

#include <string>
#include <iostream>

// struct PartStats { //struct of 
//     unsigned short partGrade;
//     std::string label, dueDate, handinDate;
//     bool droppedFromScore;
// };

class Assessment{
private:
    //weighting is stored as a percentage but can be converted later.
    unsigned short assessedGrade = 0, maxGrade = 100, weighting, latePenalty;
    bool multiPart = 0;
    //TO DO mark an assessmentStats tuple for the different parts. Default = 1.

public:
    Assessment
    (  
        std::string labelIn, 
        std::string dueDateIn, 
        std::string handinDateIn,
        unsigned short gradeIn,
        unsigned short maxGradeIn,
        unsigned short weightingIn,
        unsigned short latePenaltyIn
    );

    std::string getLabel();
    unsigned short getAssessedGrade(); 

    //takes in the amount of parts for multipart assessments.
    void setMultiPart(unsigned short numParts);
    void setAssessedGrade(unsigned short grade);
};

#endif