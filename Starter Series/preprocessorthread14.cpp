/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * preprocessorthread 14
 *****************************************/

// THESE STARTING WITH '#' ARE SO CALLED PREPROCESSORS WHICH RUN BEFORE MAIN()
#include <iostream> // #include lets you read and run header files
#include <string>
#include <vector>
#include <csignal>  // for manipulating signals
#include <unistd.h>     // for unix sleep function
#include <thread>    // for threading

// DEFINE RUNS BEFORE EVERYTHING, AND SO IT WILL DIG UP DEFINITIONS/DECLARATIONS/TEMPLATES IF NEEDED
// #define lets you do keyboard shortcuts (non-c++ symbolic constants) replacements
#define PI 3.14159          // mostly for universal constants, no need semicolon as not c++
#define MAIN int main(){    // you can even abstract away syntaxes
#define ENDMAIN return 0;}  // define can be used to replace symbols and add ending braces too
#define print(x) println(x);  // define function redirection, ends with semicolon too
#define GETMAX(x,y) println((x>y)?x:y);   // perform full functions as well

#define RUNTHIS         // can also define but don't set to anything
#define MAKESTR(z) #z   // it catches every use of MAKESTR and pipes it into a string of its param
#define hello "hello"   // you can even get rid of string quotation marks completely if you are madman

// MAKE PYTHON3 PRINT METHOD FOR YOUR SANITY
template <typename X> void println(X thingtoprint){
    std::cout << thingtoprint << std::endl;
}

// To handle any signals incoming
void signalHandler( int signum ) {
   std::cout << "You woke up" << std::endl;
   //cout << "Interrupt signal (" << signum << ") received.\n";
   // cleanup and close up stuff here  
   // terminate program  
   exit(signum);  
}

MAIN

print(PI) // this is a define function that redirects to a c++ template function
GETMAX(4, 5)
// CHECK IF DEBUG IS DEFINED PREVIOUSLY IN ENTIRE FILE
#ifndef DEBUG
    std::cerr << "DEBUG symbolic constant is not defined to a value" << std::endl;
    #define DEBUG 3
#endif
// NOW CHECK IF DEBUG IS DEFINED
#ifdef DEBUG
    std::cout << "DEBUG symbolic constant is defined at long last" << std::endl;
#endif

// THE IF 0 DIRECTIVE ACTS AS A INSTRUCTION NOT TO COMPILE WHATEVER IS INSIDE
#if 0
    std::cout << "This will not be compiled, thus not ran" << std::endl;
#endif

// ADD STRING-STYLE QUOTES TO ANY DEFINE FUNCTION PARAMS
print(MAKESTR(WHATS UP YALL))  // notice don't even need quotation marks no more
print(hello)

// AFTER ALL THE ABOVE INSANITY, YOU CAN STILL CHOOSE TO CODE IN VANILLA C++ 
std::cout << "Value of __LINE__ : " << __LINE__ << std::endl;
std::cout << "Value of __FILE__ : " << __FILE__ << std::endl;
std::cout << "Value of __DATE__ : " << __DATE__ << std::endl;
std::cout << "Value of __TIME__ : " << __TIME__ << std::endl;

// For programs that run forever eg: while(true), signals are exception-like events
int i = 0;
// register signal SIGINT and signal handler  
signal(SIGINT, signalHandler);  

// FIRST WHILE LOOP RAISES SIGNAL AT 5 SEC
// while(++i) {
//     std::cout << "Going to sleep...." << std::endl;
//     if(i == 5) {
//         raise(SIGINT); // interrupts execution process completely
//     }
//     sleep(1);
// }

// SECOND WHILE LOOP GOES FOREVER UNTIL YOU PRESS CTRL-C
// while(true) {
//     std::cout << "Sleeping...." << std::endl;
//     // if(i == 5) {
//     //     raise(SIGINT); // interrupts execution process completely
//     // }
//     sleep(1);
// }

// EVERY MAIN() FUNCT IS RUNNING ON A 'MAIN' THREAD
std::thread thread1(println<std::string>, "Creating Thread 1"); // when calling template functions inside thread, need to preface its typing
thread1.join(); // interrupts main thread to run thread1 until it finishes

ENDMAIN

