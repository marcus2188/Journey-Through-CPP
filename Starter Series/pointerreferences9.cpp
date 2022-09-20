/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * pointerreferences 9
 *****************************************/
#include <iostream>
#include <vector>
using namespace std;

void incrementThis(int *lol){
    // So in C++ funct declarations, *s and &s are applied to AFTER whatever you send to the funct parameters
    // For exp above, the * dereferencing will occur after lol is received, so lol has to be an address
    *lol += 1;
}

int* padTwo(){
    // This funct returns address, operations must be static in nature to persist outside of stack memory
    static int r[2] = {4,5};
    return r;
}

int main(){
    // 3 LEVELS: |*VAR POINTER| <-=-> |VAR VALUE| <-=-> |&VAR ADDRESS|
    // ASSIGN ANY TWO SEQUENTIALLY WITH EQUALS OPERATOR (=)

    // AMPERSAND RETRIEVES ADDRESS OF A VARIABLE STORED IN MEMORY
    int myint;  // without value init, it takes whatever value is in that memory address slot
    cout << "The var myint is at " << &myint << " with value " << myint << endl;

    // POINTERS ARE JUST SPECIAL VARS CONTAINING VALUE: ADDRESSES OF OTHER VARS
    // TWO WAYS TO USE POINTERS:
    // 1. DIRECTLY ASSIGN A POINTER * TO A VARIABLE
    // 2. ASSIGN A POINTER BASE VARIABLE AN ADDRESS AND THEN DEREFERENCE IT WITH *
    
    // WAY 1: Assign pointer * to another var directly
    int *ip; bool *bp; double *dp;
    myint = 7;
    *ip = myint;    // here you assign the pointer * striaght to myint variable
    cout << "The pointer *ip has value " << *ip << " and at " << ip << endl;    // base var contains address while deferencing it with * gives its value traced

    // WAY 2: Assign pointer base variable to address of another var
    int *temp;   // init value to 0
    temp = &myint;  // note diff with above, 
    cout << "The temp pointer var has value " << *temp << " and at " << temp << endl;
    
    // POINTERS CANNOT ALTER VALUE OF UNDERLYING VARIABLE
    *ip = 4;    // point ip to constant literal 4
    cout << "The value of myint is now " << myint << " and at " << ip << endl;
    
    // POINTERS CAN BE INCREMENTED USING ++ OR --, INCREMENTS BY BASE TYPE STEP SIZE
    static int numarr[3] = {5,6,7}; 
    int *someptr = NULL;
    someptr = numarr;   // for arrays, referring to its name w/o ampersand is already its address(using WAY 2)
    cout << "First value of numarray is " << *someptr << " at " << someptr << endl;
    someptr++;
    cout << "Second value of numarray is " << *someptr << " at " << someptr << endl;
    someptr++;
    cout << "Third value of numarray is " << *someptr << " at " << someptr << endl;
    
    // POINTERS CAN BE COMPARED IF THEY ARE POINTING TO THE SAME VARIABLE (VALUE AND/OR ADDRESS)
    int *otherptr = NULL;
    otherptr = numarr;
    // Value comparisons only
    cout << (*someptr==*otherptr? "Same value" : "Diff value") << endl; // it will be different cause someptr is pointing to 3rd element
    someptr = numarr;
    cout << (*someptr==*otherptr? "Same value" : "Diff value") << endl; // Now it will be the same
    cout << (someptr==otherptr? "Same address" : "Diff address") << endl; // Now it will be the same
    
    // DOUBLE POINTERS AND BEYOND
    // Pointer chains must have same base type (WAY 2)
    int **baseptr = NULL;
    int *tempptr = NULL;
    int try1{8};
    tempptr = &try1;
    baseptr = &tempptr;
    cout << "Value of try1 var is " << try1 << " at " << &try1 << endl;
    cout << "Value of tempptr is " << *tempptr << " at " << &tempptr << endl;
    cout << "Value of baseptr is " << **baseptr << " at " << &baseptr << endl;
    
    // C++ functions carry out any pointer manipulation AFTER you send over the funct params
    incrementThis(&try1);
    cout << "Value of try1 var is " << try1 << " at " << &try1 << endl;

    // FUNCT RETURNING POINTER FOLLOWS OPPOSITE RULE: YOU NEED TO ASSIGN POINTER BASE VAR TO AN ADDRESS GOTTEN BACK FROM FUNCT
    int *tryptr = NULL;
    tryptr = padTwo();
    cout << "Value of tryptr is " << *tryptr << " at " << tryptr << endl;
    return 0;
}