#include <iostream>
#include <string>
using namespace std;

// Amount of students
const int StudentNum = 20;

int main() {

    // Student Data Storage
    string studentName[StudentNum];
    int studentAge[StudentNum];
    int studentIds[StudentNum];

    for (int i = 0; i < StudentNum; i++) {

        cout << "Nhap ten sinh vien " << i + 1 << ": ";
        getline(cin, studentName[i]);

        cout << "Nhap tuoi sinh vien " << i + 1 << ": ";
        cin >> studentAge[i];

        cout << "Nhap ma so sinh vien " << i + 1 << ": ";
        cin >> studentIds[i];

        
    }

    return 0;
}