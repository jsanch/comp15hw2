//
//  TOT.h
//  hw2


#ifndef __hw2__TOT__
#define __hw2__TOT__

#include <iostream>
#include "Transcript.h"

using namespace std;

//initial size of dynamic array, start small for testing purposes
const int INIT_SIZE = 5;

//factor to increase the size of array, we double every time we expand the array
const int RESIZE_FACTOR = 2;

class TOT
{ public:
    
    //constructor creates dynamic array of size INIT_SIZE, sets pointers to NULL
    TOT();

    //constructor takes in a dynamic array of transcripts,
    //note you may call addTranscript function
    TOT(Transcript* transcriptList, int listSize);
    
    //Function returns a point to a copy of student’s transcripts
    Transcript* getTranscriptCopy(string studentID);
    
    //function add a single Transcript to the system, returns bool if it worked
    bool addTranscript(Transcript* t);
    
    
    //FOR  TESTING
    void print();
    
private:
    // this a pointer to an array of pointers to trancripts
    //dynamic array of pointers to Transcripts
    Transcript** transcripts;
    
    // this returns a pointer to a transcript.
    Transcript* lookUp(string sID);
    
    //expand dynamic array when it is full
    void expand();
    
    //count of how many currently stored
    int currentCount;
    
    //capacity of the dynamic array
    int currentCapacity;
    
    Transcript* getPointertoTrancript(Transcript t);
};



#endif /* defined(__hw2__TOT__) */
