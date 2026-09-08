#include <iostream>
using namespace std;

int main() {
    int a, b;
    int gcd = 1;
    int lcm;

    cout << "Nhap a: ";
    cin >> a;

    cout << "Nhap b: ";
    cin >> b;

    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    lcm = (a * b) / gcd;

    cout << "Boi chung nho nhat: " << lcm;

    return 0;
}