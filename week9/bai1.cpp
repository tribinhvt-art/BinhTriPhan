#include <iostream>
#include <string>
using namespace std;

  
struct restaurent {

    struct food {
      string id;
      string name;
      double price;
      int so_luong;
    };

    struct order {
      string id;
      string tenkhach;
      string dia_chi;
      string mon_an;
      int so_luongconlai;
      string trang_thai;
    };

    string name;
    string address;
    string phone;
    food mon_an[100];
    order orders[100];
    int foodcount;
    int ordercount;
    int dem_mon_an = 0;

    void nhap_thong_tin() {
      cout << "Nhap thong tin mon: \n";
      cin >> name;
      cout << "Nhap thong dia chi cua hang: \n";
      cin >> address;
      cout << "Nhap so dien thoai: \n";
      cin >> phone;
    }

    void them_mon_an() {
      cout << "Nhap Id mon: \n";
      cin >> mon_an[dem_mon_an].id
      cout << "Nhap ten mon: \n";
      cin >> mon_an[dem_mon_an].name;
      cout << "Nhap gia mon: \n";
      cin >> mon_an[dem_mon_an].price;
      cout << "So dien thoai: \n";
      cin >> mon_an[dem_mon_an].sdt;
      dem_mon_an++;
    }

    void hien_thi_danh_sach() {
      for (int i = 0; i < 100; i++) {
        cout << "============================\n"
        cout << mon_an[i].id;
        cout << mon_an[i].name;
        cout << mon_an[i].price;
        cout << mon_an[i].so_luong;
      }   
    }

    void tim_mon_an_theo_ma_hoac_ten() {
     string ten_mon;
     cout << "Nhap ten mon hoac ma mon: ";
     cin >> ten_mon;
     for (int i = 0; i < 100; i++) {
        if (mon_an[i].name == ten_mon) {
          cout << "============================\n"
          cout << mon_an[i].id;
          cout << mon_an[i].name;
          cout << mon_an[i].price;
          cout << mon_an[i].sdt;
        } 
      }  
    }

    void cap_nhat_gia() {
      string ten_mon;
      cout << "Nhap ten mon hoac ma mon: ";
      cin >> ten_mon;
      for (int i = 0; i < 100; i++) {
        if (mon_an[i].name == ten_mon) {
          cout << "============================\n"
          cout << "Cap nhat mon an: \n";
          cin >> mon_an[i].price;
          cout << "Cap nhat so luong mon an: \n";
          cin >> mon_an[i].so_luong;
        } 
      } 
    }

    void don_hang_moi() {
      cout << "Nhap Id don hang: ";
      cin >> orders[ordercount].id;

      cout << "Nhap ten khach hang: ";
      cin >> orders[ordercount].tenkhach;

      cout << "Nhap dia chi: ";
      cin >> orders[ordercount].dia_chi;

      cout << "Nhap mon an: ";
      cin >> orders[ordercount].mon_an;

      cout << "Nhap so luong: ";
      cin >> orders[ordercount].so_luongconlai;

      cout << "Nhap trang thai: ";
      cin >> orders[ordercount].trang_thai;

      ordercount++;
    }

    void kiemtramonan() {
      for (int i = 0; i < 100; i++) {
        if (mon_an[i].name == ten_mon) {
          cout << "Mon an co ton tai \n";
          cout << mon_an[i].so_luong;
        } 
      } 
    }

    void tongtiencuadonhang() {
      for (int i = 0; i < 100; i++) {
         for (int s = 0; s < 100; s++) {
           if (orders[i].name == mon_an[s].price) {
             cout << "Tong tien cua don_hang la: " << mon_an[s].price << "\n";
           } 
         }  
      } 
    }
};

int main() {

}