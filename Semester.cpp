//
//  Semester.cpp
//  hw2


#include "Semester.h"

Semester::Semester(){
    term = "TERM NOT DEFINED";
    year = NULL;
    number_of_courses = 0;
}


Semester::Semester(const Semester &stocopy){
   // cerr << "Semester's Copy Constructor allocating Memory"<<endl;
    
    term = stocopy.term;
    year = stocopy.year;
    courseList = stocopy.courseList;
    number_of_courses = stocopy.number_of_courses;
}


Semester& Semester::operator=(const Semester &stocopy){
   // cerr << "Semester's Assigment overload allocating memory"<<endl;
    // checking for self_assigment
    if (this == &stocopy) {
        return *this;
    }
    // do the copy.
    term = stocopy.term;
    year = stocopy.year;
    courseList = stocopy.courseList;
    number_of_courses = stocopy.number_of_courses;
    
    //return the existing object
    return *this;
}


void Semester::setSemester(string t, int y, CourseList cL){
    term = t;
    year = y;
    courseList = cL;
    number_of_courses = cL.size();
}


Semester::Semester(string t, int y, CourseList cL){
    term = t;
    year = y;
    courseList = cL;
    number_of_courses = cL.size();
}

void Semester::addCourse(string cID, string cGrade){
    courseList.insertCourse(cID, cGrade);
    number_of_courses++;
}

void Semester::setCourseList(CourseList cL){
    courseList = cL;
}

string Semester::getTerm(){
    return term;
}
int Semester::getYear(){
    return year;
}

CourseList Semester::getcourseList(){
    return courseList;
}

int Semester::courseListSize(){
    return courseList.size();
};

bool Semester::isCourseListEmpty(){
    if (courseList.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Semester::print(){
    cout << "~~~~~~~~~~~~Semester~~~~~~~~~~~~~~"<<endl;
    cout << "Semester: " << term <<" " << year <<endl;
    
    if( number_of_courses == 0 ){
        cerr << "There are no Courses in this CourseList"<<endl;
    }
    else {
        if (!isCourseListEmpty()) {
            courseList.print();
        }
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

Semester::~Semester(){
 
    courseList.~CourseList();
}


