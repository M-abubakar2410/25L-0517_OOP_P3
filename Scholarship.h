#pragma once
#include"Student.h"
#include<iostream>
using namespace std;
 
class scolarshipStudent : public Student{
private:
    bool SSFlag;
    double minGpa;
 
public:
    // your original constructor kept exactly
    scolarshipStudent(bool flag = 1) {
        SSFlag = flag;
        setStatus("scholarship"); 
    }
 
    // when we have all the info at once
    scolarshipStudent(string name, string id, string email, string dept, double minG = 2.7){
        SetName(name);
        SetId(id);
        SetEmail(email);
        setDept(dept);
        SSFlag = true;
        minGpa = minG;
        setStatus("scholarship");
    }
 
    // after adding a grade we recalculate gpa then check if still eligible
    // your original SetScholarship kept exactly
    void SetScholarship(bool flag, double minGpa = 2.7){
        SSFlag = flag;
        this->minGpa = minGpa;
    }
 
    // your original isEligible kept exactly
    // just fixed the typo in "scolarsship"
    bool isEligible(){
        if (getGpa() < minGpa)
        {
            SSFlag = 0;
            setStatus("probation");
        }
        else{
            SSFlag = 1;
            setStatus("scholarship");
        }
        return SSFlag;
    }
 
    // your original setters/getters kept exactly
    void setMinGpa(double min){
        minGpa = min;
    }
    double getMinGpa(){
        return minGpa;
    }
 
    void displayProfile() override {
        cout << "[Scholarship Student]" << endl;
        Student::displayProfile();
        cout << "Min GPA: " << minGpa << endl;
    }
};