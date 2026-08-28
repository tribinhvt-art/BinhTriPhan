#include <iostream>
#include <string>

using namespace std;

int main() {

    // Variables
    string name = "Anna";
    int age = 20;
    double gpa = 8.5;
    char grade = 'A';

    // Constant
    const int currentYear = 2026;

    // Calculations
    int birthYear = currentYear - age;
    int nextAge = age + 1;

    // Updating a variable
    int score = 80;
    score = score + 10;

    cout << "==============================" << endl;
    cout << "       MY FIRST C++ APP" << endl;
    cout << "==============================" << endl;

    cout << "Name          : " << name << endl;
    cout << "Age           : " << age << endl;
    cout << "GPA           : " << gpa << endl;
    cout << "Grade         : " << grade << endl;

    cout << endl;

    cout << "Birth Year    : " << birthYear << endl;
    cout << "Next Age      : " << nextAge << endl;

    cout << endl;

    cout << "Initial Score : 80" << endl;
    cout << "Updated Score : " << score << endl;

    cout << endl;

    cout << "Goal: Become a better programmer!" << endl;
    cout << "==============================" << endl;

    return 0;
}