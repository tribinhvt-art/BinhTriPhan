#include <iostream>
#include <string>
using namespace std;

void changeValue(int x) {
  x = 100;
}

void changeRef(int& x) {
  x = 200;
}

int main() {
    int  a = 5;
    changeValue(a);
    cout << "After changing value: " << a << endl;
    changeRef(a);
    cout << "After changing value: " << a << endl;
    return 0;
}