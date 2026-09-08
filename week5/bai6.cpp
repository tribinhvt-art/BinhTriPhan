#include <iostream>
using namespace std;

int main() {
    int n;
    int sum = 0;

    cout << "Nhap n: ";
    cin >> n;

    while (n > 0) {
        int digit = n % 10;

        sum = sum + digit;

        n = n / 10;
    }

    cout << "Tong cac chu so: " << sum;

    return 0;
}