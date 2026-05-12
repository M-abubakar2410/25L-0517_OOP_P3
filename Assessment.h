#pragma once
#include<iostream>
#include<cstring>
using namespace std;
 

class Assessment{
private:
    char type[20];      // "Exam", "Quiz", or "Assignment"
    double rawScore;    // marks the student got
    double maxScore;    // total marks it was out of
    double weightage;   // how much it counts e.g 0.4 means 40%
 
public:
    Assessment(){
        type[0] = '\0';
        rawScore  = 0;
        maxScore  = 100;
        weightage = 0;
    }
 
    Assessment(const char* t, double raw, double max, double w){
        strncpy(type, t, 19);
        type[19] = '\0';
        rawScore  = raw;
        maxScore  = max;
        weightage = w;
    }
 
    virtual ~Assessment(){}
 
    // this is the key function
    // it gives us how many marks this assessment contributes to the final grade
    virtual double getWeightedScore(){
        if(maxScore == 0) return 0;
        return (rawScore / maxScore) * weightage * 100;
    }
 
    // every subclass will show itself differently
    virtual void display() = 0;
 
    // getters
    const char* getType()    { 
        return type; 
    }
    double getRawScore()     { 
        return rawScore; 
    }
    double getMaxScore()     { 
        return maxScore; 
    }
    double getWeightage()    { 
        return weightage;
    }
 
    // setters
    void setRawScore(double s)  { 
        rawScore = s; 
    }
    void setMaxScore(double m)  { 
        maxScore = m; 
    }
    void setWeightage(double w) { 
        weightage = w;
    }
};
