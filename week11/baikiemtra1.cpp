
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

    void SetId(int id){
        this->id = id;
    }

    void SetColor(string color){
        this->color = color;
    }

    void SetName(string name){
        this->name = name;
    }

    void SetCharacteristics(string characteristic){
        this->characteristic = characteristic;
    }
 
    // Display fish information
    void displayFishInfo() {
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
    fish1.displayFishInfo();
    fish2.displayFishInfo();
    fish3.displayFishInfo();
    fish4.displayFishInfo();    
    fish5.displayFishInfo();

    //update name,color, and characteristics of one Object
    fish1.SetName("Delta");
    fish1.SetId(84971547707);
    fish1.SetColor("Orange");
    fish1.SetCharacteristics("string");

    //Retrieving information of updated object
    cout << "Name is: " <<fish1.GetName() << endl;
    cout << "Color is: " <<fish1.GetColor() << endl;
    cout << "Id is: " <<fish1.Getid() << endl;
    cout << "Characteristic is: " <<fish1.GetCharacteristics() << endl;


    cout << "\n=== Verify Updated Fish ===" << endl;
    fish1.displayFishInfo();

    return 0;
}
