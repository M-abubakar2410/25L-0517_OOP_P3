#pragma once
#include"academicEntity.h"
#include<iostream>
#include<cstring>
using namespace std;
 
class Student : public AcademicEntity{
private:
    string dept;
    string status;
    double gpa;

    int enrolledCount;
    char** EnrolledCourse;

public:
    
    Student(string dept, string status, int count, char** course){
        this->dept = dept;
        this->status = status;
        gpa = 0.0;
        enrolledCount = count;
 
        EnrolledCourse = new char*[enrolledCount];
        for(int i = 0; i < enrolledCount; i++)
        {
            EnrolledCourse[i] = new char[strlen(course[i]) + 1];
            strcpy(EnrolledCourse[i], course[i]);
        }
    }
 
    // when we dont know anything yet
    Student(){
        dept = "";
        status = "Active";
        gpa = 0.0;
        enrolledCount = 0;
        EnrolledCourse = nullptr;
    }
 
    // free all the memory we allocated
    virtual ~Student(){
        for(int i = 0; i < enrolledCount; i++)
        {
            delete[] EnrolledCourse[i];
        }
        delete[] EnrolledCourse;
    }
 
    // this was pure virtual in AcademicEntity so we have to define it
    void displayProfile() override {
        cout << "Name   : " << getName()  << endl;
        cout << "ID     : " << GetId()    << endl;
        cout << "Email  : " << getEmail() << endl;
        cout << "Dept   : " << dept       << endl;
        cout << "Status : " << status     << endl;
        cout << "GPA    : " << gpa        << endl;
    }
 
    // add a new course to the enrolled list
    // we have to grow the char** array manually since its not a vector
    void enrollInCourse(const char* courseID){
        // make a new array one size bigger
        char** temp = new char*[enrolledCount + 1];
 
        // copy all old pointers into the new array
        for(int i = 0; i < enrolledCount; i++)
            temp[i] = EnrolledCourse[i];
 
        // add the new course at the end
        temp[enrolledCount] = new char[strlen(courseID) + 1];
        strcpy(temp[enrolledCount], courseID);
 
        // replace old array with new one
        delete[] EnrolledCourse;
        EnrolledCourse = temp;
        enrolledCount++;
    }
 
    bool isEnrolledIn(const char* courseID){
        for(int i = 0; i < enrolledCount; i++){
            if(strcmp(EnrolledCourse[i], courseID) == 0) {
                return true;
            }
        }
        return false;
    }
    // store a grade for a course
    // virtual because exchange student will override this differently
    
        // otherwise add a fresh entry
        
 
    // go through transcript and compute gpa
    // call this after every addGrade
    

    // your original function kept exactly as you wrote it
    double CalculateGpa(double* points, int* crHr, int CourseCount){
        double sumOfPoints = 0;
        int sumOfCrhr = 0;
        for (int i = 0; i < CourseCount; i++)
        {
            sumOfPoints += points[i];
            sumOfCrhr += crHr[i];
        }
        double Gpa = sumOfPoints/sumOfCrhr;
        return Gpa;
    }
 
    // print everything in a simple list
    virtual void ViewTranscript(){
        cout << "\n------- Transcript: " << getName() << " (" << GetId() << ") -------" << endl;
        cout << "CourseID" << "\t" << "Grade%" << endl;
        cout << "-------------------------" << endl;
 
      
        cout << "-------------------------" << endl;
        cout << "GPA    : " << gpa    << endl;
        cout << "Status : " << status << endl;
        cout << "=========================" << endl << endl;
    }
 
    // your original setStatus kept exactly
    void setStatus(const char* s){
        status = s;
    }
 
    // your original Getstatus kept exactly
    string Getstatus(){
        return status;
    }
 
    // getters
    double getGpa(){ 
        return gpa; 
    }
    string getDept(){
        return dept;
    }
    int getEnrolledCount(){
        return enrolledCount;
    }
    
    const char* getEnrolledCourse(int i){
        return EnrolledCourse[i];
    }
    // setters
    void setDept(string d) { 
        dept = d;
    }
    void setGpa(double g)  { 
        gpa = g; 
    }
};