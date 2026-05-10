#pragma once
#include"academicEntity.h"
#include<iostream>
#include<cstring>
using namespace std;
class Student : public AcademicEntity{
private:
    double gpa;
    string dept;
    string status;
    int enrolledCount;
    char**EnrolledCourse;
public:
    Student( double gpa = 0.0 , string dept = ""  ,string status = "" ,int count ,char ** course)  {
        this->gpa = gpa;
        this->dept = dept;
        this->status = status;
        enrolledCount = count;
        EnrolledCourse = new char * [enrolledCount];
        for (int i = 0; i < enrolledCount; i++)
        {
            EnrolledCourse[i] = new char[strlen(course[i]) + 1];
            strcpy(EnrolledCourse[i] , course[i]);
        }        
    }
    Student(){

    }
    double getGpa(){
        return gpa;
    }
    void setStatus(const char * s){
        status = s;
    }
    virtual ~Student(){
        for (int i = 0; i < enrolledCount; i++)
        {
            delete [] EnrolledCourse[i];
        }
        delete [] EnrolledCourse;
    }
    string Getstatus(){
        return status;
    }
};