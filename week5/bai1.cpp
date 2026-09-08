#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    int max;

    cout << "Nhap a: ";
    cin >> a;

    cout << "Nhap b: ";
    cin >> b;

    cout << "Nhap c: ";
    cin >> c;

    max = a;

    if (b > max) {
        max = b;
    }

    if (c > max) {
        max = c;
    }

    cout << "So lon nhat la: " << max;

    return 0;
}