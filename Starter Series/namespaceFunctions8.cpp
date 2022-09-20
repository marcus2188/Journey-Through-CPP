/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * namespace&functions 8
 *****************************************/
#include <iostream>
#include <string>
#include <ctype.h>  // for the isdigit() test function
using namespace std;    // using namespace here sets the entire file default namespace to std if not specified

// FUNCTIONS ON TOP OF MAIN() ALWAYS
bool noNumbers(string teststr){
    // this function lives in default namespace
    cout << "Default noNumbers function called" << endl;
    for(char c: teststr){
        if(isdigit(c)){
            return false;
        }
    }
    return true;
}

// CREATING NEW NAMESPACES
namespace custom1{
    bool noNumbers(string teststr){
        // this function lives in custom1 namespace
        cout << "custom1 noNumbers function called" << endl;
        for(char c: teststr){
            if(isdigit(c)){
                return false;
            }
        }
        return true;
    }

    void fireWeapon(){
        // this function lives in custom1 namespace
        cout << "custom1 AK47 fired!!!!" << endl;
    }
    // Function receives a pointer to both value and address
    // Now we take in address and dereference it with pointer to get value
    void decrementVal(int *someval){
        *someval -= 1;
    }
}

namespace custom2{
    void fireWeapon(){
        // this function lives in custom2 namespace
        cout << "custom2 GPMG fired!!!!" << endl;
    }
    // function receives the value only
    void incrementVal(int someval){
        someval += 1;
    }
    // same function as above but function receives both value and address
    void decrementVal(int &someval){
        someval -= 1;
    }
    
}


// EVERY C++ PROJECT HAS A MAIN() FUNCTION SOMEWHERE
int main(){
    string yourinput;
    cout << "Please type your string to test for digits: ";
    cin >> yourinput;
    cout << (noNumbers(yourinput)? "String has no numbers" : "String has numbers") << endl;
    cout << (custom1::noNumbers(yourinput)? "String has no numbers" : "String has numbers") << endl;
    cout << endl;
    using namespace custom2;    // using namespaces sets the rest of this main function to custom2
    fireWeapon();
    cout << "hi" << endl;   // even after a using namespace, default std functions still work
    
    // BY DEFAULT, FUNCTIONS IN C++ CALL BY VALUE
    // meaning: only value is passed as parameter, original variable not changed by function workings
    int testval{20};
    incrementVal(testval);  // variable passed in as normal
    cout << "The value of testval is: " << testval << endl; // doesn't change

    // FUNCTIONS IN C++ CAN CALL BY REFERENCE AS WELL, ONLY CHANGE IS AT FUNCTION CALL SIDE
    decrementVal(testval);  // variable passed in as normal
    cout << "The value of testval is: " << testval << endl;

    // FUNCTIONS IN C++ CAN CALL BY POINTERS AS WELL
    custom1::decrementVal(&testval);  // variable passed in as address with ampersand
    cout << "The value of testval is: " << testval << endl;

    return 0;
}