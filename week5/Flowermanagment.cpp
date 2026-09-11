#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Flower {
    string name;
    double price;
    int quantity;
    string type;
};

const int MAX_FLOWERS = 20;


// =====================================================
// INPUT
// =====================================================

void inputFlowers(Flower flowers[], int N) {

    for (int i = 0; i < N; i++) {

        cout << "\nFlower " << i + 1 << ":\n";

        cout << "Name: ";
        cin >> flowers[i].name;

        do {
            cout << "Price: ";
            cin >> flowers[i].price;

            if (flowers[i].price <= 0) {
                cout << "Price must be greater than 0.\n";
            }

        } while (flowers[i].price <= 0);


        do {
            cout << "Quantity: ";
            cin >> flowers[i].quantity;

            if (flowers[i].quantity < 0) {
                cout << "Quantity cannot be negative.\n";
            }

        } while (flowers[i].quantity < 0);


        cout << "Type: ";
        cin >> flowers[i].type;
    }
}


// =====================================================
// 1. DISPLAY ALL FLOWERS
// =====================================================

void displayFlowers(Flower flowers[], int N) {

    cout << "\n===== FLOWER LIST =====\n";

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
             << setw(15) << flowers[i].name
             << setw(10) << flowers[i].price
             << setw(10) << flowers[i].quantity
             << setw(15) << flowers[i].type
             << "\n";
    }
}


// =====================================================
// 2. MOST EXPENSIVE
// =====================================================

void mostExpensive(Flower flowers[], int N) {

    int index = 0;

    for (int i = 1; i < N; i++) {

        if (flowers[i].price > flowers[index].price) {
            index = i;
        }
    }

    cout << "Most expensive flower: "
         << flowers[index].name
         << " (" << flowers[index].price << ")\n";
}


// =====================================================
// 3. CHEAPEST
// =====================================================

void cheapestFlower(Flower flowers[], int N) {

    int index = 0;

    for (int i = 1; i < N; i++) {

        if (flowers[i].price < flowers[index].price) {
            index = i;
        }
    }

    cout << "Cheapest flower: "
         << flowers[index].name
         << " (" << flowers[index].price << ")\n";
}


// =====================================================
// 4. LARGEST QUANTITY
// =====================================================

void largestQuantity(Flower flowers[], int N) {

    int index = 0;

    for (int i = 1; i < N; i++) {

        if (flowers[i].quantity > flowers[index].quantity) {
            index = i;
        }
    }

    cout << "Flower with largest quantity: "
         << flowers[index].name
         << " (" << flowers[index].quantity << ")\n";
}


// =====================================================
// 5. TOTAL QUANTITY
// =====================================================

int totalQuantity(Flower flowers[], int N) {

    int total = 0;

    for (int i = 0; i < N; i++) {
        total += flowers[i].quantity;
    }

    return total;
}


// =====================================================
// 6. AVERAGE PRICE
// =====================================================

double averagePrice(Flower flowers[], int N) {

    double sum = 0;

    for (int i = 0; i < N; i++) {
        sum += flowers[i].price;
    }

    return sum / N;
}


// =====================================================
// 7. COUNT FLOWERS BY TYPE
// =====================================================

void countByType(Flower flowers[], int N) {

    string countedTypes[MAX_FLOWERS];
    int counts[MAX_FLOWERS];

    int typeCount = 0;

    for (int i = 0; i < N; i++) {

        bool found = false;

        for (int j = 0; j < typeCount; j++) {

            if (flowers[i].type == countedTypes[j]) {

                counts[j]++;
                found = true;
                break;
            }
        }

        if (found == false) {

            countedTypes[typeCount] = flowers[i].type;
            counts[typeCount] = 1;

            typeCount++;
        }
    }


    cout << "\n===== COUNT BY TYPE =====\n";

    for (int i = 0; i < typeCount; i++) {

        cout << countedTypes[i]
             << " : "
             << counts[i]
             << "\n";
    }
}


// =====================================================
// 8. FIND ALL FLOWERS OF GIVEN TYPE
// =====================================================

void findByType(Flower flowers[], int N) {

    string searchType;

    cout << "Enter type: ";
    cin >> searchType;

    bool found = false;

    for (int i = 0; i < N; i++) {

        if (flowers[i].type == searchType) {

            cout << flowers[i].name
                 << " - Price: " << flowers[i].price
                 << " - Quantity: " << flowers[i].quantity
                 << "\n";

            found = true;
        }
    }

    if (!found) {
        cout << "No flowers found.\n";
    }
}


// =====================================================
// 9. SEARCH BY NAME
// =====================================================

