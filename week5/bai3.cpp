#include <iostream>
using namespace std;

int main() {
    int n;
    int sum = 0;

    cout << "Nhap n: ";
    cin >> n;

    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum = sum + i;
        }
    }

    if (sum == n) {
        cout << n << " la so hoan hao";
    } else {
        cout << n << " khong phai la so hoan hao";
    }

    return 0;
}