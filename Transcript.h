//
//  Transcript.h
//  hw2


#ifndef __hw2__Transcript__
#define __hw2__Transcript__

#include <iostream>
#include "Semester.h"

using namespace std;

const int init_semester_capacity = 14;
const int sem_resize_factor = 2;


class Transcript{
    public:
        //initialize sem array.
        Transcript();
    
    
        //copy constructor
        Transcript(const Transcript &ttocopy);
    
        //assigment overload
        Transcript& operator=(const Transcript &ttocopy);
    
    
        //check if semester Array is empty
        bool isSemesterArrayEmpty();
    
        //insert a semester on the next empty slot of the SemArray.
        void insertSemester(Semester  semester);
    
        //insert one semester with its indv components.
        void insertSemesterIndv(string term, int year, CourseList cL);
    
        // copies a semester array and returns it.
        Semester * copySemesterArray(Semester * oldSemArray, int arraysize );
    
        //set student id
        void setTranscriptID(string iD);
    
        //get studen id
        string getStudentID();
    
        //get senester count
        int getSemesterCount();
    
        //get current_semester_Capacity;
        int get_current_semester_capacity();
    
        // for testing purposes.
        void print();
    
        //get semesters list in this transcript
        Semester * getSemesters();
    
        Semester copySemester(Semester sem);
    
    
        // Now I am Become Death, the destroyer of Transcripts
        ~Transcript();
    
    
    private:
        string Student_ID;
    
        //pointer to array of semesters.
        Semester * SemesterArray;
    
        int current_semester_capacity;
    
        //number of semeser taken
        int semester_count;
    
        void expandSemesterArray();
    
    
};


#endif /* defined(__hw2__Transcript__) */
