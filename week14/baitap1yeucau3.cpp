
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ==================== PRODUCT MANAGEMENT ====================
class SellableItem {
private:
    string productName;
    int quantitySold;
    double price;
    string dateSold;

public:
    SellableItem(string name, int quantity, double unitPrice, string date)
        : productName(name), quantitySold(quantity),
          price(unitPrice), dateSold(date) {}

    string getProductName() const { return productName; }
    int getQuantitySold() const { return quantitySold; }
    double getPrice() const { return price; }
    string getDateSold() const { return dateSold; }

    double revenue() const {
        return quantitySold * price;
    }

    virtual string category() const = 0;

    void showSale() const {
        cout << left << setw(16) << productName
             << "Quantity: " << setw(4) << quantitySold
             << "Revenue: " << revenue() << " VND\n";
    }

    virtual ~SellableItem() = default;
};

class Drinks : public SellableItem {
public:
    Drinks(string name, int quantity, double price, string date)
        : SellableItem(name, quantity, price, date) {}

    string category() const override {
        return "Drinks";
    }
};

class Coffee : public Drinks {
public:
    Coffee(int quantity, double price, string date)
        : Drinks("Coffee", quantity, price, date) {}
};

class Tea : public Drinks {
public:
    Tea(int quantity, double price, string date)
        : Drinks("Tea", quantity, price, date) {}
};

class Smoothies : public Drinks {
public:
    Smoothies(int quantity, double price, string date)
        : Drinks("Smoothies", quantity, price, date) {}
};

class Juices : public Drinks {
public:
    Juices(int quantity, double price, string date)
        : Drinks("Juices", quantity, price, date) {}
};

class Foods : public SellableItem {
public:
    Foods(string name, int quantity, double price, string date)
        : SellableItem(name, quantity, price, date) {}

    string category() const override {
        return "Foods";
    }
};

class Cake : public Foods {
public:
    Cake(int quantity, double price, string date)
        : Foods("Cake", quantity, price, date) {}
};

class Bread : public Foods {
public:
    Bread(int quantity, double price, string date)
        : Foods("Bread", quantity, price, date) {}
};

// ==================== REVENUE CALCULATION ====================
void reportRevenue(const vector<SellableItem*>& sales, string chosenDate) {
    double drinkIncome = 0;
    double foodIncome = 0;

    cout << "\n========== SALES REPORT ==========\n";
    cout << "Date: " << chosenDate << "\n\n";

    for (const SellableItem* sale : sales) {
        if (sale->getDateSold() != chosenDate) {
            continue;
        }

        sale->showSale();

        if (sale->category() == "Drinks") {
            drinkIncome += sale->revenue();
        } else if (sale->category() == "Foods") {
            foodIncome += sale->revenue();
        }
    }

    cout << "\nDrinks revenue: " << drinkIncome << " VND\n";
    cout << "Foods revenue: " << foodIncome << " VND\n";
    cout << "Combined revenue: "
         << drinkIncome + foodIncome << " VND\n";
}

// ==================== STAFF MANAGEMENT ====================
class Staff {
private:
    string identityNumber;
    string contactNumber;
    string residence;

public:
    Staff() : identityNumber(""), contactNumber(""), residence("") {}

    Staff(string id, string phone, string address)
        : identityNumber(id), contactNumber(phone), residence(address) {}

    string getIdentityNumber() const { return identityNumber; }
    string getContactNumber() const { return contactNumber; }
    string getResidence() const { return residence; }

    void setIdentityNumber(string id) { identityNumber = id; }
    void setContactNumber(string phone) { contactNumber = phone; }
    void setResidence(string address) { residence = address; }

    virtual double salaryFor(int month, int year) = 0;

    virtual void showStaff() const {
        cout << "Identity number: " << identityNumber << '\n';
        cout << "Contact number: " << contactNumber << '\n';
        cout << "Residence: " << residence << '\n';
    }

