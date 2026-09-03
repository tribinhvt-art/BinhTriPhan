#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 20;

int main() {

    int N;
    
    string studentName[MAX_STUDENTS];
    string studentId[MAX_STUDENTS];
    string studentPhone[MAX_STUDENTS];

    cout << "Enter number of students: ";
    cin >> N;

    while (N < 2 || N > 20) {
        cout << "Enter again: ";
        cin >> N;
    }

    for (int i = 0; i < N; i++) {
        cout << "Enter name: ";
        cin >> studentName[i];

        cout << "Enter ID: ";
        cin >> studentId[i];

        cout << "Enter phone: ";
        cin >> studentPhone[i];
    }

    for (int i = 0; i < N; i++) {
        cout << "Student " << i + 1 << endl;
        cout << "Name: " << studentName[i] << endl;
        cout << "ID: " << studentId[i] << endl;
        cout << "Phone: " << studentPhone[i] << endl;
    }

    return 0;
}