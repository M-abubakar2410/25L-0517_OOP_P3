#pragma once
#include<iostream>
#include<cstring>
#include"academicEntity.h"
using namespace std;

class Teacher : public AcademicEntity{
private:

    double averageFeedback;
    int totalFeedback;

    char comments[20][100];
    int commentCount;

    char assignedCourses[20][20];
    int assignedCount;

public:

    Teacher(){

        averageFeedback = 0;
        totalFeedback = 0;
        commentCount = 0;
        assignedCount = 0;
    }

    Teacher(string name,string id,string email){

        SetName(name);
        SetId(id);
        SetEmail(email);

        averageFeedback = 0;
        totalFeedback = 0;
        commentCount = 0;
        assignedCount = 0;
    }

    void displayProfile() override {

        cout << "\n===== Teacher Profile =====" << endl;
        cout << "Name : " << getName() << endl;
        cout << "ID   : " << GetId() << endl;
        cout << "Email: " << getEmail() << endl;
        cout << "Average Feedback : " << averageFeedback << endl;
    }

    void addFeedback(int rating,const char* comment){

        averageFeedback = ((averageFeedback * totalFeedback) + rating) / (totalFeedback + 1);

        totalFeedback++;

        strcpy(comments[commentCount],comment);
        commentCount++;
    }
};