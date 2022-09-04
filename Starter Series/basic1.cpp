/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * BASICS 1
 *****************************************/

// 'INCLUDE' INCLUDES HEADER.H FILES, IOSTREAM REQUIRED FOR READING AND WRITING TO CONSOLE
#include <iostream>

// 'USING' DEFINES WHICH NAMESPACES YOU WANT TO USE FOR THIS FILE
using namespace std; // means you don't need to add 'std::' in front of standard functions anymore

int main(){
    // DECLARATION OF VARIABLES W/WO INIT VALUE
    int urnumber; // 5, 33
    string urstr; // 'GG'
    double urdouble, urdouble2, urdouble3; // 2.54
    char urchar = 'c'; // single quotes only single char
    bool urbool; // true, false
    
    // SIMPLE COUT W NEWLINE, CIN TAKING USER INPUT INTO VARIABLE
    cout << "cout works" << endl;
    cout << urchar << endl;
    cout << "Enter fav number: ";
    cin >> urnumber;
    cout << "Amazing, your number is accepted: " << urnumber << endl; // int can be cout'ed as well

    // SAMELINE USER INPUTS CIN INTO MULTIPLE VARIABLES SEPERATED BY SPACES
    string fname, lname;
    cout << "Please enter your first and lastname sep by space/(s): " << endl; // note that newlines before cin will kick input to new line
    cin >> fname >> lname; // input buffer stream flushes any spaces away
    cout << "Received name is " << fname << " " << lname << endl;

    // ALWAYS RETURN 0 FOR SUCCESS OR 1 FOR ERROR TO MAIN FUNCT
    return 0;
}