#ifndef _ASSESSMENT_H
#define _ASSESSMENT_H

#include <iostream>
#include <string>
#include <vector>

struct PartStats {
    unsigned short partGrade;
    std::string label, dueDate, handinDate;
    bool droppedFromScore;

    PartStats(unsigned short partGradeIn,
              std::string labelIn,
              std::string dueDateIn,
              std::string handinDateIn,
              bool dropped);
};

class Assessment{
private:
    //just use length of assessmentStats to determine whether multipart assessment. 
    //if (length 1 ) x
    //else y
    std::vector<PartStats> assessmentStats;
    std::string mainLabel;

    //weighting is stored as a percentage but can be converted later.
    //it is the total weighting for the whole assessment. 
    //weighting per part handled later.
    unsigned short maxGrade = 100, weighting, latePenalty;
    
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

    std::string getMainLabel();
    std::string getLabel(int labelIndex);
    int getNumberOfParts();
    unsigned short getAssessedGrade(int assessmentIndex); 

    //takes in the amount of parts for multipart assessments.
    void setAssessedGrade(unsigned short grade);
    void setAssessedGrade(unsigned short grade, unsigned short part);
};

#endif
