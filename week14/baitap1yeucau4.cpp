
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Base class
class Vehicle {
private:
    int id;
    string brand;
    double dailyRate;

public:
    // Default constructor
    Vehicle() {
        id = 0;
        brand = "";
        dailyRate = 0;
    }

    // Parameterized constructor
    Vehicle(int id, string brand, double dailyRate) {
        this->id = id;
        this->brand = brand;
        this->dailyRate = dailyRate;
    }

    // Getters
    int getId() {
        return id;
    }

    string getBrand() {
        return brand;
    }

    double getDailyRate() {
        return dailyRate;
    }

    // Setters
    void setId(int id) {
        this->id = id;
    }

    void setBrand(string brand) {
        this->brand = brand;
    }

    void setDailyRate(double dailyRate) {
        this->dailyRate = dailyRate;
    }

    // Display common information
    virtual void displayInfo() {
        cout << "ID: " << id
             << " | Brand: " << brand
             << " | Daily rate: " << dailyRate << endl;
    }

    // Polymorphism
    virtual double calculateRentalFee(int days) {
        return dailyRate * days;
    }

    // Virtual destructor
    virtual ~Vehicle() {}
};

// Derived class: Car
class Car : public Vehicle {
private:
    int seats;

public:
    Car() : Vehicle() {
        seats = 4;
    }

    Car(int id, string brand, double dailyRate, int seats)
        : Vehicle(id, brand, dailyRate) {
        this->seats = seats;
    }

    int getSeats() {
        return seats;
    }

    void setSeats(int seats) {
        this->seats = seats;
    }

    void displayInfo() override {
        cout << "[Car] ";
        Vehicle::displayInfo();
        cout << "Seats: " << seats << endl;
    }

    double calculateRentalFee(int days) override {
        double fee = getDailyRate() * days;

        if (days >= 7) {
            fee *= 0.90;
        }

        return fee;
    }
};

// Derived class: Motorbike
class Motorbike : public Vehicle {
private:
    int engineCC;

public:
    Motorbike() : Vehicle() {
        engineCC = 110;
    }

    Motorbike(int id, string brand, double dailyRate, int engineCC)
        : Vehicle(id, brand, dailyRate) {
        this->engineCC = engineCC;
    }

    int getEngineCC() {
        return engineCC;
    }

    void setEngineCC(int engineCC) {
        this->engineCC = engineCC;
    }

    void displayInfo() override {
        cout << "[Motorbike] ";
        Vehicle::displayInfo();
        cout << "Engine: " << engineCC << " cc" << endl;
    }

    double calculateRentalFee(int days) override {
        double fee = getDailyRate() * days;

        if (days >= 5) {
            fee *= 0.95;
        }

        return fee;
    }
};

// Derived class: Truck
class Truck : public Vehicle {
private:
    double transportFee;

public:
    Truck() : Vehicle() {
        transportFee = 500000;
    }

    Truck(int id, string brand, double dailyRate,
          double transportFee)
        : Vehicle(id, brand, dailyRate) {
        this->transportFee = transportFee;
    }

    double getTransportFee() {
        return transportFee;
    }

    void setTransportFee(double transportFee) {
        this->transportFee = transportFee;
    }

    void displayInfo() override {
        cout << "[Truck] ";
        Vehicle::displayInfo();
        cout << "Transport fee: " << transportFee << endl;
    }

    double calculateRentalFee(int days) override {
        return getDailyRate() * days + transportFee;
    }
};

int main() {
    vector<Vehicle*> vehicles;

    // Create vehicles
    vehicles.push_back(new Car(1, "Toyota", 1000000, 5));
    vehicles.push_back(new Car(2, "Honda", 800000, 4));
    vehicles.push_back(new Motorbike(3, "Yamaha", 150000, 155));
    vehicles.push_back(new Motorbike(4, "Honda", 100000, 125));
    vehicles.push_back(new Truck(5, "Isuzu", 2000000, 500000));
    vehicles.push_back(new Truck(6, "Hino", 2500000, 700000));

    int days = 7;
    double totalRevenue = 0;
    double highestFee = -1;
    Vehicle* mostExpensive = nullptr;

    cout << fixed << setprecision(0);

    cout << "===== VEHICLE INFORMATION =====" << endl;

    for (Vehicle* vehicle : vehicles) {
        vehicle->displayInfo();

        double fee = vehicle->calculateRentalFee(days);

        cout << "Rental days: " << days << endl;
        cout << "Rental fee: " << fee << " VND" << endl;
        cout << "-----------------------------" << endl;

        totalRevenue += fee;

        if (fee > highestFee) {
            highestFee = fee;
            mostExpensive = vehicle;
        }
    }

    cout << "\n===== SUMMARY =====" << endl;
    cout << "Total rental revenue: "
         << totalRevenue << " VND" << endl;

    cout << "\nVehicle with the highest rental fee:" << endl;

    if (mostExpensive != nullptr) {
        mostExpensive->displayInfo();
        cout << "Highest rental fee: "
             << highestFee << " VND" << endl;
    }

    // Release dynamically allocated memory
    for (Vehicle* vehicle : vehicles) {
        delete vehicle;
    }

    vehicles.clear();

    return 0;
}
