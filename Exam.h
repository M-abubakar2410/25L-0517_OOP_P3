#include<iostream>
using namespace std;
#include"Assessment.h"
class Exam : public Assessment{
public:
    Exam() : Assessment("Exam", 0, 100, 0.5){}
 
    Exam(double raw, double max, double weight)
        : Assessment("Exam", raw, max, weight){}
 
    void display() override {
        cout << "  [Exam]       " << getRawScore() << "/" << getMaxScore()
             << "  weight=" << getWeightage() * 100 << "%"
            << "  contribution=" << getWeightedScore() << endl;
    }
};
