/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * structclass 10
 *****************************************/
#include <iostream>
#include <string>
#include <math.h>  // for math power
#include <vector>
using namespace std;

// STRUCT DEFINES A STRUCTURE WITH ATTRIBUTES, OUTSIDE OF MAIN()
struct person{
    string name;
    double height;
    double weight;
    int personid;
    char gender;
};

// TYPEDEF AUTOMATES STRUCT AND WAY BETTER
typedef struct{
    string schoolname;
    int num_of_students;
    char school_grade;
} school;

// CLASS DEFINITION
class singer{
    // PUBLIC ALLOWS ALL ATTRIBUTES INSIDE TO BE ACCESSED DIRECTLY USING .
    public: 
        // empty param constructor for no overloading
        singer(){}
        // constructor with params overloaded
        singer(string sname, int sid, vector<string> slist, double h, double w, int fbcount){
            this->singername = sname;
            this->singerid = sid;
            this->songlist = slist;
            this->height = h;
            this->weight = w;
            this->fanbase = fbcount;
        }
        // shortcut constructor initialisation of class attributes
        singer(string sname, double wealth): singername(sname), money(wealth){}

        // class attributes that reset/unique to each singer instance created
        string singername;
        int singerid;
        vector<string> songlist;
        double height;
        double weight;
        int fanbase;

        // class methods which act on class attributes
        double getBMI(){
            return (this->weight/pow(this->height, 2)); // arrow accessors for using this singer class instance
        }
        // unimplemented class methods, only function declaration with implementation done elsewhere
        vector<string> getSingerSongs();
        double digUpWealth();   

    private:
        // PRIVATE CLASS ATTRIBUTES AND METHODS
        double money;

        double findWealth(){
            return money;
        }
        friend class singer2;   // making another class a friend gives that class access to everything this class has including private
};

// CLASS METHOD IMPLEMENTATIONS MUST BE DONE OUTSIDE MAIN
vector<string> singer::getSingerSongs(){    // use class accessor space ::
        return songlist;
}
double singer::digUpWealth(){
    return findWealth(); // or just straight up return money which is private
}

// THIS IS A FRIEND CLASS TO SINGER, SO IT CAN ACCESS SINGER'S PRIVATE ATTRIBUTES AND METHODS
class singer2{
    public:
        double getSingerMoney(singer s);
};

// IMPLEMENTING FUNCTION IN SINGER2 TO ACCESS SINGER'S PRIVATE MONEY
double singer2::getSingerMoney(singer s){
    return s.money;
}

int main(){
    // CREATE NEW PERSON STRUCT INSTANCE, SET VALUES AND GET THEM
    struct person person1;
    person1.name = "Mary"; person1.height = 1.67; person1.weight = 60.7;
    cout << person1.name << "'s BMI is " << (person1.weight/(pow(person1.height, 2))) << endl;
    
    // POINTERS TO STRUCT REQUIRE USE OF -> INSTEAD OF . TO ACCESS STRUCT PROPERTIES
    person1.gender = 'F';
    person *person1ptr = NULL;  // we use WAY 2 here
    person1ptr = &person1;
    cout << person1.name << "'s gender is " << person1ptr->gender << endl;

    // USING TYPEDEF STRUCTS ALLOW US TO CREATE NEW INSTANCES WITHOUT STRUCT KEYWORD
    school school1, school2, school3;

    // CLASSES ARE SUPERIOR TO STRUCTS IN EVERY WAY
    singer Singer1; // create new instance
    Singer1.height = 1.78; Singer1.weight = 70; // init its class attribute values
    cout << Singer1.getBMI() << endl;      // its public class methods are callable from the getgo

    singer Singer2("Katy Perry", 45, {"hot & cold", "firework", "ET"}, 1.68, 66.9, 65000);
    cout << Singer2.singername << " has " << Singer2.fanbase << " fans and sang: " << endl;
    for(auto s: Singer2.getSingerSongs()){
        cout << s << ", ";
    }

    // To access private class attributes and methods, have to go through public methods from its own class
    singer Singer3("Justin Bieber", 528493);
    cout << "\nJustin Bieber has $" << Singer3.digUpWealth() << endl;   // you cannot just call findWealth()

    // 2nd way to access private class attributes and methods is to define a friend class, and that friend class can access
    singer2 altsinger; // singer2 is a friend class of singer
    cout << "Alternatively, he has $" << altsinger.getSingerMoney(Singer3) << endl;
    return 0;
}