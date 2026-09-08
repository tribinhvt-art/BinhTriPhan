#include <iostream>
using namespace std;

int main() {
    int a, b;
    int gcd = 1;

    cout << "Nhap a: ";
    cin >> a;

    cout << "Nhap b: ";
    cin >> b;

    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    cout << "Uoc chung lon nhat: " << gcd;

    return 0;
}