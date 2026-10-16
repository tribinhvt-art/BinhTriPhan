#include <iostream>
#include <string>
using namespace std;

void swapValues(int& x, int& y) {
  // đặt temp là x vì khi đổi x thành y thì x sẽ mang giá trị của y
  int temp = x;
  // đặt x = y
  x = y;
  // y = x ban đầu
  y = temp;
}

int main() {
  // tạo a = 15, b =  20 để đẩy vào swapValues
  int a = 15, b = 20;
  cout << "- Before: a = " << a << ", b = " << b;
  swapValues(a,b);
  cout << "- After: a = " << a << ", b = " << b;
}
