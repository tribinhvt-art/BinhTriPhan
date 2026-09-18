#include <iostream>
#include <string>
using namespace std;

int main() {
    int a = 10;
    int& x = a;
    x =  10;
    cout << a << endl; // 10 because technically referrence varible is like giving another name for the varible itself while keeping the old name working.                      
    cout << x << endl;     // It should contain the damn same value!
    return 0;
}