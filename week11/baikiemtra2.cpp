
#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// ==================== Date Class ====================
class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() {
        day = 1;
        month = 1;
        year = 2000;
    }

    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    int getDay() {
        return day;
    }

    int getMonth() {
        return month;
    }

    int getYear() {
        return year;
    }

    void setDay(int day) {
        this->day = day;
    }

    void setMonth(int month) {
        this->month = month;
    }

    void setYear(int year) {
        this->year = year;
    }

    void displayDate() {
        cout << day << "/" << month << "/" << year;
    }
};

// ==================== Category Class ====================
class Category {
private:
    int CategoryId;
    string CategoryName;
    string Description;

public:
    Category() {
        CategoryId = 0;
        CategoryName = "Unknown";
        Description = "Unknown";
    }

    Category(int id, string name, string description) {
        CategoryId = id;
        CategoryName = name;
        Description = description;
    }

    int GetCategoryId() {
        return CategoryId;
    }

    string GetCategoryName() {
        return CategoryName;
    }

    string GetDescription() {
        return Description;
    }

    void SetCategoryId(int id) {
        CategoryId = id;
    }

    void SetCategoryName(string name) {
        CategoryName = name;
    }

    void SetDescription(string description) {
        Description = description;
    }

    void DisplayCategoryInfo() {
        cout << "Category ID: " << CategoryId << endl;
        cout << "Category Name: " << CategoryName << endl;
        cout << "Description: " << Description << endl;
    }
};

// ==================== Fish Class ====================
class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;
    int categoryId;

public:
    // Default constructor
    Fish() {
        id = 0;
        name = "Unknown";
        color = "Unknown";
        characteristic = "Unknown";
        categoryId = 0;
    }

    // Constructor with 1 parameter
    Fish(int id) {
        this->id = id;
        name = "Unknown";
        color = "Unknown";
        characteristic = "Unknown";
        categoryId = 0;
    }

    // Constructor with 2 parameters
    Fish(int id, string name) {
        this->id = id;
        this->name = name;
        color = "Unknown";
        characteristic = "Unknown";
        categoryId = 0;
    }

    // Constructor with 3 parameters
    Fish(int id, string name, string color) {
        this->id = id;
        this->name = name;
        this->color = color;
        characteristic = "Unknown";
        categoryId = 0;
    }

    // Constructor with 4 parameters
    Fish(int id, string name, string color,
         string characteristic) {
        this->id = id;
        this->name = name;
        this->color = color;
        this->characteristic = characteristic;
        categoryId = 0;
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

    int GetCategoryId() {
        return categoryId;
    }

    // Setters
    void SetId(int id) {
        this->id = id;
    }

    void SetName(string name) {
        this->name = name;
    }

    void SetColor(string color) {
        this->color = color;
    }

    void SetCharacteristics(string characteristic) {
        this->characteristic = characteristic;
    }

    void SetCategoryId(int categoryId) {
        this->categoryId = categoryId;
    }

    // Display fish information
    void displayFishInfo() {
        cout << "Fish ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Characteristic: " << characteristic << endl;
        cout << "Category ID: " << categoryId << endl;
    }
};

// ==================== FishShop Class ====================
class FishShop {
private:
    int id;
    string name;
    string address;
    string owner;
    Date startdate;
    vector<Category> categories;
    vector<Fish> fishes;

public:
    // Default constructor
    FishShop() {
        id = 0;
        name = "Unknown";
        address = "Unknown";
        owner = "Unknown";
        startdate = Date();
    }

