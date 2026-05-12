#pragma once
#include<iostream>
#include"Courses.h"
using namespace std;
class CoreCourse : public Course{
public:
    CoreCourse() : Course(){}
 
    CoreCourse(const char* id, const char* title, const char* tid, int cap = 30)
        : Course(id, title, tid, cap){}
 
    const char* getCourseType() override { 
        return "Core"; 
    }
    int getExamDuration() override { 
        return 3; 
    }
 
    double calculateFinalGrade() override {
        double total = 0;
        for(int i = 0; i < getAssessmentCount(); i++)
            total += getAssessment(i)->getWeightedScore();
        return total;
    }
};