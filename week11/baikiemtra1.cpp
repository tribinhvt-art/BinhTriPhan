
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ==================== Category Class ====================
class Category {
private:
    int CategoryId;
    string CategoryName;
    string Description;

public:
    // Default constructor
    Category() {
        CategoryId = 0;
        CategoryName = "Unknown";
        Description = "Unknown";
    }

    // Constructor with 3 parameters
    Category(int id, string name, string description) {
        CategoryId = id;
        CategoryName = name;
        Description = description;
    }

    // Getters
    int GetCategoryId() {
        return CategoryId;
    }

    string GetCategoryName() {
        return CategoryName;
    }

    string GetDescription() {
        return Description;
    }

    // Setters
    void SetCategoryId(int id) {
        CategoryId = id;
    }

    void SetCategoryName(string name) {
        CategoryName = name;
    }

    void SetDescription(string description) {
        Description = description;
    }

    // Display category information
    void DisplayCategoryInfo() {
        cout << "Category ID: " << CategoryId << endl;
        cout << "Category Name: " << CategoryName << endl;
        cout << "Description: " << Description << endl;
        cout << "------------------------" << endl;
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
    // 1. Default constructor
    Fish() {
        id = 0;
        name = "Unknown";
        color = "Unknown";
        characteristic = "Unknown";
        categoryId = 0;
    }

    // 2. Constructor with 1 parameter
    Fish(int id) {
        this->id = id;
        name = "Unknown";
        color = "Unknown";
        characteristic = "Unknown";
        categoryId = 0;
    }

    // 3. Constructor with 2 parameters
    Fish(int newid, string newname) {
        id = newid;
        name = newname;
        color = "Unknown";
        characteristic = "Unknown";
        categoryId = 0;
    }

    // 4. Constructor with 3 parameters
    Fish(int id, string name, string color) {
        this->id = id;
        this->name = name;
        this->color = color;
        characteristic = "Unknown";
        categoryId = 0;
    }

    // 5. Constructor with 4 parameters
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
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Characteristic: " << characteristic << endl;
        cout << "Category ID: " << categoryId << endl;
        cout << "------------------------" << endl;
    }
};

// ==================== Main Function ====================
int main() {

    // Question 7: Create 3 categories
    vector<Category> categories = {
        Category(1, "Betta Fish", "Colorful fish with flowing fins"),
        Category(2, "Goldfish", "Popular ornamental freshwater fish"),
        Category(3, "Tropical Fish", "Fish from tropical waters")
    };

    // Create 15 fish: 5 original + 10 additional fish
    vector<Fish> fishes = {
        Fish(),
        Fish(2),
        Fish(3, "LeDuyAnh"),
        Fish(4, "LeDuyAnh", "Orange"),
        Fish(5, "LeDuyAnh", "Blue", "Small and active"),

        // 10 additional ornamental fish
        Fish(6, "LeDuyAnh", "Black and White", "Peaceful fish"),
        Fish(7, "NguyenNgocThinh", "Black", "Easy to care for"),
        Fish(8, "NguyenChiBao", "Red", "Active and friendly"),
        Fish(9, "DoanPhucKhang", "Blue", "Round body"),
        Fish(10, "LeDuyAnh", "Blue", "Small schooling fish"),
        Fish(11, "LeDuyAnh", "White", "Decorative pond fish"),
        Fish(12, "LeDuyAnh", "Orange", "Large freshwater fish"),
        Fish(13, "LeDuyAnh", "Red", "Has a sword-like tail"),
        Fish(14, "LeDuyAnh", "Red", "Distinctive head shape"),
        Fish(15, "LeDuyAnh", "Silver", "Fast-swimming fish")
    };

    // Assign categories to all fish
    fishes[0].SetCategoryId(1);
    fishes[1].SetCategoryId(1);
    fishes[2].SetCategoryId(1);
    fishes[3].SetCategoryId(2);
    fishes[4].SetCategoryId(3);
    fishes[5].SetCategoryId(3);
    fishes[6].SetCategoryId(3);
    fishes[7].SetCategoryId(3);
    fishes[8].SetCategoryId(3);
    fishes[9].SetCategoryId(3);
    fishes[10].SetCategoryId(2);
    fishes[11].SetCategoryId(3);
    fishes[12].SetCategoryId(3);
    fishes[13].SetCategoryId(3);
    fishes[14].SetCategoryId(3);

    // Display all fish
    cout << "========== ALL FISH ==========" << endl;

    for (int i = 0; i < fishes.size(); i++) {
        fishes[i].displayFishInfo();
    }

    // Question 6: Group fish by color using vector and for loops
    cout << "\n========== FISH GROUPED BY COLOR ==========" << endl;

    for (int i = 0; i < fishes.size(); i++) {
        string color = fishes[i].GetColor();

        // Check if this color appeared before
        bool appeared = false;

        for (int j = 0; j < i; j++) {
            if (fishes[j].GetColor() == color) {
                appeared = true;
                break;
            }
        }

        // Skip colors that have already been displayed
        if (appeared) {
            continue;
        }

        cout << "\nColor: " << color << endl;

        // Display all fish with the same color
        for (int j = 0; j < fishes.size(); j++) {
            if (fishes[j].GetColor() == color) {
                cout << "- " << fishes[j].GetName() << endl;
            }
        }
    }

    // Question 7: Display all categories
    cout << "\n========== ALL CATEGORIES ==========" << endl;

    for (int i = 0; i < categories.size(); i++) {
        categories[i].DisplayCategoryInfo();
    }

    // Select a category and display its fish
    int selectedCategoryId;

    cout << "\nEnter category ID (1-3): ";
    cin >> selectedCategoryId;

    bool foundCategory = false;

    for (int i = 0; i < categories.size(); i++) {
        if (categories[i].GetCategoryId() == selectedCategoryId) {
            foundCategory = true;

            cout << "\nCategory: "
                 << categories[i].GetCategoryName() << endl;

            cout << "Description: "
                 << categories[i].GetDescription() << endl;

            cout << "\nFish belonging to this category:" << endl;

            bool foundFish = false;

            for (int j = 0; j < fishes.size(); j++) {
                if (fishes[j].GetCategoryId() == selectedCategoryId) {
                    fishes[j].displayFishInfo();
                    foundFish = true;
                }
            }

            if (!foundFish) {
                cout << "No fish in this category." << endl;
            }

            break;
        }
    }

    if (!foundCategory) {
        cout << "Category not found." << endl;
    }

    return 0;
}
