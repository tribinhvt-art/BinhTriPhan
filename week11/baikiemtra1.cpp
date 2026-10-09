
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
    Fish(int newid, string newname) {
        id = newid;
        name = newname;
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
    int Getid() {
        return id;
    }

    string GetName() {
        return name;
    }

    string GetColor() {
        return color;
    }

    string GetCharacteristics() {
        return characteristic;
    }

    // Setters method

    int SetId(int id){
        this->id = id;
    }

    string SetColor(string color){
        this->color = color;
    }

    string SetName(string name){
        this->name = name;
    }

    string SetCharacteristics(string characteristic){
        this->characteristic = characteristic;
    }
 
    // Display fish information
    void Display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Characteristic: "
             << characteristic << endl;
        cout << "-------------------" << endl;
    }
}; // Close class Fish

int main() {
    // Create 5 Fish objects using different constructors
    Fish fish1;
    Fish fish2(2);
    Fish fish3(3, "Betta");
    Fish fish4(4, "Goldfish", "Orange");
    Fish fish5(5, "Guppy", "Blue",
               "Small and active");

    // Display information
    fish1.Display();
    fish2.Display();
    fish3.Display();
    fish4.Display();
    fish5.Display();

    return 0;
}
