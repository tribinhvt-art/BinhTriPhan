
#include <iostream>
#include <string>
using namespace std;

class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;

public:
    // 1. Default constructor
    Fish() {
        id = 0;
        name = "Unknown";
        color = "Unknown";
        characteristic = "Unknown";
    }

    // 2. Constructor with 1 parameter
    Fish(int id) {
        this->id = id;
        name = "Unknown";
        color = "Unknown";
        characteristic = "Unknown";
    }

    // 3. Constructor with 2 parameters
    Fish(int id, string name) {
        this->id = id;
        this->name = name;
        color = "Unknown";
        characteristic = "Unknown";
    }

    // 4. Constructor with 3 parameters
    Fish(int id, string name, string color) {
        this->id = id;
        this->name = name;
        this->color = color;
        characteristic = "Unknown";
    }

    // 5. Constructor with 4 parameters
    Fish(int id, string name, string color,
         string characteristic) {
        this->id = id;
        this->name = name;
        this->color = color;
        this->characteristic = characteristic;
    }

    // Getters
    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getColor() {
        return color;
    }

    string getCharacteristic() {
        return characteristic;
    }

    // Setters
    void setId(int id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }

    void setColor(string color) {
        this->color = color;
    }

    void setCharacteristic(string characteristic) {
        this->characteristic = characteristic;
    }

    // Display fish information
    void displayFishInfo() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Characteristic: " << characteristic << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    // Create 5 Fish objects using different constructors
    Fish fish1;
    Fish fish2(2);
    Fish fish3(3, "Betta");
    Fish fish4(4, "Goldfish", "Orange");
    Fish fish5(5, "Guppy", "Blue",
               "Small and active");

    // Display all 5 objects
    cout << "=== Original Fish Information ===" << endl;

    fish1.displayFishInfo();
    fish2.displayFishInfo();
    fish3.displayFishInfo();
    fish4.displayFishInfo();
    fish5.displayFishInfo();

    // Update fish3 using setter methods
    fish3.setName("Angelfish");
    fish3.setColor("Black and White");
    fish3.setCharacteristic("Peaceful and elegant");

    // Retrieve and print updated information using getters
    cout << "\n=== Updated Fish Information (Getters) ===" << endl;

    cout << "ID: " << fish3.getId() << endl;
    cout << "Name: " << fish3.getName() << endl;
    cout << "Color: " << fish3.getColor() << endl;
    cout << "Characteristic: "
         << fish3.getCharacteristic() << endl;

    // Display again to verify changes
    cout << "\n=== Verify Updated Fish ===" << endl;
    fish3.displayFishInfo();

    return 0;
}
