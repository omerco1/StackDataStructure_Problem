#include <iostream>
#include "pcalc.h"

using namespace std;

// Examples:
// Input: “17” return: 17
// Input: “17,13” return: 13
// Input: “17,13,+” return: 30
// Input: “17,13+4-” return: 26
// Input: “35,17,13+-” return: 5
// Input: “2,2*3,3*-” return: -5
// You are given the following helper function and the following definition to use. You do not need to write the helper function yourself, just to use it.

int main(int argc, const char * argv[]) {
    
    Pcalc myPcalc;
    
    cout << "Starting Unit Tests... " << endl;
    //***********************
    //UNIT TESTS
    myPcalc.parseIn("17");                              //should equal: 17
    myPcalc.parseIn("17,13");                           //should equal: 13
    myPcalc.parseIn("17,13,+");                         //should equal: 30
    myPcalc.parseIn("17,13+4-");                        //should equal: 26
    myPcalc.parseIn("35,17,13+-");                      //should equal: 5
    myPcalc.parseIn("2,2*3,3*-");                       //should equal: -5
    myPcalc.parseIn("0");                               //should equal: 0
    myPcalc.parseIn("0,1,2,3,4,5,4536,73547");          //should equal: 73547
    myPcalc.parseIn("1,1,+,1,+,");                      //should equal: 3
    myPcalc.parseIn(",,,,,,,,,");                       //should equal:
    myPcalc.parseIn("3,33,*,3/");                       //should equal: 33
   
    return 0;
}
