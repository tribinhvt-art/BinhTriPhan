#include <iostream>
using namespace std;

int main() {
    int n;
    int count = 0;

    cout << "Nhap n: ";
    cin >> n;

    cout << "Divisors: ";

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
            count++;
        }
    }

    cout << endl;
    cout << "Number of divisors: " << count;

    return 0;
}