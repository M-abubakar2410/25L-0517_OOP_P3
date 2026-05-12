#include<iostream>
using namespace std;
#include"Assessment.h"
class Quiz : public Assessment{
public:
    Quiz() : Assessment("Quiz", 0, 100, 0.2){}
 
    Quiz(double raw, double max, double weight)
        : Assessment("Quiz", raw, max, weight){}
 
    void display() override {
        cout << "  [Quiz]       " << getRawScore() << "/" << getMaxScore()
             << "  weight=" << getWeightage() * 100 << "%"
            << "  contribution=" << getWeightedScore() << endl;
    }
};