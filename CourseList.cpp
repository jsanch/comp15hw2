//
//  CourseList.cpp
//  hw2

#include "CourseList.h"

CourseList::CourseList()
{
    head = NULL;
    sizeCourseList = 0;   
}

CourseList::CourseList(const CourseList &cLtocopy){
    //cerr << "CourseList's Copy Constructor allocating memory" <<endl; 
    head = cLtocopy.head;
    sizeCourseList = cLtocopy.sizeCourseList;
    
}


CourseList& CourseList::operator=(const CourseList &cLtocopy){
    //cerr << "CourseList's Assigment overload allocating memory"<<endl;
    //checking for self_assignment
    if (this == &cLtocopy) return *this;
    
    // do the copy
    head = cLtocopy.head;
    sizeCourseList = cLtocopy.sizeCourseList;
    
    //return the existing object
    return *this;
    
}

bool CourseList::isEmpty(){
    if(head == NULL)
    {
        return true;
    }
    
    else
    {
        return false;
        
    }
}

void CourseList::insertCourse(string course_ID, string grade){
   
    // firts, creating a new node to store the element.
    CourseNode * NodeA  = new CourseNode;
    NodeA->course_ID = course_ID;
    NodeA->grade = grade;
    NodeA->next = NULL;
    
    // Empty Case
    if (isEmpty()) {
        head = NodeA;
    }
    //Non empty Case
    else
    {
        CourseNode * iter = head;
        while (iter->next != NULL ) {
            iter = iter -> next;
        }
        //now iter points to the node before NULL
        iter->next = NodeA;
    }
    
    //adding 1 to the size.
    sizeCourseList++;
}

int CourseList::size(){
    return sizeCourseList;
    
}

void CourseList::print(){
    CourseNode * iter = head;

    int counter = 0 ;
    while (iter != NULL ) {
        cerr << iter->course_ID << " "
             << iter->grade  << " " <<endl;
        iter = iter->next;
        counter++;
    }
    
}

 CourseList::~CourseList(){
     //cerr<< "Destroying allocated memory for CourseList"<<endl;
     sizeCourseList = 0;
     head = NULL; 
}





