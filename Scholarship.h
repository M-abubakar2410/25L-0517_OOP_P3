#pragma once
#include"Student.h"
#include<iostream>
using namespace std;
class scolarshipStudent : public Student{
private:
    bool SSFlag;
    double minGpa;
public:
    scolarshipStudent(bool flag = 1) {
        SSFlag = flag;
        setStatus("scholarship");
        
    }
    void SetScholarship(bool flag, double minGpa = 2.7){
        SSFlag = flag;
        this->minGpa = minGpa;
    }
    bool isEligible(){
        if (getGpa() < minGpa)
        {
            SSFlag = 0;
            setStatus("probation");
        }
        else{
            SSFlag = 1;
            setStatus("scolarsship");
        }
        return SSFlag;
    }
    void setMinGpa(double min){
        minGpa = min;
    }
    double getMinGpa(){
        return minGpa;
    }
};