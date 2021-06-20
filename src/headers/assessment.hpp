class Assessment : Course {
private:
    //weighting is stored as a percentage but can be converted later.
    unsigned short assessedGrade = 0, maxGrade, weighting, parts = 1;
    bool multiPart;

public:
    Assessment();

    //takes in the amount of parts for multipart assessments.
    void setMultiPart(unsigned short numParts);
    void setAssessedGrade(unsigned short grade);

    unsigned short getMarks();
};