void searchByName(Flower flowers[], int N) {

    string searchName;

    cout << "Enter flower name: ";
    cin >> searchName;

    for (int i = 0; i < N; i++) {

        if (flowers[i].name == searchName) {

            cout << "Found!\n";
            cout << "Name: " << flowers[i].name << "\n";
            cout << "Price: " << flowers[i].price << "\n";
            cout << "Quantity: " << flowers[i].quantity << "\n";
            cout << "Type: " << flowers[i].type << "\n";

            return;
        }
    }

    cout << "Flower not found.\n";
}


// =====================================================
// 10. CHECK IF FLOWER EXISTS
// =====================================================

void flowerExists(Flower flowers[], int N) {

    string name;

    cout << "Enter flower name: ";
    cin >> name;

    bool exists = false;

    for (int i = 0; i < N; i++) {

        if (flowers[i].name == name) {

            exists = true;
            break;
        }
    }

    if (exists)
        cout << "Yes\n";
    else
        cout << "No\n";
}


// =====================================================
// 11. COUNT LOW QUANTITY
// =====================================================

void countLowQuantity(Flower flowers[], int N) {

    int count = 0;

    for (int i = 0; i < N; i++) {

        if (flowers[i].quantity < 5) {
            count++;
        }
    }

    cout << "Flowers with quantity < 5: "
         << count << "\n";
}


// =====================================================
// 12. COUNT FLOWERS IN PRICE RANGE
// =====================================================

void countPriceRange(Flower flowers[], int N) {

    double minPrice;
    double maxPrice;

    cout << "Minimum price: ";
    cin >> minPrice;

    cout << "Maximum price: ";
    cin >> maxPrice;

    int count = 0;

    for (int i = 0; i < N; i++) {

        if (flowers[i].price >= minPrice &&
            flowers[i].price <= maxPrice) {

            count++;
        }
    }

    cout << "Number of flowers in range: "
         << count << "\n";
}


// =====================================================
// 13. CALCULATE TOTAL VALUE
// =====================================================

double calculateTotalValue(Flower flowers[], int N) {

    double total = 0;

    for (int i = 0; i < N; i++) {

        total += flowers[i].price * flowers[i].quantity;
    }

    return total;
}


// =====================================================
// 14. MOST VALUABLE FLOWER
// =====================================================

void mostValuableFlower(Flower flowers[], int N) {

    int index = 0;

    double maxValue =
        flowers[0].price * flowers[0].quantity;

    for (int i = 1; i < N; i++) {

        double value =
            flowers[i].price * flowers[i].quantity;

        if (value > maxValue) {

            maxValue = value;
            index = i;
        }
    }

    cout << "Most valuable flower: "
         << flowers[index].name
         << "\n";

    cout << "Value: "
         << maxValue
         << "\n";
}


// =====================================================
// 15. SORT BY PRICE ASCENDING
// =====================================================

void sortByPrice(Flower flowers[], int N) {

    for (int i = 0; i < N - 1; i++) {

        for (int j = i + 1; j < N; j++) {

            if (flowers[i].price > flowers[j].price) {

                Flower temp = flowers[i];

                flowers[i] = flowers[j];

                flowers[j] = temp;
            }
        }
    }

    cout << "Sorted by price.\n";

    displayFlowers(flowers, N);
}


// =====================================================
// 16. SORT BY NAME A -> Z
// =====================================================

void sortByName(Flower flowers[], int N) {

    for (int i = 0; i < N - 1; i++) {

        for (int j = i + 1; j < N; j++) {

            if (flowers[i].name > flowers[j].name) {

                Flower temp = flowers[i];

                flowers[i] = flowers[j];

                flowers[j] = temp;
            }
        }
    }

    cout << "Sorted by name.\n";

    displayFlowers(flowers, N);
}


// =====================================================
// 17. TOP 3 MOST EXPENSIVE
// =====================================================

void top3Expensive(Flower flowers[], int N) {

    Flower temp[MAX_FLOWERS];

    for (int i = 0; i < N; i++) {
        temp[i] = flowers[i];
    }


    // sort descending
    for (int i = 0; i < N - 1; i++) {

        for (int j = i + 1; j < N; j++) {

            if (temp[i].price < temp[j].price) {

                Flower swapFlower = temp[i];

                temp[i] = temp[j];

                temp[j] = swapFlower;
            }
        }
    }


    int limit;

    if (N < 3)
        limit = N;
    else
        limit = 3;


    cout << "\nTop " << limit
         << " most expensive flowers:\n";

    for (int i = 0; i < limit; i++) {

        cout << i + 1 << ". "
             << temp[i].name
             << " - "
             << temp[i].price
             << "\n";
    }
}


// =====================================================
// 18. SEARCH NAME CONTAINING KEYWORD
// =====================================================

