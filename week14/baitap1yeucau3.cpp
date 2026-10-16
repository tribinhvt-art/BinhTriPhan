
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ==================== DRINKS ====================
class Drinks {
private:
    string date;
    int quantity;
    double price;

public:
    Drinks() {
        date = "";
        quantity = 0;
        price = 0;
    }

    Drinks(string d, int q, double p) {
        date = d;
        quantity = q;
        price = p;
    }

    string getDate() const {
        return date;
    }

    int getQuantity() const {
        return quantity;
    }

    double getPrice() const {
        return price;
    }

    virtual double calculateRevenue(string d) = 0;

    virtual void displayInfo() {
        cout << "Date: " << date << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: " << price << endl;
    }

    virtual ~Drinks() = default;
};

// ==================== COFFEE ====================
class Coffee : public Drinks {
public:
    Coffee() : Drinks() {}

    Coffee(string d, int q, double p)
        : Drinks(d, q, p) {}

    double calculateRevenue(string d) override {
        if (d == getDate())
            return getQuantity() * getPrice();

        return 0;
    }
};

// ==================== TEA ====================
class Tea : public Drinks {
public:
    Tea() : Drinks() {}

    Tea(string d, int q, double p)
        : Drinks(d, q, p) {}

    double calculateRevenue(string d) override {
        if (d == getDate())
            return getQuantity() * getPrice();

        return 0;
    }
};

// ==================== SMOOTHIES ====================
class Smoothies : public Drinks {
public:
    Smoothies() : Drinks() {}

    Smoothies(string d, int q, double p)
        : Drinks(d, q, p) {}

    double calculateRevenue(string d) override {
        if (d == getDate())
            return getQuantity() * getPrice();

        return 0;
    }
};

// ==================== JUICES ====================
class Juices : public Drinks {
public:
    Juices() : Drinks() {}

    Juices(string d, int q, double p)
        : Drinks(d, q, p) {}

    double calculateRevenue(string d) override {
        if (d == getDate())
            return getQuantity() * getPrice();

        return 0;
    }
};

// ==================== FOODS ====================
class Foods {
private:
    string date;
    int quantity;
    double price;

public:
    Foods() {
        date = "";
        quantity = 0;
        price = 0;
    }

    Foods(string d, int q, double p) {
        date = d;
        quantity = q;
        price = p;
    }

    string getDate() const {
        return date;
    }

    int getQuantity() const {
        return quantity;
    }

    double getPrice() const {
        return price;
    }

    virtual double calculateRevenue(string d) = 0;

    virtual void displayInfo() {
        cout << "Date: " << date << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: " << price << endl;
    }

    virtual ~Foods() = default;
};

// ==================== CAKE ====================
class Cake : public Foods {
public:
    Cake() : Foods() {}

    Cake(string d, int q, double p)
        : Foods(d, q, p) {}

    double calculateRevenue(string d) override {
        if (d == getDate())
            return getQuantity() * getPrice();

        return 0;
    }
};

// ==================== BREADS ====================
class Breads : public Foods {
public:
    Breads() : Foods() {}

    Breads(string d, int q, double p)
        : Foods(d, q, p) {}

    double calculateRevenue(string d) override {
        if (d == getDate())
            return getQuantity() * getPrice();

        return 0;
    }
};

// ==================== MAIN ====================
int main() {
    // Doanh thu đồ uống
    Coffee c1("16/10/2026", 20, 30000);
    Tea t1("16/10/2026", 15, 20000);
    Smoothies s1("16/10/2026", 10, 40000);
    Juices j1("16/10/2026", 12, 25000);

    Coffee c2("15/10/2026", 10, 30000);

    // Doanh thu đồ ăn
    Cake ca1("16/10/2026", 8, 35000);
    Breads b1("16/10/2026", 25, 15000);
    Cake ca2("15/10/2026", 5, 35000);

    // Con tro lop cha tro den doi tuong lop con
    Drinks* drinks[] = {&c1, &t1, &s1, &j1, &c2};
    Foods* foods[] = {&ca1, &b1, &ca2};

    string searchDate;

    cout << "Enter date (dd/mm/yyyy): ";
    cin >> searchDate;

    double totalDrinks = 0;
    double totalFoods = 0;

    for (Drinks* d : drinks) {
        totalDrinks += d->calculateRevenue(searchDate);
    }

    for (Foods* f : foods) {
        totalFoods += f->calculateRevenue(searchDate);
    }

    cout << fixed << setprecision(0);

    cout << "\n===== DAILY REVENUE =====" << endl;
    cout << "Date: " << searchDate << endl;
    cout << "Drinks: " << totalDrinks << " VND" << endl;
    cout << "Foods: " << totalFoods << " VND" << endl;
    cout << "Total: " << totalDrinks + totalFoods
         << " VND" << endl;

    return 0;
}
