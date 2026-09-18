#include <iostream>
#include <string>
using namespace std;

void swapValues(int& x, int& y) {
  x = 20;
  y = 15;
}

int main() {
  int a = 15, b = 20;
  cout << "- Before: a = " << a << ", b = " << b;
  swapValues(a,b);
  cout << "- After: a = " << a << ", b = " << b;
}
