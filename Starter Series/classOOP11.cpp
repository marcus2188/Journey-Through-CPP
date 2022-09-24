/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * classOOP 11
 *****************************************/
#include <iostream>
#include <string>
#include <math.h>  // for math power
#include <vector>
using namespace std;

// SUPERCLASS
class gadget{
    public: // all outside access is allowed
        gadget(double w, double p, int gid, string im): weight(w),price(p),gadgetid(gid),imei(im){
            gadgetcount++;  // add 1 to gadgetcount whenever class created
        }
        static int gadgetcount; // static attributes cannot be inited with values
        double weight;

        static int getGadgetCount(){    // methods that involve static attributes must be declared static as well
            return gadgetcount;
        }
        virtual void burnGadget() = 0;  // virtual methods must be implemented in subclasses

    private: // all outside access not allowed
        double price;
        int gadgetid;
    protected: // only internal/subclass access is allowed
        string imei;
        double retrievePrice(){
            return price;
        }
};

// Subclasses
class phone: public gadget{    // inherits from gadget class protected and public attributes/methods
    public:
        phone(double w, double p, int gid, string im, double ss, string dr, string pp, int mp):gadget(w, p, gid, im){
            screensize = ss;
            displayResolution = dr; // calling super class means you must do this way for init attributes
            processor = pp;
            megapixels = mp;
        }
        string getIMEI(){   // you need a public function inside subclass to access protected attributes of its superclass
            return imei;
        }
        double getPrice(){  // you need to call the superclass method itself inside your public method in subclass in order to access private attributes of its superclass
            return retrievePrice();
        }
        
        // Overloaded method of getPrice look at params to decide which method
        double getPrice(double discount){
            return (discount/100 * retrievePrice());
        }
        void burnGadget(){cout << "phone burnt away" << endl;}

    // If no access level is declared, then default private
    double screensize;
    string displayResolution;
    string processor;
    int megapixels;

    // For purely default private, you need to generate getters and setters
    double getscreensize(){return screensize;} string getdisplayresolution(){return displayResolution;} string getprocessor(){return processor;} int getmegapixels(){return megapixels;}
    void setscreensize(double s){screensize = s;} void setdisplayresolution(string s){displayResolution = s;} void setprocessor(string p){processor = p;} void setmegapixels(int m){megapixels = m;}
};

// FOR STATIC ATTRIBUTES, YOU MUST INIT VALUES SEPERATELY
int gadget::gadgetcount = 0;

// another subclass
class radio: public gadget{
    public: 
        radio(double w, double p, int gid, string im, double f):gadget(w, p, gid, im){
            frequency = f;
        }  
        void burnGadget(){cout << "radio burnt away" << endl;} 
    double frequency;
};

int main(){
    // CREATING 2 PHONE INSTANCES
    phone galaxys20(15.8, 999.99, 1, "FU3JH73BH3", 6.5, "4k", "snapdragon gen 2", 20);
    phone htcone2(13.8, 799.99, 2, "DNDJD73JD", 5.5, "3k", "snapdragon gen 1", 10);
    cout << "We have created " << gadget::getGadgetCount() << " gadgets" << endl;
    cout << "The htcone2 has a " << htcone2.getmegapixels() << "mp camera and a " << htcone2.getscreensize() << " inch screen" << endl;
    cout << "IMEI number of the galaxys20 is " << galaxys20.getIMEI() << endl;  // accessing a superclass protected attribute
    cout << "Price of the galaxys20 is " << galaxys20.getPrice() << endl;  // accessing a superclass protected attribute
    cout << "Price of the galaxys20 after 40percent discount is " << galaxys20.getPrice(40) << endl;    // overloaded method from previous
    
    // POLYMORPHISM ALLOWS SUBSTITUTION OF SUBCLASSES
    radio meradio(20.8, 589.45, 3, "DHSDF66SDFJ", 6.6);
    phone iphonex(33.8, 1299.99, 4, "EJENFJNLJD4D", 6.8, "5k", "A10 Bionic", 30);
    gadget *gadget1, *gadget2;  // Way 2
    gadget1 = &meradio; gadget2 = &iphonex; // cast subclass instance to superclass instance
    cout << "gadget 1 weighs " << gadget1->weight << " while gadget 2 weighs " << gadget2->weight << endl;
    cout << "We have created " << gadget::getGadgetCount() << " gadgets" << endl;
    return 0;
}