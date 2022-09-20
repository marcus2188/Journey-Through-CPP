/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * TYPES 3
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
    
    // TYPEDEF CHANGING TYPE NAMES
    typedef bool myownbooltype;     // You can clone out existing types into your own
    myownbooltype tested = true;

    // ENUMS AND ALL
    enum color{red, blue, green, yellow = 4, orange}; // declare in curly brackets comma seperated
    color c1 = green;   // if no value, use index from left
    color c2 = yellow;  // value will be explicit
    color c3 = orange;  // value follows any explicit after that
    cout << "enum color c1 is value " << c1 << endl;
    cout << "enum color c2 is value " << c2 << endl;
    cout << "enum color c3 is value " << c3 << endl;
    return 0;
}