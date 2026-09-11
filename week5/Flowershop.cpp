#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_FLOWERS = 20;

// ================= FUNCTIONS =================

// Input flower information
void inputFlowers(string names[], double prices[], int quantities[],
                  string types[], int N) {

    for (int i = 0; i < N; i++) {
        cout << "\nFlower " << i + 1 << ":\n";

        cout << "Name: ";
        cin >> names[i];

        // price must be > 0
        do {
            cout << "Price: ";
            cin >> prices[i];

            if (prices[i] <= 0) {
                cout << "Price must be greater than 0!\n";
            }

        } while (prices[i] <= 0);

        // quantity must be >= 0
        do {
            cout << "Quantity: ";
            cin >> quantities[i];

            if (quantities[i] < 0) {
                cout << "Quantity cannot be negative!\n";
            }

        } while (quantities[i] < 0);

        cout << "Type: ";
        cin >> types[i];
    }
}


// Display all flowers
void displayFlowers(string names[], double prices[], int quantities[],
                    string types[], int N) {

    cout << "\n===== FLOWER SHOP =====\n\n";

    cout << left
         << setw(5) << "No"
         << setw(15) << "Name"
         << setw(10) << "Price"
         << setw(10) << "Qty"
         << setw(15) << "Type"
         << "\n";

    cout << "--------------------------------------------------\n";

    for (int i = 0; i < N; i++) {

        cout << left
             << setw(5) << i + 1
             << setw(15) << names[i]
             << setw(10) << prices[i]
             << setw(10) << quantities[i]
             << setw(15) << types[i]
             << "\n";
    }
}


// Find most expensive and cheapest flower
void highestLowest(string names[], double prices[], int N) {

    int highestIndex = 0;
    int lowestIndex = 0;

    for (int i = 1; i < N; i++) {

        if (prices[i] > prices[highestIndex]) {
            highestIndex = i;
        }

        if (prices[i] < prices[lowestIndex]) {
            lowestIndex = i;
        }
    }

    cout << "\n----- ANALYSIS -----\n";

    cout << "Most expensive flower : "
         << names[highestIndex]
         << " (" << prices[highestIndex] << ")\n";

    cout << "Cheapest flower       : "
         << names[lowestIndex]
         << " (" << prices[lowestIndex] << ")\n";
}


// Calculate report
void report(double prices[], int quantities[], int N) {

    int totalQuantity = 0;
    double totalPrice = 0;

    for (int i = 0; i < N; i++) {

        totalQuantity += quantities[i];
        totalPrice += prices[i];
    }

    double averagePrice = totalPrice / N;

    cout << "Total quantity        : "
         << totalQuantity << "\n";

    cout << "Average price         : "
         << averagePrice << "\n";
}


// Count flowers by type
void countTypes(string types[], int N) {

    cout << "\n----- COUNT BY TYPE -----\n";

    string countedTypes[MAX_FLOWERS];
    int typeCounts[MAX_FLOWERS];

    int numberOfTypes = 0;

    for (int i = 0; i < N; i++) {

        bool found = false;

        for (int j = 0; j < numberOfTypes; j++) {

            if (types[i] == countedTypes[j]) {

                typeCounts[j]++;
                found = true;
                break;
            }
        }

        // new type
        if (found == false) {

            countedTypes[numberOfTypes] = types[i];
            typeCounts[numberOfTypes] = 1;

            numberOfTypes++;
        }
    }

    for (int i = 0; i < numberOfTypes; i++) {

        cout << countedTypes[i]
             << " : "
             << typeCounts[i]
             << "\n";
    }
}


// Search flower by name
void searchFlower(string names[], double prices[],
                  int quantities[], string types[], int N) {

    string searchName;

    cout << "\nEnter flower name to search: ";
    cin >> searchName;

    bool found = false;

    for (int i = 0; i < N; i++) {

        if (names[i] == searchName) {

            cout << "\nFound!\n";
            cout << "Price: " << prices[i] << "\n";
            cout << "Quantity: " << quantities[i] << "\n";
            cout << "Type: " << types[i] << "\n";

            found = true;
            break;
        }
    }

    if (found == false) {
        cout << "Flower not found!\n";
    }
}


// ================= MAIN =================

int main() {

    int N;

    string names[MAX_FLOWERS];
    double prices[MAX_FLOWERS];
    int quantities[MAX_FLOWERS];
    string types[MAX_FLOWERS];

    // Ask number of flowers
    do {

        cout << "How many flowers? ";
        cin >> N;

        if (N <= 0 || N > MAX_FLOWERS) {
            cout << "Please enter from 1 to "
                 << MAX_FLOWERS << " flowers.\n";
        }

    } while (N <= 0 || N > MAX_FLOWERS);


    // 1. Input
    inputFlowers(names, prices, quantities, types, N);

    // 2. Display
    displayFlowers(names, prices, quantities, types, N);

    // 3. Most expensive / cheapest
    highestLowest(names, prices, N);

    // 4. Report
    report(prices, quantities, N);

    // 5. Count by type
    countTypes(types, N);

    // 6. Keep searching
    char choice;

    do {

        searchFlower(names, prices, quantities, types, N);

        cout << "\nSearch another flower? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');


    cout << "\nProgram ended.\n";

    return 0;
}