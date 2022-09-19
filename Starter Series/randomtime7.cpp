/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * randomtime 7
 *****************************************/
#include <iostream>
#include <cstdlib>  // for C style randoms
#include <time.h>   // to use time functions
#include <chrono>   // timer
using namespace std;

int main(){
    // RAND() ALWAYS GIVES THE SAME RANDOM GENERATED SEQUENCE OF NUMBERS COS DEFAULT SEED
    // ans: 808
    int yourguess;
    int somerandomnum = rand() % 1000 + 1;   // int 1 to 1000 inclusive
    cout << "Guess this random number between 1 to 1000: " << endl; 
    do{
        cout << "Try: " << endl;
        cin >> yourguess;
        cout << (yourguess<somerandomnum? "It's higher" : yourguess>somerandomnum? "It's lower" : "Congrats you hit it!!") << endl;
    }while(yourguess!=somerandomnum);
    cout << "The actual number is indeed " << somerandomnum << endl;
    
    // SRAND() SETS SEED FOR RAND() CALLS
    srand(time(0));     // use current time in seconds as seed to RNG
    int somerandomnum2, somerandomnum3, somerandomnum4;
    somerandomnum2 = rand() % 1000 + 1;
    somerandomnum3 = rand() % 1000 + 1;
    somerandomnum4 = rand() % 1000 + 1;
    cout << "three pseudorand nums from 1 to 1000 are " << somerandomnum2 << " " << somerandomnum3 << " " << somerandomnum4 << endl;
    
    // BUILD A GUESSBOT TO PLAY ABOVE GAME, TIME IT
    int upperbound{1000}, lowerbound{1}, curbotguess, tok;
    int randlist[3] = {somerandomnum2, somerandomnum3, somerandomnum4};
    clock_t start = clock();
    for(auto r: randlist){
        for(;;){
            curbotguess = (rand() % (upperbound-lowerbound+1)) + lowerbound;
            if(curbotguess<r){
                lowerbound = curbotguess;
            }else{
                if(curbotguess>r){
                    upperbound = curbotguess;
                }else{
                    break;
                }
            }
            cout << "guess: " << curbotguess << endl;
            cout << "New range: " << lowerbound << ", " << upperbound << endl;
            // cout << "range: (" << lowerbound << ", " << upperbound << ")" << endl;
        }
        cout << "Number " << r << " guessed correctly" << endl;
        upperbound = 1000; lowerbound = 1;
    }
    clock_t end = clock();
    cout << "The bot took " << (end-start)/(double)CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}