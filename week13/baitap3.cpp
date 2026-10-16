
#include <iostream>
#include <string>
using namespace std;

// =====================================
// 1. CLASS PEOPLE
// =====================================
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

    // Hien thi thong tin People
    void displayInfo() const {
        cout << "CCCD: " << cccd << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }
};

// =====================================
// 2. CLASS STUDENT KE THUA PEOPLE
// =====================================
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

    // Hien thi thong tin Student
    void displayInfo() const {
        cout << "CCCD: " << getCccd() << endl;
        cout << "Name: " << getName() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "MSSV: " << mssv << endl;
        cout << "Year Entrance: " << yearEntrance << endl;
    }
};

// =====================================
// 3. CLASS FIESTUDENT KE THUA STUDENT
// =====================================
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

    // Hien thi thong tin FIEStudent
    void displayInfo() const {
        cout << "CCCD: " << getCccd() << endl;
        cout << "Name: " << getName() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "MSSV: " << getMssv() << endl;
        cout << "Year Entrance: "
             << getYearEntrance() << endl;
        cout << "Credits: " << credits << endl;
    }
};

// =====================================
// 4. HAM MAIN
// =====================================
int main() {
    // 1. Tao doi tuong People
    People p1;

    People p2(
        "079123456789",
        "Nguyen Van A",
        "Ho Chi Minh"
    );

    // 2. Tao doi tuong Student
    Student s1;

    Student s2(
        "079123456789",
        "Tran Thi B",
        "Ha Noi",
        "SV001",
        2023
    );

    // 3. Tao doi tuong FIEStudent
    FIEStudent f1;

    FIEStudent f2(
        "079987654321",
        "Le Minh C",
        "Da Nang",
        "FIE2023001",
        2023,
        120
    );

    // 4. Hien thi People p1
    cout << "=== Thong tin p1 (People - mac dinh) ==="
         << endl;
    p1.displayInfo();
    cout << endl;

    // Hien thi People p2
    cout << "=== Thong tin p2 (People - co tham so) ==="
         << endl;
    p2.displayInfo();
    cout << endl;

    // Hien thi Student s1
    cout << "=== Thong tin s1 (Student - mac dinh) ==="
         << endl;
    s1.displayInfo();
    cout << endl;

    // Hien thi Student s2
    cout << "=== Thong tin s2 (Student - co tham so) ==="
         << endl;
    s2.displayInfo();
    cout << endl;

    // Hien thi FIEStudent f1
    cout << "=== Thong tin f1 (FIEStudent - mac dinh) ==="
         << endl;
    f1.displayInfo();
    cout << endl;

    // Hien thi FIEStudent f2
    cout << "=== Thong tin f2 (FIEStudent - co tham so) ==="
         << endl;
    f2.displayInfo();
    cout << endl;

    return 0;
}