    virtual ~Staff() = default;
};

class HourlyStaff : public Staff {
private:
    int hoursCompleted;
    double ratePerHour;
    int salaryMonth, salaryYear;

public:
    HourlyStaff()
        : Staff(), hoursCompleted(0), ratePerHour(0),
          salaryMonth(0), salaryYear(0) {}

    HourlyStaff(string id, string phone, string address,
                int hours, double rate, int month, int year)
        : Staff(id, phone, address), hoursCompleted(hours),
          ratePerHour(rate), salaryMonth(month), salaryYear(year) {}

    int getHoursCompleted() const { return hoursCompleted; }
    double getRatePerHour() const { return ratePerHour; }
    int getSalaryMonth() const { return salaryMonth; }
    int getSalaryYear() const { return salaryYear; }

    void setHoursCompleted(int hours) { hoursCompleted = hours; }
    void setRatePerHour(double rate) { ratePerHour = rate; }
    void setSalaryMonth(int month) { salaryMonth = month; }
    void setSalaryYear(int year) { salaryYear = year; }

    double salaryFor(int month, int year) override {
        if (month == salaryMonth && year == salaryYear)
            return hoursCompleted * ratePerHour;
        return 0;
    }

    void showStaff() const override {
        cout << "\n--- HOURLY STAFF ---\n";
        Staff::showStaff();
        cout << "Hours completed: " << hoursCompleted << '\n';
        cout << "Rate per hour: " << ratePerHour << '\n';
        cout << "Salary period: " << salaryMonth << '/'
             << salaryYear << '\n';
    }
};

class MonthlyStaff : public Staff {
private:
    double fixedPay;
    int salaryMonth, salaryYear;

public:
    MonthlyStaff()
        : Staff(), fixedPay(0), salaryMonth(0), salaryYear(0) {}

    MonthlyStaff(string id, string phone, string address,
                 double pay, int month, int year)
        : Staff(id, phone, address), fixedPay(pay),
          salaryMonth(month), salaryYear(year) {}

    double getFixedPay() const { return fixedPay; }
    int getSalaryMonth() const { return salaryMonth; }
    int getSalaryYear() const { return salaryYear; }

    void setFixedPay(double pay) { fixedPay = pay; }
    void setSalaryMonth(int month) { salaryMonth = month; }
    void setSalaryYear(int year) { salaryYear = year; }

    double salaryFor(int month, int year) override {
        if (month == salaryMonth && year == salaryYear)
            return fixedPay;
        return 0;
    }

    void showStaff() const override {
        cout << "\n--- MONTHLY STAFF ---\n";
        Staff::showStaff();
        cout << "Fixed pay: " << fixedPay << '\n';
        cout << "Salary period: " << salaryMonth << '/'
             << salaryYear << '\n';
    }
};

class DailyStaff : public Staff {
private:
    int daysCompleted;
    double ratePerDay;
    int salaryMonth, salaryYear;

public:
    DailyStaff()
        : Staff(), daysCompleted(0), ratePerDay(0),
          salaryMonth(0), salaryYear(0) {}

    DailyStaff(string id, string phone, string address,
               int days, double rate, int month, int year)
        : Staff(id, phone, address), daysCompleted(days),
          ratePerDay(rate), salaryMonth(month), salaryYear(year) {}

    int getDaysCompleted() const { return daysCompleted; }
    double getRatePerDay() const { return ratePerDay; }
    int getSalaryMonth() const { return salaryMonth; }
    int getSalaryYear() const { return salaryYear; }

    void setDaysCompleted(int days) { daysCompleted = days; }
    void setRatePerDay(double rate) { ratePerDay = rate; }
    void setSalaryMonth(int month) { salaryMonth = month; }
    void setSalaryYear(int year) { salaryYear = year; }

    double salaryFor(int month, int year) override {
        if (month == salaryMonth && year == salaryYear)
            return daysCompleted * ratePerDay;
        return 0;
    }

