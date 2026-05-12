#pragma once
#include"Student.h"
#include<iostream>
#include<cstring>
using namespace std;
 
class ExchangeStudent : public Student{
private:
    bool pass_fail;           // your original variable kept exactly
    double passThreshold;     // below this percentage = Fail
 
    // we store "Pass" or "Fail" for each course separately
    char results[20][5];
 
public:
    // your original constructor kept exactly
    ExchangeStudent(bool p_f = true, double threshold = 50.0){
        pass_fail = p_f;
        passThreshold = threshold;
        setStatus("Exchange");
 
        // clear out the results array
        for(int i = 0; i < 20; i++)
            results[i][0] = '\0';
    }
 
    // when we have all the info at once
    ExchangeStudent(string name, string id, string email, string dept, double threshold = 50.0){
        SetName(name);
        SetId(id);
        SetEmail(email);
        setDept(dept);
        pass_fail = true;
        passThreshold = threshold;
        setStatus("Exchange");
 
        for(int i = 0; i < 20; i++)
            results[i][0] = '\0';
    }
 
    // override the transcript view to show Pass/Fail instead of numbers
    void ViewTranscript() override {
        cout << "\n------- Exchange Transcript: " << getName() << " (" << GetId() << ") -------" << endl;
        cout << "CourseID" << "\t" << "Result" << endl;
        cout << "-----------------------" << endl;
        cout << "Status : " << Getstatus() << endl;
        cout << "=======================" << endl << endl;
    }
 
    void displayProfile() override {
        cout << "[Exchange Student]" << endl;
        Student::displayProfile();
    }
 
    bool getPassFail(){ return pass_fail; }
};
