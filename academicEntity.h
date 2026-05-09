#pragma once
#include<iostream>
using namespace std;
class AcademicEntity{
    private:
    string name;
    string id;
    string email;
    public:
    AcademicEntity(string name, string id, string email){
        this->name = name;
        this->id  = id;
        this->email = email;
    }
    virtual ~AcademicEntity(){

    }
    virtual void displayProfile() = 0;

    string GetId(){
        return id;
    }
    string getEmail(){
        return email;
    }
    string getName(){
        return name;
    }
    void SetEmail(string e){
        email = e;
    }
    void SetName(string n){
        name = n;
    }
    void SetId(string i){
        id = i;
    }
};