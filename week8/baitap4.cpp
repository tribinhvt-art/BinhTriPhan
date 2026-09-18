#include <iostream>
#include <string>
using namespace std;

int main() {
    string fullName;
    string studentId;
    string email;
    string hometown;

    cout << "Enter your full name: ";
    getline(cin, fullName);

    cout << "Enter your student ID: ";
    getline(cin, studentId);

    cout << "Enter your email: ";
    getline(cin, email);

    cout << "Enter your hometown: ";
    getline(cin, hometown);

    cout << "\n===== STUDENT PROFILE =====" << endl;

    cout << "Full name : " << fullName << endl;
    cout << "Student ID: " << studentId << endl;
    cout << "Email     : " << email << endl;
    cout << "Hometown  : " << hometown << endl;

    cout << "===========================" << endl;

    return 0;
}