#include <iostream>
using namespace std;


void calculator(int a, int b, int x) {
    if (a != 0) {
        x = -b / a;
        cout << "x = " << x;
    }
    else {
        if (b == 0) {
            cout << "Phuong trinh vo so nghiem";
        } else {
            cout << "Phuong trinh vo nghiem"; 
        }
    }
}


int main() {
    int a;
    int b;
    int x;

    cout << "Nhap a, b cua phuong bac nhat: ";
    cin >> a >> b;
    int equation1 = a*x + b;

    calculator(a,b,x);
}