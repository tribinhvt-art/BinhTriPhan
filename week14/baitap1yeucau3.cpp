
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ================= EMPLOYEE =================

class Employee {
private:
    string cccd;
    string phone;
    string address;

public:
    Employee() : cccd(""), phone(""), address("") {}

    Employee(string c, string p, string a)
        : cccd(c), phone(p), address(a) {}

    virtual double calculateSalary(int month, int year) = 0;

    virtual void displayInfo() {
        cout << "CCCD: " << cccd << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
    }

    virtual ~Employee() = default;
};

class HourlyEmployee : public Employee {
private:
    int hours;
    double salaryPerHour;
    int month, year;

public:
    HourlyEmployee(string c, string p, string a,
                   int h, double s, int m, int y)
        : Employee(c, p, a),
          hours(h), salaryPerHour(s), month(m), year(y) {}

    double calculateSalary(int m, int y) override {
        if (m == month && y == year)
            return hours * salaryPerHour;
        return 0;
    }
};

class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int month, year;

public:
    MonthlyEmployee(string c, string p, string a,
                    double s, int m, int y)
        : Employee(c, p, a),
          monthlySalary(s), month(m), year(y) {}

    double calculateSalary(int m, int y) override {
        if (m == month && y == year)
            return monthlySalary;
        return 0;
    }
};

class DailyEmployee : public Employee {
private:
    int numberOfDays;
    double salaryPerDay;
    int month, year;

public:
    DailyEmployee(string c, string p, string a,
                  int d, double s, int m, int y)
        : Employee(c, p, a),
          numberOfDays(d), salaryPerDay(s), month(m), year(y) {}

    double calculateSalary(int m, int y) override {
        if (m == month && y == year)
            return numberOfDays * salaryPerDay;
        return 0;
    }
};

// Tinh tong luong nam
double calculateYearlySalary(Employee* employees[],
                             int n, int year) {
    double total = 0;

    for (int i = 0; i < n; i++) {
        for (int month = 1; month <= 12; month++) {
            total += employees[i]->calculateSalary(month, year);
        }
    }

    return total;
}

// ================= PRODUCT =================

class Product {
private:
    string name;
    int quantity;
    double price;
    string date;  // dd/mm/yyyy

public:
    Product(string n, int q, double p, string d)
        : name(n), quantity(q), price(p), date(d) {}

    string getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    double getPrice() const {
        return price;
    }

    string getDate() const {
        return date;
    }

    double getRevenue() const {
        return quantity * price;
    }

    virtual string getCategory() const = 0;

    virtual ~Product() = default;
};

// ================= DRINKS =================

class Drinks : public Product {
public:
    Drinks(string n, int q, double p, string d)
        : Product(n, q, p, d) {}

    string getCategory() const override {
        return "Drinks";
    }
};

class Coffee : public Drinks {
public:
    Coffee(int q, double p, string d)
        : Drinks("Coffee", q, p, d) {}
};

class Tea : public Drinks {
public:
    Tea(int q, double p, string d)
        : Drinks("Tea", q, p, d) {}
};

class Smoothies : public Drinks {
public:
    Smoothies(int q, double p, string d)
        : Drinks("Smoothies", q, p, d) {}
};

class Juices : public Drinks {
public:
    Juices(int q, double p, string d)
        : Drinks("Juices", q, p, d) {}
};

// ================= FOODS =================

class Foods : public Product {
public:
    Foods(string n, int q, double p, string d)
        : Product(n, q, p, d) {}

    string getCategory() const override {
        return "Foods";
    }
};

class Cake : public Foods {
public:
    Cake(int q, double p, string d)
        : Foods("Cake", q, p, d) {}
};

class Breads : public Foods {
public:
    Breads(int q, double p, string d)
        : Foods("Breads", q, p, d) {}
};

// ================= DAILY REVENUE =================

void calculateDailyRevenue(vector<Product*>& products,
                           string targetDate) {
    double drinksRevenue = 0;
    double foodsRevenue = 0;

    cout << "\nRevenue report: " << targetDate << endl;

    for (Product* p : products) {
        if (p->getDate() == targetDate) {
            cout << p->getName()
                 << " | Quantity: " << p->getQuantity()
                 << " | Revenue: " << fixed << setprecision(0)
                 << p->getRevenue() << " VND" << endl;

            if (p->getCategory() == "Drinks") {
                drinksRevenue += p->getRevenue();
            }
            else if (p->getCategory() == "Foods") {
                foodsRevenue += p->getRevenue();
            }
        }
    }

    cout << "\nDrinks: " << drinksRevenue << " VND" << endl;
    cout << "Foods: " << foodsRevenue << " VND" << endl;
    cout << "Total revenue: "
         << drinksRevenue + foodsRevenue << " VND" << endl;
}

// ================= MAIN =================

int main() {
    // Employee examples
    HourlyEmployee h(
        "001", "0901", "HCM",
        160, 50000, 10, 2026
    );

    MonthlyEmployee m(
        "002", "0902", "Dong Nai",
        15000000, 10, 2026
    );

    DailyEmployee d(
        "003", "0903", "Ha Noi",
        22, 400000, 10, 2026
    );

    Employee* employees[] = {&h, &m, &d};
    int employeeCount = 3;

    cout << "===== EMPLOYEE SALARIES =====" << endl;

    for (Employee* e : employees) {
        cout << e->calculateSalary(10, 2026) << " VND" << endl;
    }

    cout << "Yearly salary total: "
         << calculateYearlySalary(employees, employeeCount, 2026)
         << " VND" << endl;

    // Product sales examples
    vector<Product*> products;

    products.push_back(new Coffee(10, 30000, "16/10/2026"));
    products.push_back(new Tea(8, 25000, "16/10/2026"));
    products.push_back(new Smoothies(5, 40000, "16/10/2026"));
    products.push_back(new Juices(6, 20000, "16/10/2026"));

    products.push_back(new Cake(4, 35000, "16/10/2026"));
    products.push_back(new Breads(12, 15000, "16/10/2026"));

    products.push_back(new Coffee(3, 30000, "15/10/2026"));

    cout << "\n===== DAILY REVENUE =====" << endl;

    calculateDailyRevenue(products, "16/10/2026");

    // Free allocated memory
    for (Product* p : products) {
        delete p;
    }

    return 0;
}
