#include <iostream>
using namespace std;

int main() {
    int x, n;
    int result = 1;

    cout << "Nhap x: ";
    cin >> x;

    cout << "Nhap n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        result = result * x;
    }

    cout << x << "^" << n << " = " << result;

    return 0;
}