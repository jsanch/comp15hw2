//
//  TOT.cpp
//  hw2


#include "TOT.h"
#include <cstdlib>


TOT::TOT(){
    transcripts = new Transcript*[INIT_SIZE];
    for (int i = 0; i<=INIT_SIZE; i++) {
        transcripts[i]= NULL;
    }
    
    currentCapacity = INIT_SIZE;
    currentCount = 0;
    
}

TOT::TOT(Transcript* transcriptList, int listSize){

    //checking for trolls that insert NULL or negative numbers
    if (transcriptList == NULL) exit(0);
    if (listSize < 0 ) exit(0);
    
    transcripts = new Transcript*[listSize]; //initiating trancripts

    currentCount = listSize;
    currentCapacity = listSize;
    
   //copying from given transcriptList to trancripts list.
    for (int i=0; i<=listSize; i++) {
        transcripts[i] = getPointertoTrancript(transcriptList[i]);
    }
}
bool TOT::addTranscript(Transcript* t){
    if (t ==NULL) return false;
    if (currentCapacity < currentCount) expand();
    transcripts[currentCount+1]= t;
    currentCount++;
    return true;
}

Transcript* TOT::getPointertoTrancript(Transcript t){
    Transcript * temp = new Transcript;


    //first lest get semesters from t
    Semester * sems;
    sems = t.getSemesters();
    
    // then, lets copy all the semesters inside t to temp
    for (int i =0; i< (t.getSemesterCount()); i++) {
        temp->insertSemester(sems[i]);
        // insert semester will update semester count and semester capacity
    }
    //then lets copy other stuff inside trancript
    temp->setTranscriptID(t.getStudentID());
    
    // now lets return the temp
    return temp;
    
    
}

Transcript* TOT::lookUp(string sID){
    Transcript * t;
    for (int i = 0; i <= currentCount; i++) {
        if (transcripts[i]->getStudentID() == sID ){
            t = transcripts[i];
        }
    }
    return t;
}

void TOT::expand(){
    Transcript ** temp = new Transcript*[currentCapacity*RESIZE_FACTOR];
    for (int i = 0; i<=currentCount; i++) {
        temp[i] = transcripts[i];
        //transcripts[i] = NULL;
    }
    delete [] transcripts;
    transcripts = temp;
    currentCapacity = currentCapacity*RESIZE_FACTOR;
}

void TOT::print(){
    for (int i =0 ; i<= currentCount; i++) {
        // cout<<"i: "<< i << endl;
        // cout<<"currentCount: "<< currentCount << endl;
        //   cout<<"currentCapacity: "<< currentCapacity << endl;
        // cout<<"studentID: "<< transcripts[i]->getStudentID() << endl;
        transcripts[i]->print();
    }
    
}





