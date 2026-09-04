#include <iostream>
#include <string>
using namespace std;

void printName(string inputName) {
  cout << inputName ;
}

int main() {
    string inputName;
    cout << "Nhap ten: ";
    getline(cin, inputName);

    printName(inputName);
}