#include <cstdio>
#include <iostream>
using namespace std;

struct Sach {
    int maSach;
    char tenSach[200];
    char tenTacGia[50];
    double giaSach;

    void nhapSach() {
        cout << "Nhap ID cuon sach: ";
        cin >> maSach;
        cin.ignore();

        cout << "Nhap tieu de sach: ";
        cin.getline(tenSach, 200);

        cout << "Nhap ten tac gia: ";
        cin.getline(tenTacGia, 50);

        cout << "Nhap gia sach: ";
        cin >> giaSach;
        cin.ignore();
    }

    void hienThiSach() {
        printf("Ma sach    : %d\n", maSach);
        printf("Ten sach   : %s\n", tenSach);
        printf("Tac gia    : %s\n", tenTacGia);
        printf("Gia        : %.1f\n", giaSach);
    }
};

struct ThuVien {
    int maThuVien;
    char tenThuVien[100];
    int soSach;
    Sach danhSach[100];

    void hienThiThuVien() {
        cout << "===== THU VIEN: " << tenThuVien
             << " | ID: " << maThuVien << " =====\n";

        for (int i = 0; i < soSach; i++) {
            danhSach[i].hienThiSach();
            cout << "--------------------------\n";
        }
    }

    void nhapThuVien() {
        cout << "Nhap ID thu vien: ";
        cin >> maThuVien;
        cin.ignore();

        cout << "Nhap ten thu vien: ";
        cin.getline(tenThuVien, 100);

        cout << "Nhap tong so sach: ";
        cin >> soSach;
        cin.ignore();

        cout << endl;

        for (int i = 0; i < soSach; i++) {
            cout << "--- Nhap cuon sach so " << i + 1 << " ---\n";
            danhSach[i].nhapSach();
        }

        cout << endl;
    }

    void timSach(int maCanTim) {
        for (int i = 0; i < soSach; i++) {
            if (danhSach[i].maSach == maCanTim) {
                danhSach[i].hienThiSach();
                return;
            }
        }

        cout << "Khong co cuon sach nao co ID nay!\n";
    }

    void themSach(Sach sachMoi) {
        if (soSach < 100) {
            danhSach[soSach] = sachMoi;
            soSach++;
        }
    }

    Sach layThongTinSach(int maCanTim) {
        for (int i = 0; i < soSach; i++) {
            if (danhSach[i].maSach == maCanTim) {
                return danhSach[i];
            }
        }

        Sach sachRong;
        sachRong.maSach = -1;
        return sachRong;
    }

    Sach* layDanhSachSach() {
        return danhSach;
    }
};

int main() {
    ThuVien thuVienChinh;

    thuVienChinh.nhapThuVien();
    thuVienChinh.hienThiThuVien();

    Sach sachThem;
    sachThem.nhapSach();

    thuVienChinh.themSach(sachThem);

    cout << endl;

    int maTimKiem;

    cout << "Nhap ma sach can tra cuu: ";
    cin >> maTimKiem;

    thuVienChinh.timSach(maTimKiem);

    cout << endl;

    cout << "Nhap ma sach can xem chi tiet: ";
    cin >> maTimKiem;

    Sach ketQua = thuVienChinh.layThongTinSach(maTimKiem);

    if (ketQua.maSach != -1) {
        cout << "Thong tin cuon sach tim duoc:\n";
        ketQua.hienThiSach();
    } 
    else {
        cout << "Khong tim thay cuon sach phu hop!\n";
    }

    Sach* danhSachSach = thuVienChinh.layDanhSachSach();

    cout << "Thong tin cuon sach dau tien:\n";
    danhSachSach[0].hienThiSach();

    return 0;
}