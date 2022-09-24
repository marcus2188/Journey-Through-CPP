/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * exceptionmalloc 13
 *****************************************/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>   // for isdigit() and isalpha()
using namespace std;

// Functions declaration only
double divide(double a, double b);

// TEMPLATE FUNCTIONS ALLOW YOU TO DO DYNAMIC TYPING
template <typename T>   
T getHigher(T x, T y);

template <typename X, typename Y>
string identifyInputTypes(X in1, Y in2);

// Custom exception
class notNumException: public exception{
    public: string flushmsg(){
        return errmsg;
    }
    private: string errmsg = "You reached the notnumexception";
};

int main(){
    // TRY BLOCK TESTS EVERYTHING INSIDE FOR EXCEPTIONS
    try{
        cout << divide(8, 7) << endl;
        throw notNumException();
    }catch(const char *msg){    // catch a pointer to error msg
        cerr << msg << endl;    // output this msg to console error stream
    }catch(notNumException nne){
        cout << nne.flushmsg() << endl;
    }catch(exception e){    // catch all other exceptions
        cout << e.what() << endl;
    }

    // POINTER MEMORY CAN BE DYNAMICALLY ALLOCATED OR RELEASED AT RUNTIME
    // for normal variables, memory allocation is automatic. But for pointers, you have to manage
    int *ip = new int;  // here you allocate 4 bytes to this integer pointer *ip
    char *cp = new char[3]; // allocates memory for size 3 char array pointing to 1st char

    // DIFF BETWEEN THIS AND NORMAL POINTER DECLARATION IS: 
    // dynamically allocated variables persist throughout run lifecycle (HEAP)
    // statically allocated variables are destroyed after scope of function ends (STACK)

    // If heap has not enough memory -> segmentation fault
    int *ipp = new(nothrow) int;    // (nothrow) causes pointer to be null if segmentation fault
    if(!ipp){   // test if pointer is NULL
        cout << "HEAP OUT OF MEM" << endl;
    }else{
        cout << "HEAP HAS MEM" << endl;
    }

    // DELETE ALL DYNAMICALLY ALLOCATED HEAP VARIABLES
    delete ip;
    delete []cp;
    delete ipp;
    
    // CALL THE SAME TEMPLATE FUNCTION WITH DIFF INPUT DATA TYPES
    cout << getHigher(4,7) << endl;
    cout << getHigher('d', 'k') << endl;
    cout << identifyInputTypes(6, 'r') << endl;
    return 0;
}

// VARS IN FUNCTIONS ARE STORED IN STACK MEMORY
// Function implementation below main() must be declared at top first
double divide(double a, double b){
    if(b==0) throw "Division by zero error"; // dividing by zero actually gives inf
    return (a/b);
}

// IMPLEMENT THE TEMPLATE FUNCTIONS
template <typename T>
T getHigher(T x, T y){
    return (x>y)? x:y;
}

template <typename X, typename Y>
string identifyInputTypes(X in1, Y in2){
    string strtoadd{""};
    if(isdigit(in1)){
        strtoadd += "in1 is digitstring, ";
    }else{
        if(isalpha(in1)){
            strtoadd += "in1 is letter, ";
        }else{
            strtoadd += "in1 is integer, ";
        }
    }
    if(isdigit(in2)){
        strtoadd += "in2 is digitstring, ";
    }else{
        if(isalpha(in2)){
            strtoadd += "in2 is letter, ";
        }else{
            strtoadd += "in1 is integer, ";
        }
    }
    return strtoadd;
}
