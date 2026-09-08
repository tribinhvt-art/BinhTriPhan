#include <iostream>
using namespace std;

int main() {
    int n;
    int temp;
    int reverse = 0;

    cout << "Nhap n: ";
    cin >> n;

    temp = n;

    while (temp > 0) {
        int digit = temp % 10;
        reverse = reverse * 10 + digit;
        temp = temp / 10;
    }

    if (reverse == n) {
        cout << n << " la so doi xung";
    } else {
        cout << n << " khong phai so doi xung";
    }

    return 0;
}