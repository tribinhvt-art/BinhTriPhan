#include <iostream>
#include <string>
using namespace std;

void showStudentName(string name) {
    cout << "Hello," << name << "!" << endl;
    cout << "Welcome to our class!" << endl;
}

void showStudentId(string studentId) {
    cout << "Student ID: " << studentId << "!" << endl;
}

int main() {
    string studentName;
    string studentId;

    cout << "Enter your name: " << endl;
    getline(cin, studentName);
    cout << "Enter student id: " << endl;
    cin >> studentId;

    showStudentName(studentName);
    showStudentId(studentId);

    return 0;
}