void searchKeyword(Flower flowers[], int N) {

    string keyword;

    cout << "Enter keyword: ";
    cin >> keyword;

    bool found = false;

    for (int i = 0; i < N; i++) {

        if (flowers[i].name.find(keyword)
            != string::npos) {

            cout << flowers[i].name
                 << " - "
                 << flowers[i].price
                 << "\n";

            found = true;
        }
    }

    if (!found) {
        cout << "No matching flowers.\n";
    }
}


// =====================================================
// 19. AVERAGE QUANTITY BY TYPE
// =====================================================

void averageQuantityByType(Flower flowers[], int N) {

    string types[MAX_FLOWERS];

    int totalQuantity[MAX_FLOWERS];
    int counts[MAX_FLOWERS];

    int typeCount = 0;


    for (int i = 0; i < N; i++) {

        bool found = false;

        for (int j = 0; j < typeCount; j++) {

            if (flowers[i].type == types[j]) {

                totalQuantity[j] += flowers[i].quantity;
                counts[j]++;

                found = true;
                break;
            }
        }


        if (!found) {

            types[typeCount] = flowers[i].type;

            totalQuantity[typeCount] =
                flowers[i].quantity;

            counts[typeCount] = 1;

            typeCount++;
        }
    }


    cout << "\nAverage quantity by type:\n";

    for (int i = 0; i < typeCount; i++) {

        double average =
            (double) totalQuantity[i] / counts[i];

        cout << types[i]
             << " : "
             << average
             << "\n";
    }
}


// =====================================================
// 20. SIMPLE REPORT
// =====================================================

void simpleReport(Flower flowers[], int N) {

    cout << "\n===== FLOWER SHOP REPORT =====\n";

    cout << "Number of flowers: "
         << N << "\n";

    cout << "Total quantity: "
         << totalQuantity(flowers, N)
         << "\n";

    cout << "Average price: "
         << averagePrice(flowers, N)
         << "\n";

    cout << "Total inventory value: "
         << calculateTotalValue(flowers, N)
         << "\n";

    countByType(flowers, N);
}


// =====================================================
// MAIN
// =====================================================

int main() {

    Flower flowers[MAX_FLOWERS];

    int N;

    do {

        cout << "How many flowers? ";
        cin >> N;

        if (N < 1 || N > 20) {
            cout << "N must be from 1 to 20.\n";
        }

    } while (N < 1 || N > 20);


    inputFlowers(flowers, N);


    int choice;

    do {

        cout << "\n============================\n";
        cout << "FLOWER SHOP MANAGER\n";
        cout << "============================\n";

        cout << "1. Display all flowers\n";
        cout << "2. Most expensive flower\n";
        cout << "3. Cheapest flower\n";
        cout << "4. Largest quantity\n";
        cout << "5. Total quantity\n";
        cout << "6. Average price\n";
        cout << "7. Count flowers by type\n";
        cout << "8. Find flowers by type\n";
        cout << "9. Search by name\n";
        cout << "10. Check if flower exists\n";
        cout << "11. Count low quantity\n";
        cout << "12. Count price range\n";
        cout << "13. Calculate total value\n";
        cout << "14. Most valuable flower\n";
        cout << "15. Sort by price\n";
        cout << "16. Sort by name\n";
        cout << "17. Top 3 expensive flowers\n";
        cout << "18. Search by keyword\n";
        cout << "19. Average quantity by type\n";
        cout << "20. Simple report\n";
        cout << "0. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;


        switch (choice) {

        case 1:
            displayFlowers(flowers, N);
            break;

        case 2:
            mostExpensive(flowers, N);
            break;

        case 3:
            cheapestFlower(flowers, N);
            break;

        case 4:
            largestQuantity(flowers, N);
            break;

        case 5:
            cout << "Total quantity: "
                 << totalQuantity(flowers, N)
                 << "\n";
            break;

        case 6:
            cout << "Average price: "
                 << averagePrice(flowers, N)
                 << "\n";
            break;

        case 7:
            countByType(flowers, N);
            break;

        case 8:
            findByType(flowers, N);
            break;

        case 9:
            searchByName(flowers, N);
            break;

        case 10:
            flowerExists(flowers, N);
            break;

        case 11:
            countLowQuantity(flowers, N);
            break;

        case 12:
            countPriceRange(flowers, N);
            break;

        case 13:
            cout << "Total value: "
                 << calculateTotalValue(flowers, N)
                 << "\n";
            break;

        case 14:
            mostValuableFlower(flowers, N);
            break;

        case 15:
            sortByPrice(flowers, N);
            break;

        case 16:
            sortByName(flowers, N);
            break;

        case 17:
            top3Expensive(flowers, N);
            break;

        case 18:
            searchKeyword(flowers, N);
            break;

        case 19:
            averageQuantityByType(flowers, N);
            break;

        case 20:
            simpleReport(flowers, N);
            break;

        case 0:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);


    return 0;
}