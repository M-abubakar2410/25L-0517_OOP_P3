#include<iostream>
using namespace std;
#include"Assessment.h"
class Assignment : public Assessment{
public:
    Assignment() : Assessment("Assignment", 0, 100, 0.3){}
 
    Assignment(double raw, double max, double weight)
        : Assessment("Assignment", raw, max, weight){}
 
    void display() override {
        cout << "  [Assignment] " << getRawScore() << "/" << getMaxScore()
             << "  weight=" << getWeightage() * 100 << "%"
            << "  contribution=" << getWeightedScore() << endl;
    }
};