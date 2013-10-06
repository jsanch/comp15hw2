//  
//  CourseList.h
//  hw2


#ifndef hw2_Course_h
#define hw2_Course_h

#include <iostream>
using namespace std;


struct CourseNode
{
    string course_ID;
    string grade;
    CourseNode * next;
};

class CourseList{
    public:
        // constructor
        CourseList();
    
        //copy constructor
        CourseList(const CourseList &cLtocopy);
    
        //asigment overload
        CourseList& operator=(const CourseList &cLtocopy);
    
        // checks to see if Course List is empty
        bool isEmpty();
    
        // adds a Course to the list
        void insertCourse( string course_ID, string grade);
    
        //gets the size of the list.
        int size();
    
        // prints to the console (for debugging)
        void print();
    
        // i need a destructor.
        ~CourseList();
    
    
    private:
        //keeps the size of the Course List/
        int sizeCourseList;
    
        // points to the head of the list.
        CourseNode * head;
};


#endif
