
#include <iostream>
#include <string>
using namespace std;

// ==================== EMPLOYEE ====================
class Employee {
private:
    string id;
    string name;

public:
    Employee() {
        id = "";
        name = "";
    }

    Employee(string id, string name) {
        this->id = id;
        this->name = name;
    }

    string getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    void setId(string id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }

    virtual void display() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }

    virtual double calculateSalary(int month, int year) const {
        return 0;
    }

    virtual ~Employee() {}
};

// ==================== HOURLY EMPLOYEE ====================
class HourlyEmployee : public Employee {
private:
    double hours;
    double salaryPerHour;
    int month;
    int year;

public:
    HourlyEmployee() : Employee() {
        hours = 0;
        salaryPerHour = 0;
        month = 1;
        year = 2026;
    }

    HourlyEmployee(string id, string name,
                   double hours, double salaryPerHour,
                   int month, int year)
        : Employee(id, name) {
        this->hours = hours;
        this->salaryPerHour = salaryPerHour;
        this->month = month;
        this->year = year;
    }

    double getHours() const {
        return hours;
    }

    double getSalaryPerHour() const {
        return salaryPerHour;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    void setHours(double hours) {
        this->hours = hours;
    }

    void setSalaryPerHour(double salaryPerHour) {
        this->salaryPerHour = salaryPerHour;
    }

    void setMonth(int month) {
        this->month = month;
    }

    void setYear(int year) {
        this->year = year;
    }

    double calculateSalary(int month, int year) const override {
        if (this->month == month && this->year == year) {
            return hours * salaryPerHour;
        }
        return 0;
    }

    void display() const override {
        Employee::display();
        cout << "Hours: " << hours << endl;
        cout << "Salary per hour: " << salaryPerHour << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
        cout << "Salary: " << calculateSalary(month, year) << endl;
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

    void display() const override {
        Employee::display();
        cout << "Monthly salary: " << monthlySalary << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
        cout << "Salary: " << calculateSalary(month, year) << endl;
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

    void display() const override {
        Employee::display();
        cout << "Number of days: " << numberOfDays << endl;
        cout << "Salary per day: " << salaryPerDay << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
        cout << "Salary: " << calculateSalary(month, year) << endl;
    }
};

// ==================== MAIN ====================
int main() {
    HourlyEmployee e1(
        "E01", "Nguyen Van A",
        160, 50000, 10, 2026
    );

    MonthlyEmployee e2(
        "E02", "Tran Thi B",
        15000000, 10, 2026
    );

    DailyEmployee e3(
        "E03", "Le Van C",
        24, 300000, 10, 2026
    );

    int month, year;

    cout << "Enter month: ";
    cin >> month;

    cout << "Enter year: ";
    cin >> year;

    cout << "\n===== HOURLY EMPLOYEE =====" << endl;
    e1.display();
    cout << "Salary for selected period: "
         << e1.calculateSalary(month, year) << endl;

    cout << "\n===== MONTHLY EMPLOYEE =====" << endl;
    e2.display();
    cout << "Salary for selected period: "
         << e2.calculateSalary(month, year) << endl;

    cout << "\n===== DAILY EMPLOYEE =====" << endl;
    e3.display();
    cout << "Salary for selected period: "
         << e3.calculateSalary(month, year) << endl;

    return 0;
}
