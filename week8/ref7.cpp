#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void edit(string &ref) {
    ref = "Hi " + ref;
}

void join(string &ref, string &other) {
    ref += other;
}

void capitalize(string &ref) {
    if (!ref.empty()) {
        ref[0] = toupper(ref[0]);
    }
}

int main() {
    string first = "student";
    string second = " life";

    string &ref = first;

    cout << "Original: " << first << endl;

    edit(ref);
    cout << "Edited: " << first << endl;

    join(first, second);
    cout << "Joined: " << first << endl;

    string title = "programming";
    capitalize(title);
    cout << "Title: " << title << endl;

    string city = "Hanoi";
    string &alias = city;
    alias = "Da Nang";

    cout << "City: " << city << endl;
    cout << "Alias: " << alias << endl;

    return 0;
}