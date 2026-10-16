
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ==================== EMPLOYEE ====================
class Employee {
private:
    string id;
    string name;
    string cccd;
    string phone;
    string address;

public:
    Employee() {
        id = "";
        name = "";
        cccd = "";
        phone = "";
        address = "";
    }

    Employee(string id, string name) {
        this->id = id;
        this->name = name;
        cccd = "";
        phone = "";
        address = "";
    }

    // Bo sung constructor theo code giang vien
    Employee(string id, string name, string cccd,
             string phone, string address) {
        this->id = id;
        this->name = name;
        this->cccd = cccd;
        this->phone = phone;
        this->address = address;
    }

    string getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    string getCCCD() const {
        return cccd;
    }

    string getPhone() const {
        return phone;
    }

    string getAddress() const {
        return address;
    }

    void setId(string id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }

    void setCCCD(string cccd) {
        this->cccd = cccd;
    }

    void setPhone(string phone) {
        this->phone = phone;
    }

    void setAddress(string address) {
        this->address = address;
    }

    // Bo sung displayInfo theo code giang vien
    virtual void displayInfo() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "CCCD: " << cccd << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
    }

    virtual void display() const {
        displayInfo();
    }

    // Chuyen thanh ham thuan ao nhu code giang vien
    virtual double calculateSalary(int month, int year) const = 0;

    virtual ~Employee() {}
};

// ==================== HOURLY EMPLOYEE ====================
class HourlyEmployee : public Employee {
private:
    // Bo sung de luu nhieu ky luong trong mot nam
    struct SalaryRecord {
        double hours;
        int month;
        int year;
    };

    vector<SalaryRecord> records;
    double salaryPerHour;

public:
    HourlyEmployee() : Employee() {
        salaryPerHour = 0;
    }

    HourlyEmployee(string id, string name,
                   double hours, double salaryPerHour,
                   int month, int year)
        : Employee(id, name) {
        this->salaryPerHour = salaryPerHour;
        records.push_back({hours, month, year});
    }

    // Bo sung constructor co thong tin theo code giang vien
    HourlyEmployee(string id, string name,
                   string cccd, string phone, string address,
                   double hours, double salaryPerHour,
                   int month, int year)
        : Employee(id, name, cccd, phone, address) {
        this->salaryPerHour = salaryPerHour;
        records.push_back({hours, month, year});
    }

    double getHours() const {
        if (records.empty()) {
            return 0;
        }
        return records.back().hours;
    }

    double getSalaryPerHour() const {
        return salaryPerHour;
    }

    int getMonth() const {
        if (records.empty()) {
            return 0;
        }
        return records.back().month;
    }

    int getYear() const {
        if (records.empty()) {
            return 0;
        }
        return records.back().year;
    }

    void setHours(double hours) {
        if (!records.empty()) {
            records.back().hours = hours;
        }
    }

    void setSalaryPerHour(double salaryPerHour) {
        this->salaryPerHour = salaryPerHour;
    }

    void setMonth(int month) {
        if (!records.empty()) {
            records.back().month = month;
        }
    }

    void setYear(int year) {
        if (!records.empty()) {
            records.back().year = year;
        }
    }

    // Them ky luong moi theo vi du cua giang vien
    void addRecord(double hours, int month, int year) {
        records.push_back({hours, month, year});
    }

    double calculateSalary(int month, int year) const override {
        double salary = 0;

        for (const SalaryRecord& record : records) {
            if (record.month == month && record.year == year) {
                salary += record.hours * salaryPerHour;
            }
        }

        return salary;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Salary per hour: " << salaryPerHour << endl;

        cout << "Salary records:" << endl;
        for (const SalaryRecord& record : records) {
            cout << "Month: " << record.month
                 << ", Year: " << record.year
                 << ", Hours: " << record.hours << endl;
        }
    }

    void display() const override {
        displayInfo();
    }
};

// ==================== MONTHLY EMPLOYEE ====================
class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int month;
    int year;

public:
    MonthlyEmployee() : Employee() {
        monthlySalary = 0;
        month = 1;
        year = 2026;
    }

    MonthlyEmployee(string id, string name,
                    double monthlySalary, int month, int year)
        : Employee(id, name) {
        this->monthlySalary = monthlySalary;
        this->month = month;
        this->year = year;
    }

    // Bo sung constructor theo code giang vien
    MonthlyEmployee(string id, string name,
                    string cccd, string phone, string address,
                    double monthlySalary, int month, int year)
        : Employee(id, name, cccd, phone, address) {
        this->monthlySalary = monthlySalary;
        this->month = month;
        this->year = year;
    }

    double getMonthlySalary() const {
        return monthlySalary;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    void setMonthlySalary(double monthlySalary) {
        this->monthlySalary = monthlySalary;
    }

    void setMonth(int month) {
        this->month = month;
    }

    void setYear(int year) {
        this->year = year;
    }

    double calculateSalary(int month, int year) const override {
        if (this->month == month && this->year == year) {
            return monthlySalary;
        }
        return 0;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Monthly salary: " << monthlySalary << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
    }

    void display() const override {
        displayInfo();
    }
};

