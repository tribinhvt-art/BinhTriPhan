#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;
    double GPA;
    char GPAletters;
    bool passorfail;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your GPA: ";
    cin >> GPA;

    cout << "GPA in Letter: ";
    cin >> GPAletters;

    cout << "Pass or fail (1 = pass, 0 = fail): ";
    cin >> passorfail;

    return 0;
}