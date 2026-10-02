#include <iostream>
#include <string>
using namespace std;

class Food {
private:
    // Data hiding
    string name;
    double price;
    int quantity;

public:
    // Constructor
    Food(string n, double p, int q) {
        name = n;

        if (p > 0)
            price = p;
        else
            price = 0;

        if (q >= 0)
            quantity = q;
        else
            quantity = 0;
    }

    // Getter
    string getName() {
        return name;
    }

    double getPrice() {
        return price;
    }

    int getQuantity() {
        return quantity;
    }

    // Setter
    void setName(string n) {
        name = n;
    }

    void setPrice(double p) {
        if (p > 0)
            price = p;
        else
            cout << "Price must be greater than 0!\n";
    }

    void setQuantity(int q) {
        if (q >= 0)
            quantity = q;
        else
            cout << "Quantity cannot be negative!\n";
    }

    // Display
    void display() {
        cout << "Food name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

int main() {
    // Create object
    Food f("Burger", 50000, 10);

    // Display initial information
    cout << "=== Initial Food ===" << endl;
    f.display();

    // Getters
    cout << "\n=== Using Getters ===" << endl;
    cout << "Name: " << f.getName() << endl;
    cout << "Price: " << f.getPrice() << endl;
    cout << "Quantity: " << f.getQuantity() << endl;

    // Setters
    cout << "\n=== Updating Food ===" << endl;

    f.setPrice(60000);
    f.setQuantity(15);
    f.setName("Cheese Burger");

    f.display();

    // Test invalid data
    cout << "\n=== Testing Invalid Data ===" << endl;

    f.setPrice(-1000);
    f.setQuantity(-5);

    // Final information
    cout << "\n=== Final Food ===" << endl;
    f.display();

    return 0;
}