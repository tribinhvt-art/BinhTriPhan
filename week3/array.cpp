#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 20; -- student counter

    string name[20]; --- student name 
    string studentID[20]; --- student ids
    string phone[20]; --- studen phones

    for(int i = 0; i < n; i++)
    {
        cout << "Enter student " << i + 1 << ":" << endl;
        cout << "Name: ";
        getline(cin, name[i]);
        cout << "ID: ";
        getline(cin, studentID[i]);
        cout << "Phone: ";
        getline(cin, phone[i]);
        cout << endl;
    }

    cout << "=============== STUDENT LIST ================\n\n" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << endl;
        cout << "Name       : " << name[i] << endl;
        cout << "Student ID : " << studentID[i] << endl;
        cout << "Phone      : " << phone[i] << endl;
        cout << endl;
    }


    cout << endl;
    cout << "==============================================" << endl;
    cout << "Total students: " << n << endl;
    cout << "==============================================" << endl;

    return 0;
}