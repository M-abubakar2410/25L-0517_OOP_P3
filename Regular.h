#pragma once
#include"Student.h"
#include<iostream>
using namespace std;
class RegularStudent : public Student{
    private:
    double Gpa;
public:
    RegularStudent(double g = 0.0){
        setStatus("Regular");
        Gpa = g;
    }
    double CaclculateGpa(double * points, int * CrHr, int ){
        
    }
    ~RegularStudent(){
        
    }
};
