#pragma once
#include<iostream>
#include<cstring>
#include"Assessment.h"
#include"Student.h"
using namespace std;
 
// Course is the base class
// CoreCourse, ElectiveCourse, LabCourse all inherit from it
class Course{
private:
    char courseID[10];
    char title[50];
    char teacherID[10];
    int  capacity;  
 
    Student** enrolledStudents; //array of students
    int enrolledCount;
 
    // assessments for this course (exam, quiz, assignment)
    Assessment* assessments[10];
    int assessmentCount;
 
public:
    Course(){
        courseID[0]  = '\0';
        title[0]     = '\0';
        teacherID[0] = '\0';
        capacity     = 30;
        enrolledCount    = 0;
        assessmentCount  = 0;
        enrolledStudents = new Student*[30];
        for(int i = 0; i < 10; i++) {
            assessments[i] = nullptr;
        }
    }
 
    Course(const char* id, const char* t, const char* tid, int cap){
        strncpy(courseID,  id,  9);  courseID[9]  = '\0';
        strncpy(title,     t,  49);  title[49]    = '\0';
        strncpy(teacherID, tid, 9);  teacherID[9] = '\0';
        capacity         = cap;
        enrolledCount    = 0;
        assessmentCount  = 0;
        enrolledStudents = new Student*[capacity];
        for(int i = 0; i < 10; i++) {
            assessments[i] = nullptr;
        }
    }
 
    virtual ~Course(){
        // students are managed externally so we dont delete them
        delete[] enrolledStudents;
 
        // but we own the assessments so we delete those
        for(int i = 0; i < assessmentCount; i++)
            delete assessments[i];
    }
 
    // each course type calculates its grade differently
    virtual double calculateFinalGrade() = 0;
 
    // core = 3 hrs, elective = 2 hrs, lab = 0 (no exam)
    virtual int getExamDuration() = 0;
 
    // so we know which type it is when saving to file
    virtual const char* getCourseType() = 0;
 
    // try to enroll a student — returns false if course is full
    bool enrollStudent(Student* s){
        if(enrolledCount >= capacity)
            return false;
        enrolledStudents[enrolledCount++] = s;
        return true;
    }
 
    bool isFull(){
        return enrolledCount >= capacity;
    }
 
    // add an assessment (exam/quiz/assignment) to this course
    void addAssessment(Assessment* a){
        if(assessmentCount < 10)
            assessments[assessmentCount++] = a;
    }
 
    void display(){
        cout << "[" << getCourseType() << "] "
            << courseID << " - " << title
            << "  Teacher: " << teacherID
            << "  Enrolled: " << enrolledCount << "/" << capacity << endl;
    }
 
    // getters
    const char* getCourseID()   { 
        return courseID; 
    }
    const char* getTitle()      { 
        return title; 
    }
    const char* getTeacherID()  { 
        return teacherID; 
    }
    int getCapacity()           { 
        return capacity; 
    }
    int getEnrolledCount()      { 
        return enrolledCount; 
    }
    int getAssessmentCount()    { 
        return assessmentCount; 
    }
    Student* getEnrolledStudent(int i) { 
        return enrolledStudents[i]; 
    }
    Assessment* getAssessment(int i)   { 
        return assessments[i]; 
    }

};
