
#include <iostream>
#include <string>
using namespace std;

// 1. Class People
class People {
private:
    string cccd;
    string name;
    string address;

public:
    // Constructor mac dinh
    People() {
        cccd = "000000000000";
        name = "Unknown";
        address = "Unknown";
    }

    // Constructor co tham so
    People(string c, string n, string a) {
        cccd = c;
        name = n;
        address = a;
    }

    // Getters
    string getCccd() const {
        return cccd;
    }

    string getName() const {
        return name;
    }

    string getAddress() const {
        return address;
    }

    // Setters
    void setCccd(string c) {
        cccd = c;
    }

    void setName(string n) {
        name = n;
    }

    void setAddress(string a) {
        address = a;
    }
};

// 2. Class Student ke thua People
class Student : public People {
private:
    string mssv;
    int yearEntrance;

public:
    // Constructor mac dinh
    Student() : People() {
        mssv = "N/A";
        yearEntrance = 0;
    }

    // Constructor co tham so
    Student(string c, string n, string a,
            string m, int y)
        : People(c, n, a) {
        mssv = m;
        yearEntrance = y;
    }

    // Getters
    string getMssv() const {
        return mssv;
    }

    int getYearEntrance() const {
        return yearEntrance;
    }

    // Setters
    void setMssv(string m) {
        mssv = m;
    }

    void setYearEntrance(int y) {
        yearEntrance = y;
    }
};

// 3. Class FIEStudent ke thua Student
class FIEStudent : public Student {
private:
    int credits;

public:
    // Constructor mac dinh
    FIEStudent() : Student() {
        credits = 0;
    }

    // Constructor co tham so
    FIEStudent(string c, string n, string a,
               string m, int y, int cr)
        : Student(c, n, a, m, y) {
        credits = cr;
    }

    // Getter
    int getCredits() const {
        return credits;
    }

    // Setter
    void setCredits(int cr) {
        credits = cr;
    }

    // Hien thi thong tin
    void displayInfo() const {
        cout << "CCCD: " << getCccd() << endl;
        cout << "Name: " << getName() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "MSSV: " << getMssv() << endl;
        cout << "Year Entrance: "
             << getYearEntrance() << endl;
        cout << "Credits: " << credits << endl;
        cout << "--------------------------" << endl;
    }
};

// 4. Ham main
int main() {
    // Tao doi tuong People
    People p1;
    People p2(
        "079123456789",
        "Nguyen Van A",
        "Ho Chi Minh"
    );

    // Tao doi tuong Student
    Student s1;
    Student s2(
        "079123456789",
        "Tran Thi B",
        "Ha Noi",
        "SV001",
        2023
    );

    // Tao doi tuong FIEStudent
    FIEStudent f1;
    FIEStudent f2(
        "079987654321",
        "Le Minh C",
        "Da Nang",
        "FIE2023001",
        2023,
        120
    );

    // Hien thi f1
    cout << "=== Thong tin doi tuong f1 (mac dinh) ==="
         << endl;
    f1.displayInfo();

    // Hien thi f2
    cout << "\n=== Thong tin doi tuong f2 (co tham so) ==="
         << endl;
    f2.displayInfo();

    return 0;
}
