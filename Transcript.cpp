//
//  Transcript.cpp
//  hw2
//


#include "Transcript.h"
#include <cstdlib>

Transcript::Transcript(){
    //initiates the Semester array
    Student_ID = "STUDENT ID NOT SPECIFIED";
    SemesterArray = new Semester[init_semester_capacity];
    current_semester_capacity = init_semester_capacity;
    semester_count = 0;
    
}

Transcript::Transcript(const Transcript &ttocopy){
    //cerr << "Transcript's Copy Constructor allocating memory" <<endl;
    

    // copying dynamic array
    SemesterArray = copySemesterArray(ttocopy.SemesterArray,ttocopy.current_semester_capacity);

   // copying the rest
    current_semester_capacity = ttocopy.current_semester_capacity;
    Student_ID = ttocopy.Student_ID;
    semester_count = ttocopy.semester_count;

}




Transcript& Transcript::operator=(const Transcript &ttocopy){
    //cerr << "Transcript's Assigment Overload allocating memory" <<endl;

    //checking for self_assignment
        if (this == &ttocopy) return *this;
    //checking for NULL
    if (ttocopy.SemesterArray == NULL) {
    }
    
    // copying dynamic array
    SemesterArray = copySemesterArray(ttocopy.SemesterArray,ttocopy.current_semester_capacity);
    
    
    // copying the rest
    current_semester_capacity = ttocopy.current_semester_capacity;
    Student_ID = ttocopy.Student_ID;
    semester_count = ttocopy.semester_count;
    //return the existing object
    
    return *this;
}



Semester * Transcript::copySemesterArray(Semester * oldSemArray, int arraysize){
    if (oldSemArray == NULL){
        cerr << "Nulll"<<endl;
        exit(0);
    }
    Semester * newSemesterArray = new Semester[arraysize];

    for (int i = 0; i<arraysize; i++) {
        newSemesterArray[i].setSemester(oldSemArray[i].getTerm(), oldSemArray[i].getYear(), oldSemArray[i].getcourseList());
        
    }
  
    return newSemesterArray;
}

Semester Transcript::copySemester(Semester sem){
    sem.print();
    Semester temp;
    temp = sem;
    temp.print();
    return temp;
}


bool Transcript::isSemesterArrayEmpty(){
    if (semester_count == 0){
        return true;
    }else{
        return false;
    }
}

void Transcript::insertSemester(Semester sem){
    
    if ( current_semester_capacity < semester_count){
       expandSemesterArray();
    }
    
    SemesterArray[semester_count] = sem;
    
    
    semester_count++;
}

int Transcript::getSemesterCount(){
    return semester_count;
    
}
int Transcript::get_current_semester_capacity(){
    return current_semester_capacity;
}

string Transcript::getStudentID(){
    return Student_ID;
    
}


void Transcript::expandSemesterArray(){
    Semester * temp = new Semester[current_semester_capacity*sem_resize_factor];
        for (int i =0; i<semester_count; i ++) {
            temp[i] = SemesterArray[i];
        }
        delete[] SemesterArray;
        SemesterArray = temp;
    
    current_semester_capacity= current_semester_capacity*sem_resize_factor;
}

Semester * Transcript::getSemesters(){
    Semester * sems = new Semester[current_semester_capacity];
    sems = copySemesterArray(SemesterArray, current_semester_capacity);
    
    return sems;
    
}

void Transcript::setTranscriptID(string iD){
    Student_ID = iD;
}

void Transcript::print(){
    cout << "*************TRANSCRIPT****************" <<endl;
    cout << "Student ID: " <<  Student_ID << endl;
    cout << "Semester_count: " << semester_count << endl;
    for (int i = 0; i<semester_count; i++) {
        if (!isSemesterArrayEmpty()){
        SemesterArray[i].print();
        }
    }
    cout << "***************************************" <<endl;
}

Transcript::~Transcript(){
  // cerr<< "Destroying allocated memory for Transcript?"<<endl;
   for (int i = 0; i<=semester_count; i++) {
       SemesterArray[i].courseList.~CourseList();
       
    }
}