    void showStaff() const override {
        cout << "\n--- DAILY STAFF ---\n";
        Staff::showStaff();
        cout << "Days completed: " << daysCompleted << '\n';
        cout << "Rate per day: " << ratePerDay << '\n';
        cout << "Salary period: " << salaryMonth << '/'
             << salaryYear << '\n';
    }
};

// ==================== PAYROLL REPORTS ====================
void reportMonthlyPayroll(
    Staff* staffMembers[], int memberCount, int month, int year
) {
    double monthTotal = 0;

    cout << "\n========== MONTHLY PAYROLL ==========\n";

    for (int i = 0; i < memberCount; i++) {
        double amount = staffMembers[i]->salaryFor(month, year);
        cout << "Staff " << i + 1 << ": " << amount << " VND\n";
        monthTotal += amount;
    }

    cout << "Total for month: " << monthTotal << " VND\n";
}

double reportYearlyPayroll(
    Staff* staffMembers[], int memberCount, int year
) {
    double yearTotal = 0;

    for (int i = 0; i < memberCount; i++) {
        for (int month = 1; month <= 12; month++) {
            yearTotal += staffMembers[i]->salaryFor(month, year);
        }
    }

    return yearTotal;
}

// ==================== EMPLOYEE SYSTEM (SECOND CODE) ====================
class Employee {
private:
    string id;
    string name;
public:
    Employee() : id(""), name("") {}
    Employee(string id, string name) : id(id), name(name) {}
    string getId() const { return id; }
    string getName() const { return name; }
    void setId(string id) { this->id = id; }
    void setName(string name) { this->name = name; }
    virtual void display() const {
        cout << "ID: " << id << '\n' << "Name: " << name << '\n';
    }
    virtual double calculateSalary(int month, int year) const { return 0; }
    virtual ~Employee() {}
};

