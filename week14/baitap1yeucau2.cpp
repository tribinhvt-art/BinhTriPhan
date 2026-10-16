
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

public:
    Employee() : id(""), name("") {}

    Employee(string id, string name)
        : id(id), name(name) {}

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

    virtual ~Employee() = default;
};

// ==================== HOURLY EMPLOYEE ====================

class HourlyEmployee : public Employee {
private:
    double hours;
    double salaryPerHour;
    int month;
    int year;

public:
    HourlyEmployee()
        : Employee(), hours(0), salaryPerHour(0),
          month(1), year(2026) {}

    HourlyEmployee(string id, string name, double hours,
                   double salaryPerHour, int month, int year)
        : Employee(id, name), hours(hours),
          salaryPerHour(salaryPerHour),
          month(month), year(year) {}

    double getHours() const { return hours; }
    double getSalaryPerHour() const { return salaryPerHour; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setHours(double hours) { this->hours = hours; }
    void setSalaryPerHour(double salary) {
        salaryPerHour = salary;
    }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }

    double calculateSalary(int m, int y) const override {
        if (m == month && y == year)
            return hours * salaryPerHour;
        return 0;
    }

    void display() const override {
        cout << "\n[Hourly Employee]\n";
        Employee::display();
        cout << "Hours: " << hours << endl;
        cout << "Salary per hour: " << salaryPerHour << endl;
        cout << "Month/Year: " << month << "/" << year << endl;
    }
};

// ==================== MONTHLY EMPLOYEE ====================

class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int month;
    int year;

public:
    MonthlyEmployee()
        : Employee(), monthlySalary(0), month(1), year(2026) {}

    MonthlyEmployee(string id, string name, double salary,
                    int month, int year)
        : Employee(id, name), monthlySalary(salary),
          month(month), year(year) {}

    double getMonthlySalary() const { return monthlySalary; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setMonthlySalary(double salary) {
        monthlySalary = salary;
    }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }

    double calculateSalary(int m, int y) const override {
        if (m == month && y == year)
            return monthlySalary;
        return 0;
    }

    void display() const override {
        cout << "\n[Monthly Employee]\n";
        Employee::display();
        cout << "Monthly salary: " << monthlySalary << endl;
        cout << "Month/Year: " << month << "/" << year << endl;
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
    DailyEmployee()
        : Employee(), numberOfDays(0), salaryPerDay(0),
          month(1), year(2026) {}

    DailyEmployee(string id, string name, int days,
                  double salaryPerDay, int month, int year)
        : Employee(id, name), numberOfDays(days),
          salaryPerDay(salaryPerDay),
          month(month), year(year) {}

    int getNumberOfDays() const { return numberOfDays; }
    double getSalaryPerDay() const { return salaryPerDay; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setNumberOfDays(int days) {
        numberOfDays = days;
    }
    void setSalaryPerDay(double salary) {
        salaryPerDay = salary;
    }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }

    double calculateSalary(int m, int y) const override {
        if (m == month && y == year)
            return numberOfDays * salaryPerDay;
        return 0;
    }

    void display() const override {
        cout << "\n[Daily Employee]\n";
        Employee::display();
        cout << "Working days: " << numberOfDays << endl;
        cout << "Salary per day: " << salaryPerDay << endl;
        cout << "Month/Year: " << month << "/" << year << endl;
    }
};

// ==================== SALARY REPORT ====================

double calculateYearlySalary(Employee* employees[],
                             int count, int year) {
    double total = 0;

    for (int i = 0; i < count; i++) {
        for (int month = 1; month <= 12; month++) {
            total += employees[i]->calculateSalary(month, year);
        }
    }

    return total;
}

void displayMonthlySalary(Employee* employees[],
                          int count, int month, int year) {
    double total = 0;

    cout << "\n===== MONTHLY SALARY REPORT =====\n";

    for (int i = 0; i < count; i++) {
        double salary = employees[i]->calculateSalary(month, year);

        cout << employees[i]->getName()
             << ": " << salary << " VND\n";

        total += salary;
    }

    cout << "Total monthly salary: " << total << " VND\n";
}

