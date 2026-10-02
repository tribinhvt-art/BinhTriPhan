#include <iostream>
#include <string>
using namespace std;

class Food {
public:
    string id;
    string name;
    double price;
    int quantity;

    void input() {
        cout << "Nhap ten: ";
        getline(cin, name);

        cout << "Nhap gia: ";
        cin >> price;

        quantity = 0;
        cin.ignore();
    }

    void display() {
        cout << name << " - " << price
             << " (" << quantity << ")" << endl;
    }
};

int main() {
    Food foods[3];

    // Nhap 3 mon an
    for (int i = 0; i < 3; i++) {
        foods[i].input();
    }

    // In danh sach
    cout << "\n=== Danh sach mon an ===" << endl;

    for (int i = 0; i < 3; i++) {
        foods[i].display();
    }

    // Tim mon an theo ten
    string searchName;
    cout << "\nNhap ten mon can tim: ";
    getline(cin, searchName);

    bool found = false;

    for (int i = 0; i < 3; i++) {
        if (foods[i].name == searchName) {
            cout << "Tim thay: ";
            foods[i].display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay mon an!" << endl;
    }

    // Cap nhat gia
    string updateName;
    cout << "\nNhap ten mon can cap nhat gia: ";
    getline(cin, updateName);

    found = false;

    for (int i = 0; i < 3; i++) {
        if (foods[i].name == updateName) {
            double newPrice;

            cout << "Nhap gia moi: ";
            cin >> newPrice;

            foods[i].price = newPrice;
            found = true;

            cout << "Cap nhat thanh cong!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay mon an!" << endl;
    }

    // In danh sach sau khi cap nhat
    cout << "\n=== Danh sach sau khi cap nhat ===" << endl;

    for (int i = 0; i < 3; i++) {
        foods[i].display();
    }

    return 0;
}