    // Constructor with all basic shop information
    FishShop(int id, string name, string address,
             string owner, Date startdate) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->owner = owner;
        this->startdate = startdate;
    }

    // Getters
    int GetId() {
        return id;
    }

    string GetName() {
        return name;
    }

    string GetAddress() {
        return address;
    }

    string GetOwner() {
        return owner;
    }

    Date GetStartDate() {
        return startdate;
    }

    vector<Category> GetCategories() {
        return categories;
    }

    vector<Fish> GetFishes() {
        return fishes;
    }

    // Setters
    void SetId(int id) {
        this->id = id;
    }

    void SetName(string name) {
        this->name = name;
    }

    void SetAddress(string address) {
        this->address = address;
    }

    void SetOwner(string owner) {
        this->owner = owner;
    }

    void SetStartDate(Date startdate) {
        this->startdate = startdate;
    }

    void SetCategories(vector<Category> categories) {
        this->categories = categories;
    }

    void SetFishes(vector<Fish> fishes) {
        this->fishes = fishes;
    }

    // Add a category
    void AddCategory(Category category) {
        categories.push_back(category);
    }

    // Add a fish
    void AddFish(Fish fish) {
        fishes.push_back(fish);
    }

    // Display shop information
    void DisplayShopInfo() {
        cout << "\n========== FISH SHOP INFORMATION ==========\n";
        cout << "Shop ID: " << id << endl;
        cout << "Shop Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Owner: " << owner << endl;

        cout << "Start Date: ";
        startdate.displayDate();
        cout << endl;

        cout << "Number of Categories: "
             << categories.size() << endl;

        cout << "Number of Fish: "
             << fishes.size() << endl;
    }

    // Display all categories
    void DisplayAllCategories() {
        cout << "\n========== ALL CATEGORIES ==========\n";

        for (int i = 0; i < categories.size(); i++) {
            categories[i].DisplayCategoryInfo();
            cout << "------------------------" << endl;
        }
    }

    // Display all fish
    void DisplayAllFishes() {
        cout << "\n========== ALL FISH ==========\n";

        for (int i = 0; i < fishes.size(); i++) {
            fishes[i].displayFishInfo();
            cout << "------------------------" << endl;
        }
    }

    // Display fish belonging to each category
    void DisplayFishesByCategory() {
        cout << "\n========== FISH BY CATEGORY ==========\n";

        for (int i = 0; i < categories.size(); i++) {
            int currentCategoryId =
                categories[i].GetCategoryId();

            cout << "\nCategory: "
                 << categories[i].GetCategoryName() << endl;

            bool found = false;

            for (int j = 0; j < fishes.size(); j++) {
                if (fishes[j].GetCategoryId()
                    == currentCategoryId) {

                    fishes[j].displayFishInfo();
                    cout << "------------------------" << endl;
                    found = true;
                }
            }

            if (!found) {
                cout << "No fish in this category." << endl;
            }
        }
    }
};

// ==================== Main Function ====================
int main() {
    // Create a FishShop object
    FishShop shop;

    // Input shop information
    int shopId;
    string shopName, address, owner;
    int day, month, year;

    cout << "Enter shop ID: ";
    cin >> shopId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter shop name: ";
    getline(cin, shopName);

    cout << "Enter shop address: ";
    getline(cin, address);

    cout << "Enter shop owner: ";
    getline(cin, owner);

    cout << "Enter establishment date (day month year): ";
    cin >> day >> month >> year;

    // Use setters to update shop information
    shop.SetId(shopId);
    shop.SetName(shopName);
    shop.SetAddress(address);
    shop.SetOwner(owner);
    shop.SetStartDate(Date(day, month, year));

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Input 4 categories
    cout << "\n========== INPUT 4 CATEGORIES ==========\n";

    for (int i = 0; i < 4; i++) {
        int categoryId;
        string categoryName, description;

        cout << "\nCategory " << i + 1 << endl;

        cout << "Enter category ID: ";
        cin >> categoryId;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter category name: ";
        getline(cin, categoryName);

        cout << "Enter description: ";
        getline(cin, description);

        Category category(
            categoryId, categoryName, description
        );

        shop.AddCategory(category);

        // Input 10 fish for this category
        cout << "\nEnter 10 fish for category "
             << categoryName << endl;

        for (int j = 0; j < 10; j++) {
            int fishId;
            string fishName, color, characteristic;

            cout << "\nFish " << j + 1 << endl;

            cout << "Enter fish ID: ";
            cin >> fishId;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter fish name: ";
            getline(cin, fishName);

            cout << "Enter fish color: ";
            getline(cin, color);

            cout << "Enter fish characteristic: ";
            getline(cin, characteristic);

            Fish fish(
                fishId, fishName, color, characteristic
            );

            // Assign the fish to its category
            fish.SetCategoryId(categoryId);

            shop.AddFish(fish);
        }
    }

    // Display all information
    shop.DisplayShopInfo();
    shop.DisplayAllCategories();
    shop.DisplayAllFishes();

    // Display fish grouped by category
    shop.DisplayFishesByCategory();

    return 0;
}
