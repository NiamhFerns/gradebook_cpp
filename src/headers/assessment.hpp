#ifndef _ASSESSMENT_H
#define _ASSESSMENT_H

#include <iostream>
#include <string>
#include <vector>

struct PartStats {
    unsigned short partGrade, partMax;
    std::string label, dueDate, handinDate;
    bool droppedFromScore;
    float weighting;

    PartStats(std::string labelIn,
              unsigned short partGradeIn,
              unsigned short partMaxIn,
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
    std::string mainLabel = "";

    //weighting is stored as a percentage but can be converted later.
    //it is the total weighting for the whole assessment. 
    //weighting per part handled later.
    unsigned short weighting, latePenalty; //TODO Move penalty into the PartStats.
    
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

    void addPart();

    std::string    getMainLabel();
    std::string    getLabel(int labelIndex);
    std::string    getDueDate(int indx);
    std::string    getHandInDate(int indx);
    bool           getDropped(int indx);
    int            getNumberOfParts();
    unsigned short getAssessedGrade(int assessmentIndex); 

    void setAssessedGrade(unsigned short grade, unsigned short part);
    void setWeighting(int indx);
};

#endif
