
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// =====================================
// STRUCT LAB
// =====================================
struct lab {
    string ma_phong;
    string chuc_nang;
};

lab labs[100];
int so_luonglab = 0;

// =====================================
// STRUCT COMPUTER
// =====================================
struct Computer {
    int Id;
    string Ten_may;
    string Pwd;
    string Hdh;
    string Username;
    string Model;
    int year;
};

// =====================================
// STRUCT USER
// Dung de tra ve Username va Password
// =====================================
struct User {
    string Username;
    string Pwd;
};

// =====================================
// NHAP THONG TIN LAB
// =====================================
void getLabInfo() {
    do {
        cout << "Nhap so luong labs (1-100): ";
        cin >> so_luonglab;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            so_luonglab = 0;
        }

        if (so_luonglab < 1 || so_luonglab > 100) {
            cout << "So luong khong hop le!\n";
        }
    } while (so_luonglab < 1 || so_luonglab > 100);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < so_luonglab; i++) {
        cout << "\n--- Nhap Lab " << i + 1 << " ---\n";

        cout << "Nhap ma phong lab: ";
        getline(cin, labs[i].ma_phong);

        cout << "Nhap chuc nang phong lab: ";
        getline(cin, labs[i].chuc_nang);
    }
}

// =====================================
// HIEN THI THONG TIN LAB
// =====================================
void showLabInfo() {
    cout << "\n======== DANH SACH LAB ========\n";

    for (int i = 0; i < so_luonglab; i++) {
        cout << "Ma phong Lab: " << labs[i].ma_phong << endl;
        cout << "Chuc nang: " << labs[i].chuc_nang << endl;
        cout << "------------------------------\n";
    }
}

// =====================================
// CAU 1: TIM VA IN THONG TIN COMPUTER
// =====================================
void getComputerInfo(
    const Computer computers[],
    int so_luong,
    int Id_nhap_tay
) {
    for (int i = 0; i < so_luong; i++) {
        if (Id_nhap_tay == computers[i].Id) {
            cout << "\n======== THONG TIN MAY TINH ========\n";
            cout << "ID may: " << computers[i].Id << endl;
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

// =====================================
// CAU 2: TIM VA TRA VE DOI TUONG COMPUTER
// =====================================
Computer getComputerInfo1(
    const Computer computers[],
    int so_luong,
    int Id_nhap_tay
) {
    for (int i = 0; i < so_luong; i++) {
        if (Id_nhap_tay == computers[i].Id) {
            return computers[i];
        }
    }

    // Id = -1 bao hieu khong tim thay
    Computer emptyComputer{};
    emptyComputer.Id = -1;
    return emptyComputer;
}

// =====================================
// CAU 3: TRA VE CON TRO DEN MANG COMPUTER
// =====================================
const Computer* getComputers(
    const Computer computers[],
    int so_luong
) {
    return computers;
}

// =====================================
// HAM HIEN THI MOT COMPUTER
// =====================================
void showComputer(const Computer& computer) {
    cout << "ID may: " << computer.Id << endl;
    cout << "Ten may: " << computer.Ten_may << endl;
    cout << "He dieu hanh: " << computer.Hdh << endl;
    cout << "Username: " << computer.Username << endl;
    cout << "Password: " << computer.Pwd << endl;
    cout << "Model: " << computer.Model << endl;
    cout << "Year: " << computer.year << endl;
}

// =====================================
// NHAP THONG TIN TOAN BO COMPUTER
// =====================================
void getAllComputerInfo(Computer computers[], int so_luong) {
    for (int i = 0; i < so_luong; i++) {
        cout << "\n--- Nhap thong tin may " << i + 1 << " ---\n";

        cout << "Nhap ID may: ";
        cin >> computers[i].Id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nhap ten may: ";
        getline(cin, computers[i].Ten_may);

        cout << "Nhap he dieu hanh: ";
        getline(cin, computers[i].Hdh);

        cout << "Nhap username: ";
        getline(cin, computers[i].Username);

        cout << "Nhap password: ";
        getline(cin, computers[i].Pwd);

        cout << "Nhap model: ";
        getline(cin, computers[i].Model);

        cout << "Nhap year: ";
        cin >> computers[i].year;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// =====================================
// CAU 4: LAY USERNAME VA PASSWORD THEO ID
// =====================================
User getUserAndPassword(
    const Computer computers[],
    int so_luong,
    int Id_nhap_tay
) {
    for (int i = 0; i < so_luong; i++) {
        if (Id_nhap_tay == computers[i].Id) {
            return User{
                computers[i].Username,
                computers[i].Pwd
            };
        }
    }

    return User{"N/A", "N/A"};
}

// =====================================
// MAIN
// =====================================
int main() {
    // Nhap va hien thi Lab
    getLabInfo();
    showLabInfo();

    // Nhap so luong may tinh
    int so_luong;

    do {
        cout << "\nNhap so luong may (1-100): ";
        cin >> so_luong;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            so_luong = 0;
        }

        if (so_luong < 1 || so_luong > 100) {
            cout << "So luong khong hop le!\n";
        }
    } while (so_luong < 1 || so_luong > 100);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Khai bao mang dung chuan C++
    Computer computers[100];

    // Nhap toan bo thong tin may tinh
    getAllComputerInfo(computers, so_luong);

    // CAU 1: Tim va in thong tin may theo ID
    int Id_nhap_tay;

    cout << "\nNhap ID can tim (Cau 1): ";
    cin >> Id_nhap_tay;

    getComputerInfo(computers, so_luong, Id_nhap_tay);

    // CAU 2: Tra ve mot doi tuong Computer
    cout << "\nNhap ID can tim (Cau 2): ";
    cin >> Id_nhap_tay;

    Computer cau_2 = getComputerInfo1(
        computers, so_luong, Id_nhap_tay
    );

    if (cau_2.Id != -1) {
        cout << "\n=== COMPUTER TRA VE ===\n";
        showComputer(cau_2);
    } else {
        cout << "Khong tim thay may!\n";
    }

    // CAU 3: Lay danh sach may tinh
    cout << "\n=== DANH SACH MAY TINH ===\n";

    const Computer* sob = getComputers(computers, so_luong);

    for (int i = 0; i < so_luong; i++) {
        cout << "\nMay thu " << i + 1 << ":\n";
        showComputer(sob[i]);
    }

    // CAU 4: Lay username va password theo ID
    cout << "\nNhap ID can lay tai khoan (Cau 4): ";
    cin >> Id_nhap_tay;

    User u = getUserAndPassword(
        computers, so_luong, Id_nhap_tay
    );

    if (u.Username != "N/A") {
        cout << "\n=== THONG TIN TAI KHOAN ===\n";
        cout << "Username: " << u.Username << endl;
        cout << "Password: " << u.Pwd << endl;
    } else {
        cout << "Khong tim thay may!\n";
    }

    return 0;
}
