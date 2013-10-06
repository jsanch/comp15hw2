//
//  main.cpp
//  hw2


#include <iostream>
#include "TOT.h"
#include "Transcript.h"
#include "Semester.h"
#include "CourseList.h"

void testCourseList();
void testSemester();
void testTranscript();
void testTOT();
void testTitle(string title); //this is to cout test names.

int main() {
//Test 1  - The CourseList Object
    testCourseList();
//Test 2 - the Semester Object
    testSemester();
//Test 3 - the Transcript Object
    testTranscript();
//Test 4 - The TOT Object
    testTOT();
}

void testCourseList(){
    
    testTitle("Test1 - CourseList Object");
    testTitle("Test1.1 - inserting Courses to Object ");
    
    CourseList cL;
    cL.insertCourse("COMP11","B+");
    cL.insertCourse("ES0056","A+");
    cL.insertCourse("COMP11","A-");
    cL.insertCourse("COMP11","B+");
    cL.print();
    
    
    testTitle("Test1.2 - using copy constructor ");
    CourseList c = cL;
    c.print();
    
    testTitle("Test1.3 - testing assigment overload ");
    CourseList a;
    a = cL;
    a.print();
    
    testTitle("Test1.4 - testing get size ");
    cout << c.size()<<endl;
    
    testTitle("Test1.5 - testing destructor");
    CourseList destructhis;
}

void testSemester(){
    testTitle("Test2 - Semester Object");
    
    //preparing courselist for testing/passing into semester
    CourseList cL;
    cL.insertCourse("COMP11","B+");
    cL.insertCourse("ES0056","A+");
    cL.insertCourse("COMP11","A-");
    cL.insertCourse("COMP11","B+");
    
    testTitle("Test2.1 - Testing normal Constructors ");
    Semester fall11;
    fall11.print();
    Semester fall13("FALL", 2013, cL);
    fall13.print();
    
    testTitle("Test2.2 - Testing add Course ");
    fall11.addCourse("COMP11","B+");
    fall11.addCourse("ES0056","A+");
    fall11.addCourse("COMP11","A-");
    fall11.addCourse("COMP11","B+");
    fall11.print();
    
    testTitle("Test2.3 - Testing setter and getter fncs ");
    cout<< fall11.getTerm() << fall11.getYear() <<endl;
    cout << fall13.courseListSize() << endl;
    fall11.getcourseList().print();
    
    
    testTitle("Test2.4 - Testing Semester copy constructor");
    Semester sem = fall13;
    sem.print();

    testTitle("Test2.5 - Testing Semester Assigment Overload");
    fall13 = fall11;
    fall13.print();
}

void testTranscript(){
    
    testTitle("Test3 - Transcript Object");
    
    testTitle("Test3.1 - Initializing transcript");
    Transcript t;
    t.print();
    Transcript t1;
    t1.print();
    t1.setTranscriptID("el t1.");

    testTitle("Preparrin Course Lists and Semester Array to insert to a trancript.");
    //feedign the array in t to test deep copying.
    //creating course Lists
    CourseList cL;
    cL.insertCourse("COMP11","B+");
    cL.insertCourse("ES0056","A+");
    cL.insertCourse("COMP11","A-");
    cL.insertCourse("COMP11","B+");
    
    CourseList cL2;
    cL2.insertCourse("FRENCH","B+");
    cL2.insertCourse("LALALA","A+");
    cL2.insertCourse("GYM","A-");
    cL2.insertCourse("COMP86","B+");
    
    //creating various semesters with course lists in them.
    Semester * semesterarray = new Semester[20];
    for (int i = 0; i<10; i++) {
        semesterarray[i].setSemester("FALL", 2013, cL);
        semesterarray[i+10].setSemester("SPRING", 2014, cL2);
        
    }
    
    testTitle("Test3.2 - Inserting Semestes to transcripts:");
    //inserting semesters in transcripts.
    for (int i = 0; i<10; i++) {
        t1.insertSemester(semesterarray[i]);
    }
    //priting one trancsript with 20 semesters to check its ok.
     t1.print();
    
    
    testTitle("test3.3 - testing the copy semester array");
    Semester * Arr = t1.copySemesterArray(semesterarray, 20);
    for (int i = 0; i<20; i++) {
        Arr[i].print();
    }
    
    testTitle("Test3.4 - Copy Constructor / Deep Copying:");
    //deep copying the transcript.
    Transcript t2 = t1;

    t2.print();
    t1.print();

    
    testTitle("Test3.5 - Assigment Overload");
    Transcript t3;
    t3.print();
    
    t3 = t1;
    t1.print();
    t3.print();
    
}




