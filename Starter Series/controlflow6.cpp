/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * controlflow 6
 *****************************************/
#include <iostream>
using namespace std;

int main(){
    // IF CONDITION + ELSE W/O BRACKETSS, 
    string name{"singapore"};
    if(name[0]=='a') cout << "Start with a";
    else if(name[0]=='t') cout << "Start with t";
    else if(name[0]=='k') cout << "Start with k";
    else cout << name << " starts with something other than a, t, k!";

    // SWITCH CASE - CHECKING FOR VARIABLE VALUES
    char grade;
    cout << endl;
    cout << "Please enter the grade you want to get for test: " << endl;
    cin >> grade;
    switch (grade)
    {
    case 'a': // same branch do this
    case 'A':
        cout << "You need 90 marks" << endl;
        break;  // every branch end must break;
    case 'b':
    case 'B':
        cout << "You need 80 marks" << endl;
        break;
    case 'c':
    case 'C':
        cout << "You need 70 marks" << endl;
        break;
    case 'd':
    case 'D':
        cout << "You need 60 marks" << endl;
        break;
    default:    // default branch does not need break
        cout << "You entered some other character or stuff" << endl;
    }

    // TERNARY OPERATORS/MULTIPLEXERS
    int num{};
    cout << "Enter an interger: ";
    cin >> num;
    string strtocout;
    strtocout = (num%2==0)? "is even" : "is odd";
    cout << "is " << ((num%2==0)? "even" : "odd") << endl;
    cout << strtocout << endl;

    // FOR ITERATIONS
    for(int i {0}; i < 10; i +=2){
        cout << ' ' << i;
    }
    for(int i {2}, j{3}; i < 10; i += 2, j += 3){ // double iterators, single ending condition
        cout << i << ' ' << j << endl;
    }

    // WHILE ITERATIONS + DO WHILE LOOPS
    int rocketcountprop {10};
    cout << "Rocket blasting off in :" << endl;
    while(rocketcountprop != 0){
        cout << ' ' << rocketcountprop;
        rocketcountprop--;
    }
    cout << "Blast off!!!!!" << endl;
    
    return 0;
}