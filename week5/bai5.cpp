#include <iostream>
using namespace std;

int main() {
    int n;
    int reverse = 0;

    cout << "Nhap n: ";
    cin >> n;

    while (n > 0) {
        int digit = n % 10;

        reverse = reverse * 10 + digit;

        n = n / 10;
    }

    cout << "So dao nguoc: " << reverse;

    return 0;
}