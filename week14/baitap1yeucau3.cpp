
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ==================== CLASS CHA ====================
class SellableItem {
private:
    string name;
    int quantity;
    double price;
    string date;

public:
    SellableItem() {
        name = "";
        quantity = 0;
        price = 0;
        date = "";
    }

    SellableItem(string n, int q, double p, string d) {
        name = n;
        quantity = q;
        price = p;
        date = d;
    }

    string getName() {
        return name;
    }

    int getQuantity() {
        return quantity;
    }

    double getPrice() {
        return price;
    }

    string getDate() {
        return date;
    }

    virtual string getCategory() = 0;

    double calculateRevenue() {
        return quantity * price;
    }

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: " << price << endl;
        cout << "Date: " << date << endl;
    }

    virtual ~SellableItem() {}
};

// ==================== DRINKS ====================
class Drinks : public SellableItem {
public:
    Drinks(string n, int q, double p, string d)
        : SellableItem(n, q, p, d) {
    }

    string getCategory() override {
        return "Drinks";
    }
};

class Coffee : public Drinks {
public:
    Coffee(int q, double p, string d)
        : Drinks("Coffee", q, p, d) {
    }
};

class Tea : public Drinks {
public:
    Tea(int q, double p, string d)
        : Drinks("Tea", q, p, d) {
    }
};

class Smoothies : public Drinks {
public:
    Smoothies(int q, double p, string d)
        : Drinks("Smoothies", q, p, d) {
    }
};

class Juices : public Drinks {
public:
    Juices(int q, double p, string d)
        : Drinks("Juices", q, p, d) {
    }
};

// ==================== FOODS ====================
class Foods : public SellableItem {
public:
    Foods(string n, int q, double p, string d)
        : SellableItem(n, q, p, d) {
    }

    string getCategory() override {
        return "Foods";
    }
};

class Cake : public Foods {
public:
    Cake(int q, double p, string d)
        : Foods("Cake", q, p, d) {
    }
};

class Bread : public Foods {
public:
    Bread(int q, double p, string d)
        : Foods("Bread", q, p, d) {
    }
};

// ==================== REVENUE REPORT ====================
void calculateDailyRevenue(
    vector<SellableItem*>& items,
    string chosenDate
) {
    double drinksRevenue = 0;
    double foodsRevenue = 0;

    cout << "\n===== DAILY REVENUE REPORT =====" << endl;
    cout << "Date: " << chosenDate << endl;

    for (SellableItem* item : items) {
        if (item->getDate() == chosenDate) {
            item->displayInfo();

            double revenue = item->calculateRevenue();

            cout << "Category: " << item->getCategory() << endl;
            cout << "Revenue: " << revenue << " VND" << endl;
            cout << "------------------------" << endl;

            if (item->getCategory() == "Drinks") {
                drinksRevenue += revenue;
            }
            else if (item->getCategory() == "Foods") {
                foodsRevenue += revenue;
            }
        }
    }

    cout << fixed << setprecision(0);
    cout << "\nDrinks: " << drinksRevenue << " VND" << endl;
    cout << "Foods: " << foodsRevenue << " VND" << endl;
    cout << "Total revenue: "
         << drinksRevenue + foodsRevenue << " VND" << endl;
}

// ==================== MAIN ====================
int main() {
    vector<SellableItem*> items;

    // Drinks
    items.push_back(new Coffee(10, 30000, "16/10/2026"));
    items.push_back(new Tea(8, 25000, "16/10/2026"));
    items.push_back(new Smoothies(5, 40000, "16/10/2026"));
    items.push_back(new Juices(6, 20000, "16/10/2026"));

    // Foods
    items.push_back(new Cake(4, 35000, "16/10/2026"));
    items.push_back(new Bread(12, 15000, "16/10/2026"));

    // Sales on another day
    items.push_back(new Coffee(3, 30000, "15/10/2026"));

    calculateDailyRevenue(items, "16/10/2026");

    for (SellableItem* item : items) {
        delete item;
    }

    return 0;
}