class HourlyEmployee : public Employee {
private:
    double hours, salaryPerHour;
    int month, year;
public:
    HourlyEmployee() : Employee(), hours(0), salaryPerHour(0), month(1), year(2026) {}
    HourlyEmployee(string id, string name, double hours, double salaryPerHour, int month, int year)
        : Employee(id, name), hours(hours), salaryPerHour(salaryPerHour), month(month), year(year) {}
    double getHours() const { return hours; }
    double getSalaryPerHour() const { return salaryPerHour; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    void setHours(double hours) { this->hours = hours; }
    void setSalaryPerHour(double salaryPerHour) { this->salaryPerHour = salaryPerHour; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }
    double calculateSalary(int month, int year) const override {
        return (this->month == month && this->year == year) ? hours * salaryPerHour : 0;
    }
    void display() const override {
        Employee::display();
        cout << "Hours: " << hours << '\n'
             << "Salary per hour: " << salaryPerHour << '\n'
             << "Month: " << month << '\n'
             << "Year: " << year << '\n'
             << "Salary: " << calculateSalary(month, year) << " VND\n";
    }
};

class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int month, year;
public:
    MonthlyEmployee() : Employee(), monthlySalary(0), month(1), year(2026) {}
    MonthlyEmployee(string id, string name, double monthlySalary, int month, int year)
        : Employee(id, name), monthlySalary(monthlySalary), month(month), year(year) {}
    double getMonthlySalary() const { return monthlySalary; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    void setMonthlySalary(double salary) { monthlySalary = salary; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }
    double calculateSalary(int month, int year) const override {
        return (this->month == month && this->year == year) ? monthlySalary : 0;
    }
    void display() const override {
        Employee::display();
        cout << "Monthly salary: " << monthlySalary << '\n'
             << "Month: " << month << '\n' << "Year: " << year << '\n'
             << "Salary: " << calculateSalary(month, year) << " VND\n";
    }
};

class DailyEmployee : public Employee {
private:
    int numberOfDays;
    double salaryPerDay;
    int month, year;
public:
    DailyEmployee() : Employee(), numberOfDays(0), salaryPerDay(0), month(1), year(2026) {}
    DailyEmployee(string id, string name, int numberOfDays, double salaryPerDay, int month, int year)
        : Employee(id, name), numberOfDays(numberOfDays), salaryPerDay(salaryPerDay), month(month), year(year) {}
    int getNumberOfDays() const { return numberOfDays; }
    double getSalaryPerDay() const { return salaryPerDay; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    void setNumberOfDays(int days) { numberOfDays = days; }
    void setSalaryPerDay(double salary) { salaryPerDay = salary; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }
    double calculateSalary(int month, int year) const override {
        return (this->month == month && this->year == year) ? numberOfDays * salaryPerDay : 0;
    }
    void display() const override {
        Employee::display();
        cout << "Number of days: " << numberOfDays << '\n'
             << "Salary per day: " << salaryPerDay << '\n'
             << "Month: " << month << '\n' << "Year: " << year << '\n'
             << "Salary: " << calculateSalary(month, year) << " VND\n";
    }
};

void reportEmployeePayroll(Employee* employees[], int count, int month, int year) {
    double total = 0;
    cout << "\\n========== EMPLOYEE PAYROLL ==========" << '\n';
    cout << "Period: " << month << '/' << year << '\n';
    for (int i = 0; i < count; ++i) {
        double salary = employees[i]->calculateSalary(month, year);
        cout << "\\nEmployee " << i + 1 << ":\n";
        employees[i]->display();
        cout << "Salary for selected period: " << salary << " VND\n";
        total += salary;
    }
    cout << "Total employee payroll: " << total << " VND\n";
}

// ==================== MAIN ====================
int main() {
    cout << fixed << setprecision(0);

    // Employee records from the second code
    HourlyEmployee employeeA("E01", "Nguyen Van A", 160, 50000, 10, 2026);
    MonthlyEmployee employeeB("E02", "Tran Thi B", 15000000, 10, 2026);
    DailyEmployee employeeC("E03", "Le Van C", 24, 300000, 10, 2026);
    Employee* employees[] = { &employeeA, &employeeB, &employeeC };
    int employeeCount = 3;
    reportEmployeePayroll(employees, employeeCount, 10, 2026);

    // Create staff records
    HourlyStaff staffA(
        "001", "0901", "HCM", 160, 50000, 10, 2026
    );

    MonthlyStaff staffB(
        "002", "0902", "Dong Nai", 15000000, 10, 2026
    );

    DailyStaff staffC(
        "003", "0903", "Ha Noi", 22, 400000, 10, 2026
    );

    Staff* staffMembers[] = {&staffA, &staffB, &staffC};
    int memberCount = 3;

    cout << "========== STAFF INFORMATION ==========\n";

    for (Staff* member : staffMembers) {
        member->showStaff();
    }

    reportMonthlyPayroll(staffMembers, memberCount, 10, 2026);

    cout << "\n========== YEARLY PAYROLL ==========\n";
    cout << "Yearly total for 2026: "
         << reportYearlyPayroll(staffMembers, memberCount, 2026)
         << " VND\n";

    // Record product sales
    vector<SellableItem*> sales;

    sales.push_back(new Coffee(10, 30000, "16/10/2026"));
    sales.push_back(new Tea(8, 25000, "16/10/2026"));
    sales.push_back(new Smoothies(5, 40000, "16/10/2026"));
    sales.push_back(new Juices(6, 20000, "16/10/2026"));
    sales.push_back(new Cake(4, 35000, "16/10/2026"));
    sales.push_back(new Bread(12, 15000, "16/10/2026"));
    sales.push_back(new Coffee(3, 30000, "15/10/2026"));

    reportRevenue(sales, "16/10/2026");

    for (SellableItem* sale : sales) {
        delete sale;
    }

    return 0;
}