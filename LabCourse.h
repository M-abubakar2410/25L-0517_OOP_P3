#pragma once
#include<iostream>
#include<cstring>
#include"Courses.h"
using namespace std;

class LabCourse : public Course{
private:

    char venue[30];

public:

    LabCourse() : Course(){
        venue[0] = '\0';
    }

    LabCourse(const char* id,const char* title,const char* tid,const char* v,int cap = 30): Course(id,title,tid,cap)
    {
        strcpy(venue,v);
    }

    const char* getCourseType() override {
        return "Lab";
    }

    int getExamDuration() override {
        return 0;
    }

    double calculateFinalGrade() override {

        double total = 0;

        for(int i=0;i<getAssessmentCount();i++)
        {
            total += getAssessment(i)->getWeightedScore();
        }

        return total;
    }
};