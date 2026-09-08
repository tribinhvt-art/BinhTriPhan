#include <iostream>
using namespace std;

int main() {
    int n;
    int factorial = 1;

    cout << "Nhap n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        factorial = factorial * i;
    }

    cout << n << "! = " << factorial;

    return 0;
}