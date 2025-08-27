#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// TODO: Create the Employee Template Class

template<typename T1,typename   T2, typename T3>


class Employee {
private:
    // TODO: Define data members

    T1 id;
    T2 name;
    T3 hour;

public:
    // TODO: Define constructor

    Employee(T1 a, T2 b, T3 c):id(a), name(b), hour(c){}


    void display() 
    {
        cout<<name<<" "<<id<<" "<<hour;
    }

    void saveToCSV(ofstream & out)
    {
        out<<id<<"    "<<name<<"    "<<hour;  
    }

    // Load employee record from CSV using stringstream
    void loadFromCSV(string line) 
    {
        stringstream s(line);
        string part1, part2, part3;

        getline(s, part1, ',');
        getline(s, part2, ',');
        getline(s, part3, ',');

        id = part1;     
        name = part2;
        hour = part3; 
    
    }


};

// Main
int main() {
    // TODO: Create two Employee objects each with relevant data types
    // Company A Employee (ID = string, Hours = float)
    Employee <string, string, float> E1("EMP_101", "John Doe", 7.5);

    // Company B Employee (ID = int, Hours = int)
    Employee <int, string, int>E2(101, "Billy Mark" , 8);


    // TODO: Write the data of the Employee objects to CSV with the headers ID, Name, Working Hours
    ofstream out("employees.csv");
    out<<"ID   :    NAME    :     Hours"<<endl;



    // TODO: Close the file
    
    E1.saveToCSV(out);
    E2.saveToCSV(out);
    out.close();
    

    cout << "Data has been written to the file!\n";

    // TODO: Read the data back from CSV

    ifstream in("employees.csv");

    // This variable will be used to store the lines back from the csv
    string line;

    // TODO: Skip header

    getline(in,line);

    cout << "\nReading back from CSV:\n";
    while (getline(in, line)) 
    {
        cout << line << endl; 
    }

    // TODO: Close the file
    in.close();

    return 0;
}
