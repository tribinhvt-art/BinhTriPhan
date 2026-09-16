#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Computer {
    int Id;
    string Ten_may;
    string Pwd;
    string Hdh;
    string Username;
    string Model;
    int year;
};

struct lab {
    string ma_phong;
    string chuc_nang;
};

void getComputerInfo(Computer computers[], int so_luong) {
    cout << "Nhap Id may: ";
    int Id_nhap_tay;
    cin >> Id_nhap_tay;

    for (int i = 0; i < so_luong; i++) {
        if (Id_nhap_tay == computers[i].Id) {
            cout << "======== ID: " << Id_nhap_tay << " ========\n";
            cout << "Ten may: " << computers[i].Ten_may << endl;
            cout << "He dieu hanh: " << computers[i].Hdh << endl;
            cout << "Username: " << computers[i].Username << endl;
            cout << "Password: " << computers[i].Pwd << endl;
            cout << "Model: " << computers[i].Model << endl;
            cout << "Year: " << computers[i].year << endl;
            return;
        }
    }

    cout << "Khong tim thay may!\n";
}

Computer getComputerInfo1(Computer computers[], int so_luong) {
    cout << "Nhap Id may: ";
    int Id_nhap_tay;
    cin >> Id_nhap_tay;

    for (int i = 0; i < so_luong; i++) {
        if (Id_nhap_tay == computers[i].Id) {
            return computers[i];
        }
    }

    return Computer{};
}

void getComputers(Computer computers[], int so_luong, Computer COMPUTERWTF[]) {
    for (int i = 0; i < so_luong; i++) {
        cout << "Id may: " << computers[i].Id << endl;
        COMPUTERWTF[i].Id = computers[i].Id;
        cout << "Ten may: " << computers[i].Ten_may << endl;
        COMPUTERWTF[i].Ten_may = computers[i].Ten_may;
        cout << "He dieu hanh: " << computers[i].Hdh << endl;
        COMPUTERWTF[i].Hdh = computers[i].Hdh;
        cout << "Username: " << computers[i].Username << endl;
        COMPUTERWTF[i].Username = computers[i].Username;
        cout << "Password: " << computers[i].Pwd << endl;
        COMPUTERWTF[i].Pwd = computers[i].Pwd;
        cout << "Model: " << computers[i].Model << endl;
        COMPUTERWTF[i].Model = computers[i].Model;
        cout << "Year: " << computers[i].year << endl;
        COMPUTERWTF[i].year = computers[i].year;
    }
}

void showComputer(Computer computer) {
    cout << "Id may: " << computer.Id << endl;
    cout << "Ten may: " << computer.Ten_may << endl;
    cout << "He dieu hanh: " << computer.Hdh << endl;
    cout << "Username: " << computer.Username << endl;
    cout << "Password: " << computer.Pwd << endl;
    cout << "Model: " << computer.Model << endl;
    cout << "Year: " << computer.year << endl;
}

void getAllComputerInfo(Computer computers[], int so_luong) {
    for (int i = 0; i < so_luong; i++) {
        cout << "Nhap id may: ";
        cin >> computers[i].Id;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nhap ten may: ";
        getline(cin, computers[i].Ten_may);

        cout << "Nhap he dieu hanh may: ";
        getline(cin, computers[i].Hdh);

        cout << "Nhap username may: ";
        getline(cin, computers[i].Username);

        cout << "Nhap Pwd may: ";
        cin >> computers[i].Pwd;

        cout << "Nhap Model may: ";
        cin >> computers[i].Model;

        cout << "Nhap year may: ";
        cin >> computers[i].year;
    }
}

void showLabInfo() {
    lab a;

    cout << "Nhap ma phong lab: ";
    cin >> a.ma_phong;

    cout << "Nhap chuc nang phong lab: ";
    cin >> a.chuc_nang;

    cout << "Phong lab: " << a.ma_phong << endl;
    cout << "Chuc nang: " << a.chuc_nang << endl;
}

int main() {

    int so_luong;

    cout << "Nhap so luong may: ";
    cin >> so_luong;

    Computer computers[so_luong];
    

    // Nhap toan bo thong tin
    getAllComputerInfo(computers, so_luong);

    // Cau 1
    showLabInfo();

    // Cau 2
    getComputerInfo(computers, so_luong);

    // Cau 3
    Computer cau_3 = getComputerInfo1(computers, so_luong);

    // Cau 4
    Computer COMPUTERWTF[so_luong];
    getComputers(computers, so_luong, COMPUTERWTF);

    return 0;
}