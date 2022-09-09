/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * operators 5
 *****************************************/
#include <iostream>
using namespace std;

int main(){
    // INIT VALUE VS ASSIGN VALUE (=)
    int num1 {10}; num1 = 9;

    // PRE VS POST INCREMENT DIFFERENCES
    int c {10};
    int g = c++; // c is assigned to g before value of c is incremented
    cout << "The value of c is " << c << " and g is " << g << endl;

    c = 10;
    g = ++c; // c is incremented before it is assigned to g
    cout << "The value of c is " << c << " and g is " << g << endl;
    
    // EQUALITY OPERATORS AND BOOLALPHA
    cout << (1==2) << endl;
    cout << boolalpha;
    cout << (1<=2) << endl;
    cout << noboolalpha;
    cout << ('a'!='A') << endl;

    // BOOLEAN OPERATORS , AND + OR + NOT
    if(1==1 && 2!=3 || 3==4){
        cout << "This chain of conditions passed" << endl;
        cout << "OR - Requires either LHS or RHS to be true to evaluate to true" << endl;
        cout << "AND - Requires both LHS & RHS to be true to evaluate to true" << endl;
    }

    // COMPOUND ASSIGNMENTS - OPERATIONS FOLLOWED BY ASSIGNMENTS
    int a {3};
    a += 3; // adds and assigns back
    a /= 2; // divides and assigns back
    a = a + 3 * 3 - 6;  // BODMAS rules apply as well

    cout << "The value of a is now: " << a << endl;
    

    

    return 0;
}