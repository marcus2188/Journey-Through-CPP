/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * vectorarray 4
 *****************************************/
#include <iostream>
#include <vector>   // include the vector library header!
using namespace std;

int main(){
    // VECTORS INIT W/WO SIZE AND VALUES
    vector<int> vowelList; // no size or values
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};    // init all vowel chars
    vector<double> temperatures (365, 37.1);   // init size 365 vector spaces all of value 37.1

    // VECTOR ACCESS, PUSH
    cout << "Second vowel is " << vowels.at(1) << endl; // At index 1 or 2nd element
    cout << "Last vowel is " << vowels[1] << endl; // At negative index from the back

    return 0;
}