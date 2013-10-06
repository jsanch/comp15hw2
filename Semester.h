//
//  Semester.h
//  hw2


#ifndef __hw2__Semester__
#define __hw2__Semester__

#include <iostream>
#include "CourseList.h"
using namespace std;




class Semester{
    
    public:
        // initializes a semester. zeroes all values. 
        Semester();
    
        // copy constructor
        Semester(const Semester &stocopy);
    
        //asigment overload
        Semester& operator=(const Semester &stocopy);
    
        //initializes with term, year and CourseList
        Semester(string t, int y, CourseList cL);
    
        //sets the term and year and CourseList for a Semester.
        void setSemester(string t, int y, CourseList cL);
    
        // adds a Course
        void addCourse(string cID, string cGrade);
    
        //sets course List (replaces the current one)
        void setCourseList(CourseList cL);
    
        // gets the term
        string getTerm();
    
        // gets the year
        int getYear();
    
        //gets a courseList;
        CourseList getcourseList();
    
        //gets size of CourseList
        int courseListSize();
    
        // checks if CoursList is empty
        bool isCourseListEmpty();
    
        // prints a Semester very nicely??
        void print();
        //destroyer
        ~Semester();
    
        CourseList courseList;
        
    private:
        string term;
        int year; 
        int number_of_courses;
    
};

#endif /* defined(__hw2__Semester__) */
