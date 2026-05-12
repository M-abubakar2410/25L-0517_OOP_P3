#pragma once
#include<iostream>
#include<cstring>
using namespace std;
 
// a section links a course to a teacher and a venue at a specific time
// one course can have multiple sections
 
class Section{
private:
    char sectionID[10];
    char courseID[10];
    char teacherID[10];
    char venueID[10];
    char timeSlot[20];      // e.g "MON-08:00"
 
    // exam info — filled in by the Scheduler
    char examTimeSlot[20];
    char examVenueIDs[5][10];   // exam can span multiple venues
    int  examVenueCount;
 
public:
    Section(){
        sectionID[0]    = '\0';
        courseID[0]     = '\0';
        teacherID[0]    = '\0';
        venueID[0]      = '\0';
        timeSlot[0]     = '\0';
        examTimeSlot[0] = '\0';
        examVenueCount  = 0;
    }
 
    Section(const char* sid, const char* cid, const char* tid,const char* vid, const char* slot){
        strncpy(sectionID,  sid,  9);  sectionID[9]  = '\0';
        strncpy(courseID,   cid,  9);  courseID[9]   = '\0';
        strncpy(teacherID,  tid,  9);  teacherID[9]  = '\0';
        strncpy(venueID,    vid,  9);  venueID[9]    = '\0';
        strncpy(timeSlot,   slot, 19); timeSlot[19]  = '\0';
        examTimeSlot[0] = '\0';
        examVenueCount  = 0;
    }
 
    // scheduler calls this when it assigns an exam slot
    void addExamVenue(const char* vid){
        if(examVenueCount < 5)
        {
            strncpy(examVenueIDs[examVenueCount], vid, 9);
            examVenueIDs[examVenueCount][9] = '\0';
            examVenueCount++;
        }
    }
 
    void display(){
        cout << "Section: " << sectionID
            << "  Course: "  << courseID
            << "  Teacher: " << teacherID
            << "  Venue: "   << venueID
            << "  Slot: "    << timeSlot << endl;
 
        if(examTimeSlot[0] != '\0')
        {
            cout << "  Exam Slot: " << examTimeSlot << "  Venues: ";
            for(int i = 0; i < examVenueCount; i++)
                cout << examVenueIDs[i] << " ";
            cout << endl;
        }
    }
 
    // getters
    const char* getSectionID()    { 
        return sectionID; 
    }
    const char* getCourseID()     { 
        return courseID;
    }
    const char* getTeacherID()    { 
        return teacherID; 
    }
    const char* getVenueID()      { 
        return venueID; 
    }
    const char* getTimeSlot()     { 
        return timeSlot; 
    }
    const char* getExamTimeSlot() { 
        return examTimeSlot; 
    }
    int getExamVenueCount()       { 
        return examVenueCount; 
    }
    const char* getExamVenueID(int i) { 
        return examVenueIDs[i]; 
    }
 
    // setters
    void setSectionID(const char* s)    { 
        strncpy(sectionID, s, 9);   sectionID[9]  = '\0'; 
    }
    void setCourseID(const char* c)     { 
        strncpy(courseID,  c, 9);   courseID[9]   = '\0'; 
    }
    void setTeacherID(const char* t)    { 
        strncpy(teacherID, t, 9);   teacherID[9]  = '\0'; 
    }
    void setVenueID(const char* v)      { 
        strncpy(venueID,   v, 9);   venueID[9]    = '\0'; 
    }
    void setTimeSlot(const char* t)     { 
        strncpy(timeSlot,  t, 19);  timeSlot[19]  = '\0'; 
    }
    void setExamTimeSlot(const char* t) { 
        strncpy(examTimeSlot, t, 19); examTimeSlot[19] = '\0'; 
    }
};
