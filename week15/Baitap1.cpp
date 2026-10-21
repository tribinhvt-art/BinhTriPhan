
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Class cha
class PT {
public:
    virtual void solve() {
        cout << "Giai phuong trinh\n";
    }

    virtual ~PT() {}
};

// Phuong trinh bac 1: ax + b = 0
class PTB1 : public PT {
private:
    double a, b;

public:
    PTB1(double a, double b) {
        this->a = a;
        this->b = b;
    }

    void solve() override {
        if (a != 0) {
            double solution = -b / a;
            cout << "Phuong trinh co 1 nghiem: x = "
                 << solution << endl;
        }
        else if (b != 0) {
            cout << "Phuong trinh vo nghiem\n";
        }
        else {
            cout << "Phuong trinh co vo so nghiem\n";
        }
    }
};

// Phuong trinh bac 2: ax^2 + bx + c = 0
class PTB2 : public PT {
private:
    double a, b, c;

public:
    PTB2(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void solve() override {
        if (a == 0) {
            cout << "Day khong phai phuong trinh bac 2\n";

            if (b != 0) {
                cout << "Phuong trinh bac 1 co nghiem: x = "
                     << -c / b << endl;
            }
            else if (c != 0) {
                cout << "Phuong trinh vo nghiem\n";
            }
            else {
                cout << "Phuong trinh co vo so nghiem\n";
            }

            return;
        }

        double delta = b * b - 4 * a * c;

        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);

            cout << "Phuong trinh co 2 nghiem phan biet:\n";
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
        else if (delta == 0) {
            double x = -b / (2 * a);

            cout << "Phuong trinh co nghiem kep: x = "
                 << x << endl;
        }
        else {
            cout << "Phuong trinh vo nghiem trong tap so thuc\n";
        }
    }
};

int main() {
    PTB1 pt1(2, -4);
    PTB2 pt2(1, -3, 2);

    PT* p;

    p = &pt1;
    p->solve();

    p = &pt2;
    p->solve();

    return 0;
}
