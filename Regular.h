#pragma once
#include"Student.h"
#include<iostream>
using namespace std;
 
class RegularStudent : public Student{
public:
    // your original constructor kept exactly
    RegularStudent(){
        setStatus("Regular");
    }
 
    // when we have all the info at once
    RegularStudent(string name, string id, string email, string dept){
        SetName(name);
        SetId(id);
        SetEmail(email);
        setDept(dept);
        setStatus("Active");
    }
 
    // after adding a grade we recalculate gpa right away
    void displayProfile() override {
        cout << "[Regular Student]" << endl;
        Student::displayProfile();
    }
};