// ==================== PRODUCT BASE CLASS ====================

class Product {
private:
    string name;
    int quantity;
    double unitPrice;
    string saleDate;

public:
    Product(string name, int quantity,
            double price, string date)
        : name(name), quantity(quantity),
          unitPrice(price), saleDate(date) {}

    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getUnitPrice() const { return unitPrice; }
    string getSaleDate() const { return saleDate; }

    double calculateRevenue() const {
        return quantity * unitPrice;
    }

    virtual string getCategory() const = 0;

    virtual void displaySale() const {
        cout << left << setw(14) << name
             << "Quantity: " << setw(4) << quantity
             << "Revenue: " << calculateRevenue()
             << " VND\n";
    }

    virtual ~Product() = default;
};

// ==================== DRINKS ====================

class Drinks : public Product {
public:
    Drinks(string name, int quantity,
           double price, string date)
        : Product(name, quantity, price, date) {}

    string getCategory() const override {
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

// ==================== FOODS ====================

class Foods : public Product {
public:
    Foods(string name, int quantity,
          double price, string date)
        : Product(name, quantity, price, date) {}

    string getCategory() const override {
        return "Foods";
    }
};

class Cake : public Foods {
public:
    Cake(int quantity, double price, string date)
        : Foods("Cake", quantity, price, date) {}
};

class Breads : public Foods {
public:
    Breads(int quantity, double price, string date)
        : Foods("Breads", quantity, price, date) {}
};

// ==================== DAILY REVENUE REPORT ====================

void calculateDailyRevenue(vector<Product*>& products,
                           const string& date) {
    double drinksTotal = 0;
    double foodsTotal = 0;

    cout << "\n===== DAILY REVENUE REPORT =====\n";
    cout << "Date: " << date << "\n\n";

    for (Product* product : products) {
        if (product->getSaleDate() != date)
            continue;

        product->displaySale();

        if (product->getCategory() == "Drinks") {
            drinksTotal += product->calculateRevenue();
        } else if (product->getCategory() == "Foods") {
            foodsTotal += product->calculateRevenue();
        }
    }

    cout << "\nDrinks: " << drinksTotal << " VND\n";
    cout << "Foods: " << foodsTotal << " VND\n";
    cout << "Total revenue: "
         << drinksTotal + foodsTotal << " VND\n";
}

// ==================== MAIN ====================

int main() {
    cout << fixed << setprecision(0);

    // Employee data
    HourlyEmployee e1(
        "E01", "Nguyen Van A", 160, 50000, 10, 2026
    );

    MonthlyEmployee e2(
        "E02", "Tran Thi B", 15000000, 10, 2026
    );

    DailyEmployee e3(
        "E03", "Le Van C", 24, 300000, 10, 2026
    );

    Employee* employees[] = {&e1, &e2, &e3};
    int employeeCount = 3;

    cout << "========== EMPLOYEE INFORMATION ==========\n";

    for (Employee* employee : employees) {
        employee->display();
    }

    displayMonthlySalary(employees, employeeCount, 10, 2026);

    cout << "\n===== YEARLY SALARY REPORT =====\n";
    cout << "Total salary in 2026: "
         << calculateYearlySalary(employees, employeeCount, 2026)
         << " VND\n";

    // Sales data
    vector<Product*> products;

    products.push_back(new Coffee(10, 30000, "16/10/2026"));
    products.push_back(new Tea(8, 25000, "16/10/2026"));
    products.push_back(new Smoothies(5, 40000, "16/10/2026"));
    products.push_back(new Juices(6, 20000, "16/10/2026"));

    products.push_back(new Cake(4, 35000, "16/10/2026"));
    products.push_back(new Breads(12, 15000, "16/10/2026"));

    // A sale from another day, excluded from today's report
    products.push_back(new Coffee(3, 30000, "15/10/2026"));

    calculateDailyRevenue(products, "16/10/2026");

    // Release dynamically allocated products
    for (Product* product : products) {
        delete product;
    }

    return 0;
}
