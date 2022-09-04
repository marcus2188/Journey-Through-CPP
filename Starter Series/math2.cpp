/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * MATH 2
 *****************************************/
#include <iostream>
using namespace std;

int main(){
    // MATHEMATICAL OPERATIONS: ADD, MULTIPLY, DIVISION AND FLOAT DIVISION
    int room_length, room_width, room_height;
    cout << "Enter length of your room : " << endl;
    cin >> room_length;
    cout << "Enter width of your room : " << endl;
    cin >> room_width;
    cout << "Enter height of your room : " << endl;
    cin >> room_height;
    cout << "Area of your room is " << room_length*room_width << endl;
    cout << "Perimeter of your room is " << 2*room_length + 2*room_width << endl;
    cout << "Volume of your room is " << room_length*room_height*room_width << endl;
    cout << "Cube ratio of your room (float) is " << (float)room_length/(float)room_width/(float)room_height << endl;
    cout << "Cube ratio of your room (no float) is " << room_length/room_width/room_height << endl;

    // MATH OPERATIONS: MODULUS FACTORS + WHILE LOOP + INIT INT VALUES
    int num {0}, yourguess {0}; // initial int values is now 0
    cout << "Guess the Factor Game!" << endl;
    cout << "Please enter a 3/4/5 digit number: " << endl;
    cin >> num;
    cout << "Now enter a factor number guess: " << endl;
    cin >> yourguess;
    while(num % yourguess != 0){
        cout << "That is not a factor of " << num << ". Please try again: " << endl;
        cin >> yourguess;
    }
    cout << "Congrats! " << yourguess << " is a valid factor" << endl;
    


    return 0;
}