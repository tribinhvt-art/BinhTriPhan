#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct lab {
    string ma_phong;
    string chuc_nang;
};


lab labs[100];
int so_luonglab;


struct Computer {
    int Id;
    string Ten_may;
    string Pwd;
    string Hdh;
    string Username;
    string Model;
    int year;
};


void getComputerInfo(Computer computers[], int so_luong, int Id_nhap_tay) {

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

Computer getComputerInfo1(Computer computers[], int so_luong, int Id_nhap_tay) {

    for (int i = 0; i < so_luong; i++) {
        if (Id_nhap_tay == computers[i].Id) {
            return computers[i];
        }
    }

    return Computer{};
}

Computer* getComputers(Computer computers[], int so_luong) {
    return computers;
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

void getLabInfo() {
    

    cout << "Nhap so luong labs: ";
    cin >> so_luonglab;
    for (int i = 0 ; i < so_luonglab ; i++ ) {
      cout << "Nhap ma phong lab: ";
      cin >> labs[i].ma_phong;

      cout << "Nhap chuc nang phong lab: ";
      cin >> labs[i].chuc_nang;
    }

    
}

void showLabInfo() {
  for (int i = 0 ; i < so_luonglab ; i++ ) {
      cout << "Mã Phòng Lab: " << labs[i].ma_phong << "\n";
      cout << "Chức năng Phòng Lab: " << labs[i].chuc_nang << "\n";
    }
}

int main() {


    getLabInfo();
    showLabInfo();


    int so_luong;

    cout << "Nhap so luong may: ";
    cin >> so_luong;

    Computer computers[so_luong];
    

    // Nhap toan bo thong tin
    getAllComputerInfo(computers, so_luong);

    // Cau 1
    showLabInfo();

    // Cau 2
    int Id_nhap_tay;
    cout << "Nhap Id tu tay:" ;
    cin >> Id_nhap_tay;
    getComputerInfo(computers, so_luong, Id_nhap_tay);

    // Cau 3
  
    cout << "Nhap Id tu tay:" ;
    cin >> Id_nhap_tay;
    Computer cau_3 = getComputerInfo1(computers, so_luong, Id_nhap_tay);

    // Cau 4
    Computer* sob = getComputers(computers, so_luong);

    return 0;
}