void testTOT(){
//preparing a transcript list.....
    //creating course Lists
    CourseList cL, cl2;
    cL.insertCourse("COMP11","B+");
    cL.insertCourse("ES0056","A+");
    cL.insertCourse("COMP11","A-");
    cL.insertCourse("COMP11","B+");
    
    CourseList cL2;
    cL2.insertCourse("FRENCH","B+");
    cL2.insertCourse("LALALA","A+");
    cL2.insertCourse("GYM","A-");
    cL2.insertCourse("COMP86","B+");
    
    //creating various semesters with course lists in them.
    Semester * semesterarray = new Semester[20];
    for (int i = 0; i<10; i++) {
        semesterarray[i].setSemester("FALL", 2013, cL);
        semesterarray[i+10].setSemester("SPRING", 2014, cL2);
        
    }
    
    // MUST CREATE TRANSCRIPT AND POINT TO THEM.
    //creating 7 trancripts
    Transcript hello1;
    Transcript hello2;
    Transcript hello3;
    Transcript hello4;
    Transcript hello5;
    Transcript hello6;
    Transcript hello7;
    
    //inserting 3 semesters in each trancript
    hello1.insertSemester(semesterarray[0]);
    hello1.insertSemester(semesterarray[1]);
    hello1.insertSemester(semesterarray[2]);

    hello2.insertSemester(semesterarray[0]);
    hello2.insertSemester(semesterarray[1]);
    hello2.insertSemester(semesterarray[2]);
    
    hello3.insertSemester(semesterarray[0]);
    hello3.insertSemester(semesterarray[1]);
    hello3.insertSemester(semesterarray[2]);
    
    hello4.insertSemester(semesterarray[0]);
    hello4.insertSemester(semesterarray[1]);
    hello4.insertSemester(semesterarray[2]);
    
    hello5.insertSemester(semesterarray[0]);
    hello5.insertSemester(semesterarray[1]);
    hello5.insertSemester(semesterarray[2]);
    
    hello6.insertSemester(semesterarray[0]);
    hello6.insertSemester(semesterarray[1]);
    hello6.insertSemester(semesterarray[2]);
    
    hello7.insertSemester(semesterarray[0]);
    hello7.insertSemester(semesterarray[1]);
    hello7.insertSemester(semesterarray[2]);
    
    //Creating a pointer array of  ponters to trancrtips
    Transcript * transcripts;
    transcripts = new Transcript[10];
    
    //storing the addres of each trancript in the array of pointers
    transcripts[0] = hello1;
    transcripts[1] = hello2;
    transcripts[2] = hello3;
    transcripts[3] = hello4;
    transcripts[4] = hello5;
    transcripts[5] = hello6;
    transcripts[6] = hello7;
    
    //the arrow dereferences each  pointer of the array and lets me acces the object's functions.
 
    // giving weach stranscript an id.
    transcripts[0].setTranscriptID("Jaime");
    transcripts[1].setTranscriptID("Alberto");
    transcripts[2].setTranscriptID("Sanchez");
    transcripts[3].setTranscriptID("Arias");
    transcripts[4].setTranscriptID("BOOM");
    transcripts[5].setTranscriptID("Zeuz");
    transcripts[6].setTranscriptID("big bang");

    testTitle("Test4 -  the TOT object. ");
    
    testTitle("Test 4.1 - the constructor");
    TOT b(transcripts,6);

    b.print();

    testTitle("test 4.2 - add transcript");
    bool jh;
    jh =  b.addTranscript(&transcripts[0]);
    b.print();
 
//    testTitle("4.3 - lookup test ( works when lookup is set to pulic)");
//    Transcript * look;
//    look = b.lookUp("Zeuz");
//    look->print();
//    

    
    
}

void testTitle(string title){
    cerr << title << endl;
}
