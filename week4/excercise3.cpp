#include <iostream>
using namespace std;

int main() {
    int n;
    int count = 0;

    cout << "Nhap n: ";
    cin >> n;

    if (n <= 1) {
        cout << "Khong phai so nguyen to";
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }

        if (count == 2) {
            cout << n << " la so nguyen to";
        }
        else {
            cout << n << " khong phai so nguyen to";
        }
    }

    return 0;
}