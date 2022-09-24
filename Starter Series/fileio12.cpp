/*****************************************
 * THIS FILE SUMMARISES THE ENTIRE C++ BASIC SYNTAX WITH MULTIPLE ENTRIES
 * fileio 12
 *****************************************/
#include <iostream>
#include <stdlib.h> 
#include <string>
#include <vector>
#include <fstream>  // for reading and writing to files
#include "../libs/nlohmann/json.hpp"   // for json handling, import header from physical dir
using namespace std;

int main(){
    cout << endl;
    // TXT FILES
    // Create a new file
    ofstream newofstream("playfiles/newtest.txt");

    // Read the file contents
    ifstream newinputstream;
    newinputstream.open("playfiles/helloworld.txt");
    char filecontents[100];
    newinputstream.getline(filecontents, 100); // Instead of using >>, use getline()
    cout << filecontents << endl;

    // Write something to the file
    ofstream newoutputstream;
    newoutputstream.open("playfiles/helloworld.txt", ios::app); // ios::app means all output always at end of file, ios::ate means when file opened position at end, but free to seek
    char strtoadd[100] = " tested";
    newoutputstream << strtoadd;

    // Create and write a new json file
    using json = nlohmann::json;
    json randomjsonobj = {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {"answer", {
            {"everything", 42}
        }},
        {"list", {1, 0, 2}},
        {"object", {
            {"currency", "USD"},
            {"value", 42.99}
        }}
    };
    ofstream o("playfiles/try1.json");
    o << setw(4) << randomjsonobj << endl;

    // READING A JSON FILE, ACCESS ITS CONTENTS EASILY
    ifstream f("playfiles/crazy.json");
    auto crazydata = json::parse(f);
    cout << crazydata << endl;
    cout << crazydata["account"]["interests"] << endl;

    // READ DAT FILE
    ifstream fin("playfiles/income.dat");
    int num;
    vector<int> vec;
    while (fin >> num)
        cout << num << endl;
        vec.push_back(num);
    
    // WRITE TO DAT FILE
    ofstream fout;
    fout.open("playfiles/income.dat", ios::app);
    fout << "\n" << 897557;
    fout.close();

    // WRITE MULTIATTRIBUTE DAT FILE
    ofstream fout2;
    fout2.open("playfiles/companydb.dat", ios::app|ios::trunc); // ios::trunc erases the file first before writing
    vector<int> employeeid{1,2,3,4};
    vector<string> employeename{"brandon", "sweesen", "kaiming", "dawn"};
    vector<char> gender{'m', 'm', 'm', 'f'};
    for(auto i: employeeid){
        fout2 << i << ", " << employeename.at(i-1) << ", " << gender.at(i-1) << "\n";
    }
    cout << "Successful" << endl;

    // READ MULTIATTRIBUTE DAT FILE
    ifstream fin2("playfiles/companydb.dat");
    string thing, thing2, thing3;
    while (fin2 >> thing >> thing2 >> thing3)
        cout << thing << thing2 << thing3 << endl;
    return 0;
}