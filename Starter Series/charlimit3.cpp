/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * CHARLIMIT 3
 *****************************************/
#include <iostream>
#include <climits>  // contains primitive info about data types
using namespace std;

#define ray 4.5;    // old way of defining global constants (unchangable)
const double ray2 = 4.5;    // new way
bool testedPositive = true;

int main(){
    // SIZE OF C++ VARIABLES IN BYTES using sizeof(var)
    cout << "Size of C++ data types (bytes): " << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "char: " << sizeof(char) << endl;
    cout << "short: " << sizeof(short) << endl;
    cout << "long: " << sizeof(long) << endl;
    cout << "double: " << sizeof(double) << endl;
    cout << "bool: " << sizeof(bool) << endl;
    cout << "longdouble: " << sizeof(long double) << endl;
    cout << "float: " << sizeof(float) << endl;

    // MIN AND MAX ALLOWED RANGE OF EACH C++ VARIABLE TYPE
    cout << "Minimum and maximum allowed range: " << endl;
    cout << "int: " << INT_MIN << " to " << INT_MAX << endl;
    cout << "char: " << CHAR_MIN << " to " << CHAR_MAX << endl;
    cout << "short: " << SHRT_MIN << " to " << SHRT_MAX << endl;
    cout << "long: " << LONG_MIN << " to " << LONG_MAX << endl;
    cout << "long long: " << LLONG_MIN << " to " << LLONG_MAX << endl;

    // GLOBAL VS LOCAL VARIABLES, LOCAL CHECKED/USED FIRST BEFORE GLOBAL
    bool testedPositive = false;
    cout << "It is " << testedPositive << " that I have covid"<< endl;
    
    return 0;
}