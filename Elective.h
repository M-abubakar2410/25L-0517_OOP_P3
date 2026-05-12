#include<iostream>
using namespace std;
#include"Courses.h"
class ElectiveCourse : public Course{
public:
    ElectiveCourse() : Course(){}
 
    ElectiveCourse(const char* id, const char* title, const char* tid, int cap = 30)
        : Course(id, title, tid, cap){}
 
    const char* getCourseType() override { 
        return "Elective"; 
    }
    int getExamDuration()       override { 
        return 2; 
    }
 
    double calculateFinalGrade() override {
        double total = 0;
        for(int i = 0; i < getAssessmentCount(); i++)
            total += getAssessment(i)->getWeightedScore();
        return total;
    }
};