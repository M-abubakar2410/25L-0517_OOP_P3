#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class Venue{
private:

    char roomID[20];
    int capacity;
    bool hasComputers;

public:

    Venue(){

        roomID[0] = '\0';
        capacity = 0;
        hasComputers = false;
    }

    Venue(const char* id,int cap,bool comp){

        strcpy(roomID,id);
        capacity = cap;
        hasComputers = comp;
    }

    void display(){

        cout << roomID
            << " Capacity: "
            << capacity
            << endl;
    }

    const char* getRoomID(){
        return roomID;
    }

    int getCapacity(){
        return capacity;
    }

    bool getComputers(){
        return hasComputers;
    }
};