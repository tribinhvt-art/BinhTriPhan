#include <iostream>
#include <string>
using namespace std;

 struct Computer {
        int    Id;
        string Ten_may;
        string Pwd;
        string Hdh;
        string Username;
        string Model;
        int    year;
    };

void getComputerInfo(Computer computers[],int so_luong) {
   cout << "Nhap Id máy:";
   int Id_nhap_tay;
   cin >> Id_nhap_tay;

   for ( int i = 0 ; i < so_luong ; i++ ) {
      if (Id_nhap_tay == computers[i].Id) {
        cout << "======== ID: " << Id_nhap_tay << " ========";
        cout << "Ten may: " <<  computers[i].Ten_may;
        cout << "He dieu hanh: " <<  computers[i].Hdh;
        cout << "Username " <<  computers[i].Username;
        cout << "Password " <<  computers[i].Pwd;
        cout << "Model " <<  computers[i].Model;
        cout << "Year " <<  computers[i].year;
      }
   }

}

Computer getComputerInfo1(Computer computers[],int so_luong) {
   cout << "Nhap Id máy:";
   int Id_nhap_tay;
   cin >> Id_nhap_tay;

   for ( int i = 0 ; i < so_luong ; i++ ) {
      if (Id_nhap_tay == computers[i].Id) {
        return computers[i];
      }
   }

}

void getComputers(Computer computers[], int so_luong) {
    for (int i = 0 ; i < so_luong ; i++) {
        cout << "Id may: " << computers[i].Id;
        cout << "Ten may: " <<  computers[i].Ten_may;
        cout << "He dieu hanh: " <<  computers[i].Hdh;
        cout << "Username " <<  computers[i].Username;
        cout << "Password " <<  computers[i].Pwd;
        cout << "Model " <<  computers[i].Model;
        cout << "Year " <<  computers[i].year;
    }
}

void getAllComputerInfo(Computer computers[], int so_luong) {
  for (int i = 0 ; i < so_luong ; i++) {
    cout << "Nhap id may: ";
    cin >> computers[i].Id;
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
   string phong_lab;
   string chuc_nang;
   cout << "Nhap thong tin Lab: ";
   cout << "Nhap chuc nang phong lab:";   
   cin >> phong_lab;
   cin >> chuc_nang;
   cout << "Phong lab: " << phong_lab;
   cout << "Chuc nang: " << chuc_nang;
}

int main() {

    int so_luong;
    cout << "Nhap so luong may: ";
    cin >> so_luong;

    Commputer computers[so_luong];



    // lay toan bo thong tin may tinh
    getAllComputerInfo(computers, so_luong);
    
    //cau 1:
    showLabInfo();

    //cau 2:
    getComputerInfo(computers,so_luong);

    //cau 3:
    Computer cau_3 = getComputerInfo1(computers,so_luong);
    

    //cau 4:
    getComputers(cau_3);
    

    //cau 5:
    

}

