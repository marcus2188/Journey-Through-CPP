/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * exceptionmalloc 13
 *****************************************/
#include <iostream>
#include <string>
#include <vector>
#include <thread>    // for threading
#include <time.h>   // to use time functions
#include <chrono>   // timer
using namespace std;

// Function for thread to run
void print(string strtoprint){
    cout << strtoprint << endl;
    cout << strtoprint << endl;
    cout << strtoprint << endl;
    cout << strtoprint << endl;
    cout << strtoprint << endl;
    cout << strtoprint << endl;
    cout << strtoprint << endl;
    cout << strtoprint << endl;
}

int main(){
    int printFreq{1000};
    // CREATE printFreq STRINGS TO PRINT OUT, AND A VECTOR OF THREADS TO RUN THEM CONCURRENTLY
    clock_t start = clock();
    vector<thread> threadvec;
    for(int i = 0; i < printFreq; ++i){
        thread(print, "Print line " + to_string(i+1)).detach();
    }
    // for(auto &t: threadvec){
    //     t.join();
    // }
    // threadvec.back().join();
    clock_t end = clock();

    // PHYSICALLY PRINTING printFreq TIMES
    clock_t start2 = clock();
    for(int i = 0; i < printFreq; ++i){
        print("Print line " + to_string(i+1));
    }
    clock_t end2 = clock();
    cout << "Multithreading " << printFreq <<  " prints took " << (end-start)/(double)CLOCKS_PER_SEC << " secs" << endl;
    cout << "Physical doing " << printFreq <<  " prints took " << (end2-start2)/(double)CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
