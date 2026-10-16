
#include <iostream>
#include <string>
using namespace std;

// 1. Lop cha Employee
class Employee {
private:
    string cccd;
    string sdt;
    string address;

public:
    // Constructor mac dinh
    Employee() {
        cccd = "";
        sdt = "";
        address = "";
    }

    // Constructor co tham so
    Employee(string c, string p, string a) {
        cccd = c;
        sdt = p;
        address = a;
    }

    // Getters
    string getCCCD() const {
        return cccd;
    }

    string getSDT() const {
        return sdt;
    }

    string getAddress() const {
        return address;
    }

    // Setters
    void setCCCD(string c) {
        cccd = c;
    }

    void setSDT(string p) {
        sdt = p;
    }

    void setAddress(string a) {
        address = a;
    }
};

// 2. Lop HourlyEmployee
class HourlyEmployee : public Employee {
private:
    int soGioLamViec;
    double donGia;

public:
    // Constructor mac dinh
    HourlyEmployee() : Employee() {
        soGioLamViec = 0;
        donGia = 0.0;
    }

    // Constructor co tham so
    HourlyEmployee(string c, string p, string a,
                   int soGio, double dg)
        : Employee(c, p, a) {
        soGioLamViec = soGio;
        donGia = dg;
    }

    // Getters
    int getSoGioLamViec() const {
        return soGioLamViec;
    }

    double getDonGia() const {
        return donGia;
    }

    // Setters
    void setSoGioLamViec(int g) {
        soGioLamViec = g;
    }

    void setDonGia(double dg) {
        donGia = dg;
    }

    // Tinh luong theo gio
    double calculateSalary() const {
        return soGioLamViec * donGia;
    }
};

// 3. Lop MonthlyEmployee
class MonthlyEmployee : public Employee {
private:
    double luongCoBan;
    double phuCap;
    double heSoThuong;

public:
    // Constructor mac dinh
    MonthlyEmployee() : Employee() {
        luongCoBan = 0.0;
        phuCap = 0.0;
        heSoThuong = 0.0;
    }

    // Constructor co tham so
    MonthlyEmployee(string c, string p, string a,
                    double lcb, double pc, double hs)
        : Employee(c, p, a) {
        luongCoBan = lcb;
        phuCap = pc;
        heSoThuong = hs;
    }

    // Getters
    double getLuongCoBan() const {
        return luongCoBan;
    }

    double getPhuCap() const {
        return phuCap;
    }

    double getHeSoThuong() const {
        return heSoThuong;
    }

    // Setters
    void setLuongCoBan(double lcb) {
        luongCoBan = lcb;
    }

    void setPhuCap(double pc) {
        phuCap = pc;
    }

    void setHeSoThuong(double hs) {
        heSoThuong = hs;
    }

    // Tinh luong thang
    double calculateSalary() const {
        return luongCoBan + phuCap * heSoThuong;
    }
};

// 4. Ham main
int main() {
    // Nhan vien mac dinh
    Employee e1;

    // Nhan vien tinh luong theo gio
    HourlyEmployee h1(
        "079123456789",
        "0901002003",
        "Ha Noi",
        160,
        50000
    );

    // Nhan vien tinh luong theo thang
    MonthlyEmployee m1(
        "079987654321",
        "0903004005",
        "Da Nang",
        15000000,
        2000000,
        1.2
    );

    // Hien thi Employee
    cout << "--- Employee e1 ---" << endl;
    cout << "CCCD: " << e1.getCCCD() << endl;
    cout << "SDT: " << e1.getSDT() << endl;
    cout << "Address: " << e1.getAddress() << endl;

    // Hien thi HourlyEmployee
    cout << "\n--- HourlyEmployee h1 ---" << endl;
    cout << "CCCD: " << h1.getCCCD() << endl;
    cout << "SDT: " << h1.getSDT() << endl;
    cout << "Address: " << h1.getAddress() << endl;
    cout << "So gio lam viec: "
         << h1.getSoGioLamViec() << endl;
    cout << "Don gia: " << h1.getDonGia() << endl;
    cout << "Luong: " << h1.calculateSalary() << endl;

    // Hien thi MonthlyEmployee
    cout << "\n--- MonthlyEmployee m1 ---" << endl;
    cout << "CCCD: " << m1.getCCCD() << endl;
    cout << "SDT: " << m1.getSDT() << endl;
    cout << "Address: " << m1.getAddress() << endl;
    cout << "Luong co ban: " << m1.getLuongCoBan() << endl;
    cout << "Phu cap: " << m1.getPhuCap() << endl;
    cout << "He so thuong: " << m1.getHeSoThuong() << endl;
    cout << "Luong: " << m1.calculateSalary() << endl;

    return 0;
}
