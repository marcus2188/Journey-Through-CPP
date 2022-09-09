/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * vectorarray 4
 *****************************************/
#include <iostream>
#include <vector>   // include the vector library header!
using namespace std;

int main(){
    // VECTORS INIT W/WO SIZE AND VALUES, SIZE IS NOT REQUIRED/NOT FIXED
    vector<int> totoNumbers; // no size or values
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};    // init all vowel chars
    vector<double> temperatures (365, 37.1);   // init size 365 vector spaces all of value 37.1

    // VECTOR INDEX ACCESS
    cout << "Second vowel is " << vowels.at(1) << endl; // At index 1 or 2nd element, special method
    cout << "Last vowel is " << vowels.back() << endl; // Last element on the back

    // ARRAY INIT METHODS W/WO INIT VALUES, SIZE IS REQUIRED/FIXED
    int testscores[10]; // no init values
    bool gotCOVID[3] = {true, false, false}; // size and values init
    double loc[] = {6.5, 7.777, 8}; // values init but no size stated
    float movieRating[3][4];    // nd-array
    cout << "The size in bytes of gotCOVID array is : " << sizeof(gotCOVID) << endl;
    cout << "The second element in gotCOVID array is : " << gotCOVID[1] << endl;
    cout << "If cout'ing uninitialised array, address of first element returned: " << testscores << endl;

    // ADDING AND REMOVING ELEMENTS IN ARRAYS AT INDEX
    string players[10] = {"Maguire", "Ronaldo", "Sergio"};
    cout << "Added player Rooney to index 1 of the players array" << endl;
    for(int v = 3; v > 1; v--){
        players[v] = players[v-1];  // shift everything after index back
    }
    players[1] = "Rooney";
    cout << "Player array after adding Rooney is:";
    for(int i = 0 ; i < sizeof(players)/sizeof(players[0]) ; i++){
        cout << ' ' << players[i];
    }
    cout << endl;

    // ADDING AND REMOVING ELEMENTS, AND LOOP THROUGH VECTORS
    totoNumbers.push_back(8888);    // Add element to the back of vector, must be same type
    int totoNumbersToAdd[3] = {7465, 9274, 9999};
    for(int i = 0 ; i < sizeof(totoNumbersToAdd)/sizeof(totoNumbersToAdd[0]) ; i++){
        totoNumbers.push_back(totoNumbersToAdd[i]);
    }
    cout << "The elements inside the vector totoNumbers are: ";
    for (vector<int>::iterator it = totoNumbers.begin() ; it != totoNumbers.end(); ++it){
        cout << ' ' << *it; // How to iterate vectors
    }
    cout << endl;
    cout << "Element in vector index 2 is removed." << endl;
    totoNumbers.erase(totoNumbers.begin() + 2);
    cout << "The elements left inside the vector totoNumbers are: ";
    for (vector<int>::iterator it = totoNumbers.begin() ; it != totoNumbers.end(); ++it){
        cout << ' ' << *it; // How to iterate vectors
    }


    
    

    return 0;
}