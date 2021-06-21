class Assessment{
private:
    //weighting is stored as a percentage but can be converted later.
    unsigned short assessedGrade = 0, maxGrade, weighting, latePenalty, parts = 1;
    std::string dueDate, handinDate;
    bool multiPart;

public:
    Assessment();

    //takes in the amount of parts for multipart assessments.
    void setMultiPart(unsigned short numParts);
    void setAssessedGrade(unsigned short grade);

    unsigned short getMarks();
};