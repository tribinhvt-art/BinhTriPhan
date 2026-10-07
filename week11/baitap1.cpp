#include <iostream>
#include <string>
using namespace std;

// Class Date
class Date {
private:
    int year;
    int month;
    int day;

public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }

    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    void display() {
        cout << year << "/" << month << "/" << day;
    }
};


// Class Student
class Student {
private:
    // Properties
    string name;
    string address;
    Date birthdate;
    string cccd;

public:
    // Default constructor
    Student() {
        name = "";
        address = "";
        birthdate = Date();
        cccd = "";
    }

    // Constructor with name
    Student(string n) {
        name = n;
        address = "";
        birthdate = Date();
        cccd = "";
    }

    // Constructor with birthdate
    Student(Date d) {
        name = "";
        address = "";
        birthdate = d;
        cccd = "";
    }

    // Constructor with name and address
    Student(string n, string a) {
        name = n;
        address = a;
        birthdate = Date();
        cccd = "";
    }

    // Constructor with name, address and birthdate
    Student(string n, string a, Date d) {
        name = n;
        address = a;
        birthdate = d;
        cccd = "";
    }

    // Constructor with all properties
    Student(string n, string a, Date d, string c) {
        name = n;
        address = a;
        birthdate = d;
        cccd = c;
    }

    // Set student information
    void setStudentInfo() {
        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter address: ";
        getline(cin, address);

        cout << "Enter CCCD: ";
        getline(cin, cccd);
    }

    // Get student by CCCD
    Student getStudentInfo(string inputCCCD) {
        if (cccd == inputCCCD) {
            return *this;
        }

        return Student();
    }

    // Getters
    string getName() {
        return name;
    }

    string getAddress() {
        return address;
    }

    string getCCCD() {
        return cccd;
    }

    // Display student information
    void display() {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: ";
        birthdate.display();
        cout << endl;
        cout << "CCCD: " << cccd << endl;
    }
};


int main() {

    Student student1;

    Student student2("Huong");

    Student student3("Vo Van Ngan", "Ho Chi Minh City");

    Date date1(2007, 6, 12);

    Student student4(
        "Tri",
        "Ho Chi Minh City",
        date1,
        "012345678901"
    );

    cout << "Student 4:" << endl;
    student4.display();

    cout << "\nSearch student by CCCD:" << endl;

    Student result = student4.getStudentInfo("012345678901");

    result.display();

    return 0;
}