// ==================== DAILY EMPLOYEE ====================
class DailyEmployee : public Employee {
private:
    int numberOfDays;
    double salaryPerDay;
    int month;
    int year;

public:
    DailyEmployee() : Employee() {
        numberOfDays = 0;
        salaryPerDay = 0;
        month = 1;
        year = 2026;
    }

    DailyEmployee(string id, string name,
                  int numberOfDays, double salaryPerDay,
                  int month, int year)
        : Employee(id, name) {
        this->numberOfDays = numberOfDays;
        this->salaryPerDay = salaryPerDay;
        this->month = month;
        this->year = year;
    }

    // Bo sung constructor theo code giang vien
    DailyEmployee(string id, string name,
                  string cccd, string phone, string address,
                  int numberOfDays, double salaryPerDay,
                  int month, int year)
        : Employee(id, name, cccd, phone, address) {
        this->numberOfDays = numberOfDays;
        this->salaryPerDay = salaryPerDay;
        this->month = month;
        this->year = year;
    }

    int getNumberOfDays() const {
        return numberOfDays;
    }

    double getSalaryPerDay() const {
        return salaryPerDay;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    void setNumberOfDays(int numberOfDays) {
        this->numberOfDays = numberOfDays;
    }

    void setSalaryPerDay(double salaryPerDay) {
        this->salaryPerDay = salaryPerDay;
    }

    void setMonth(int month) {
        this->month = month;
    }

    void setYear(int year) {
        this->year = year;
    }

    double calculateSalary(int month, int year) const override {
        if (this->month == month && this->year == year) {
            return numberOfDays * salaryPerDay;
        }
        return 0;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Number of days: " << numberOfDays << endl;
        cout << "Salary per day: " << salaryPerDay << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
    }

    void display() const override {
        displayInfo();
    }
};

// ==================== TINH LUONG CA NAM ====================
// Bo sung ham giang vien chua hoan thanh
double calculateYearlySalary(Employee* employees[], int count, int year) {
    double totalSalary = 0;

    for (int i = 0; i < count; i++) {
        for (int month = 1; month <= 12; month++) {
            totalSalary += employees[i]->calculateSalary(month, year);
        }
    }

    return totalSalary;
}

// ==================== MAIN ====================
int main() {
    HourlyEmployee h(
        "E01", "Nguyen Van A",
        "001", "0901", "HCM",
        26, 50000, 1, 2026
    );

    // Them cac ky luong theo vi du cua giang vien
    h.addRecord(24, 2, 2026);
    h.addRecord(30, 12, 2026);

    MonthlyEmployee m(
        "E02", "Tran Thi B",
        "002", "0902", "Dong Nai",
        15000000, 10, 2026
    );

    DailyEmployee d(
        "E03", "Le Van C",
        "003", "0903", "Ha Noi",
        22, 400000, 10, 2026
    );

    // Con tro lop cha tro den cac doi tuong lop con
    Employee* employees[] = {&h, &m, &d};
    int count = sizeof(employees) / sizeof(employees[0]);

    int month, year;

    cout << "Enter month: ";
    cin >> month;

    cout << "Enter year: ";
    cin >> year;

    if (month < 1 || month > 12) {
        cout << "Invalid month!" << endl;
        return 1;
    }

    cout << fixed << setprecision(0);

    // Hien thi thong tin va luong theo thang da chon
    for (int i = 0; i < count; i++) {
        cout << "\n========== EMPLOYEE " << i + 1 << " ==========" << endl;
        employees[i]->display();

        cout << "Salary for " << month << "/" << year << ": "
             << employees[i]->calculateSalary(month, year)
             << " VND" << endl;
    }

    // Tinh luong ca nam cua tung nhan vien
    cout << "\n========== YEARLY SALARY ==========" << endl;

    for (int i = 0; i < count; i++) {
        Employee* oneEmployee[] = {employees[i]};

        cout << employees[i]->getId() << " - "
             << employees[i]->getName() << ": "
             << calculateYearlySalary(oneEmployee, 1, year)
             << " VND" << endl;
    }

    // Tong luong ca nam cua tat ca nhan vien
    cout << "\nTotal yearly salary: "
         << calculateYearlySalary(employees, count, year)
         << " VND" << endl;

    return 0;
}
