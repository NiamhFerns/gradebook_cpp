#ifndef _ASSESSMENT_H
#define _ASSESSMENT_H

#include <string>
#include <iostream>
class Assessment{
private:
    //weighting is stored as a percentage but can be converted later.
    unsigned short assessedGrade = 0, maxGrade, weighting, latePenalty, parts = 1;
    std::string label, dueDate, handinDate;
    bool multiPart;

public:
    Assessment();

    //takes in the amount of parts for multipart assessments.
    void setMultiPart(unsigned short numParts);
    void setAssessedGrade(unsigned short grade);
    
    std::string getLabel();
};

#endif