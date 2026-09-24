#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// ======================================================
// STRUCT
// ======================================================

struct Dish {
    string name;
};

struct Order {
    string code;
    string customer;
    string address;
    string dish;
    int quantity;
    string status;
};

// ======================================================
// HÀM HỖ TRỢ
// ======================================================

// Chuyển chuỗi thành chữ thường
string toLowerString(string s) {
    for (char &c : s) {
        c = tolower(c);
    }
    return s;
}

// Chuẩn hóa tên món ăn
string normalizeName(string s) {
    stringstream ss(s);
    string word;
    string result;

    while (ss >> word) {

        // Chuyển toàn bộ thành chữ thường
        for (char &c : word) {
            c = tolower(c);
        }

        // Viết hoa chữ cái đầu
        if (!word.empty()) {
            word[0] = toupper(word[0]);
        }

        if (!result.empty()) {
            result += " ";
        }

        result += word;
    }

    return result;
}

// ======================================================
// 1. NHẬP VÀ HIỂN THỊ TÊN CỬA HÀNG
// ======================================================

void bai1() {
    string storeName;

    cout << "Nhap ten cua hang: ";
    getline(cin, storeName);

    cout << "Chao mung den voi " << storeName << "!" << endl;
}

// ======================================================
// 2. CHUẨN HÓA TÊN MÓN ĂN
// ======================================================

void bai2() {
    string name;

    cout << "Nhap ten mon an: ";
    getline(cin, name);

    cout << "Ten sau khi chuan hoa: "
         << normalizeName(name) << endl;
}

// ======================================================
// 3. TẠO MÃ ĐƠN HÀNG
// ======================================================

void bai3() {
    string customer;
    string phone;

    cout << "Nhap ten khach hang: ";
    getline(cin, customer);

    cout << "Nhap so dien thoai: ";
    getline(cin, phone);

    // Lấy 3 ký tự đầu của tên khách hàng
    string codeName = "";

    for (char c : customer) {
        if (isalpha(c)) {
            codeName += toupper(c);
        }

        if (codeName.length() == 3) {
            break;
        }
    }

    // Nếu tên quá ngắn
    while (codeName.length() < 3) {
        codeName += "X";
    }

    // Lấy 4 số cuối điện thoại
    string last4;

    if (phone.length() >= 4) {
        last4 = phone.substr(phone.length() - 4);
    }
    else {
        last4 = phone;
    }

    cout << "Ma don hang: DH-"
         << codeName << "-"
         << last4 << endl;
}

// ======================================================
// 4. KIỂM TRA MÓN ĂN
// ======================================================

void bai4() {

    vector<Dish> menu = {
        {"Banh mi"},
        {"Pho bo"},
        {"Com tam"},
        {"Hamburger"},
        {"Pizza"},
        {"Mi xao"}
    };

    string name;

    cout << "Nhap ten mon an can tim: ";
    getline(cin, name);

    string searchName = toLowerString(name);

    bool found = false;

    for (const Dish &dish : menu) {

        if (toLowerString(dish.name) == searchName) {
            cout << "Mon an co trong menu: "
                 << dish.name << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Mon an khong co trong menu." << endl;
    }
}

// ======================================================
// 5. TÁCH THÔNG TIN ĐƠN HÀNG
// ======================================================

void bai5() {

    string order;

    cout << "Nhap don hang theo dang:\n";
    cout << "Ten khach | Dia chi | Mon an | So luong\n";

    cout << "Nhap: ";
    getline(cin, order);

    stringstream ss(order);

    string customer;
    string address;
    string dish;
    string quantity;

    getline(ss, customer, '|');
    getline(ss, address, '|');
    getline(ss, dish, '|');
    getline(ss, quantity, '|');

    // Xóa khoảng trắng thừa
    auto trim = [](string s) {

        while (!s.empty() && isspace(s.front())) {
            s.erase(s.begin());
        }

        while (!s.empty() && isspace(s.back())) {
            s.pop_back();
        }

        return s;
    };

    customer = trim(customer);
    address = trim(address);
    dish = trim(dish);
    quantity = trim(quantity);

    cout << "\n===== THONG TIN DON HANG =====\n";
    cout << "Ten khach: " << customer << endl;
    cout << "Dia chi: " << address << endl;
    cout << "Mon an: " << dish << endl;
    cout << "So luong: " << quantity << endl;
}

// ======================================================
// 6. THAY ĐỔI TRẠNG THÁI ĐƠN HÀNG
// ======================================================

void bai6() {

    vector<Order> orders = {
        {"DH-AN-1234", "An", "Quan 1", "Banh mi", 2, "Dang chuan bi"},
        {"DH-BD-5678", "Binh", "Quan 3", "Pho bo", 1, "Dang giao"},
        {"DH-CL-9999", "Cuong", "Quan 5", "Pizza", 3, "Hoan thanh"}
    };

    string code;
    string newStatus;

    cout << "Nhap ma don hang: ";
    getline(cin, code);

    cout << "Nhap trang thai moi:\n";
    cout << "1. Dang chuan bi\n";
    cout << "2. Dang giao\n";
    cout << "3. Hoan thanh\n";
    cout << "4. Da huy\n";

    cout << "Lua chon: ";

    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice) {

        case 1:
            newStatus = "Dang chuan bi";
            break;

        case 2:
            newStatus = "Dang giao";
            break;

        case 3:
            newStatus = "Hoan thanh";
            break;

        case 4:
            newStatus = "Da huy";
            break;

        default:
            cout << "Lua chon khong hop le.\n";
            return;
    }

    bool found = false;

    for (Order &order : orders) {

        if (order.code == code) {

            order.status = newStatus;

            cout << "Da cap nhat don hang!\n";
            cout << "Ma: " << order.code << endl;
            cout << "Trang thai: " << order.status << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay don hang.\n";
    }
}

// ======================================================
// 7. TÌM CÁC ĐƠN HÀNG THEO TÊN KHÁCH
// ======================================================

void bai7() {

    vector<Order> orders = {
        {"DH-AN-1234", "Nguyen Van An", "Quan 1",
         "Banh mi", 2, "Dang giao"},

        {"DH-BD-5678", "Tran Van Binh", "Quan 3",
         "Pho bo", 1, "Hoan thanh"},

        {"DH-AN-7777", "An Nguyen", "Quan 5",
         "Pizza", 3, "Dang chuan bi"},

        {"DH-CL-8888", "Nguyen Van Cuong", "Quan 7",
         "Com tam", 1, "Da huy"}
    };

    string keyword;

    cout << "Nhap tu khoa ten khach hang: ";
    getline(cin, keyword);

    keyword = toLowerString(keyword);

    bool found = false;

    cout << "\n===== KET QUA =====\n";

    for (const Order &order : orders) {

        string customer = toLowerString(order.customer);

        if (customer.find(keyword) != string::npos) {

            cout << "Ma don: " << order.code << endl;
            cout << "Khach hang: " << order.customer << endl;
            cout << "Mon: " << order.dish << endl;
            cout << "Trang thai: " << order.status << endl;
            cout << "----------------------\n";

            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay don hang.\n";
    }
}

// ======================================================
// 8. RÚT GỌN ĐỊA CHỈ
// ======================================================

void bai8() {

    string address;

    cout << "Nhap dia chi: ";
    getline(cin, address);

    // Ví dụ:
    // "123 Nguyen Trai, Phuong 1, Quan 5, TP HCM"
    //
    // Rút gọn:
    // "123 Nguyen Trai, Quan 5"

    stringstream ss(address);

    vector<string> parts;
    string part;

    while (getline(ss, part, ',')) {

        // Xóa khoảng trắng đầu/cuối
        while (!part.empty() && isspace(part.front())) {
            part.erase(part.begin());
        }

        while (!part.empty() && isspace(part.back())) {
            part.pop_back();
        }

        parts.push_back(part);
    }

    cout << "Dia chi goc: " << address << endl;

    if (parts.size() >= 3) {

        cout << "Dia chi rut gon: "
             << parts[0] << ", "
             << parts[parts.size() - 2]
             << endl;
    }
    else {
        cout << "Dia chi rut gon: "
             << address << endl;
    }
}

// ======================================================
// 9. THỐNG KÊ MÓN ĂN BÁN CHẠY
// ======================================================

void bai9() {

    vector<Order> orders = {

        {"DH01", "An", "Quan 1",
         "Banh mi", 2, "Hoan thanh"},

        {"DH02", "Binh", "Quan 2",
         "Pho bo", 1, "Hoan thanh"},

        {"DH03", "Cuong", "Quan 3",
         "Banh mi", 3, "Hoan thanh"},

        {"DH04", "Dung", "Quan 4",
         "Pizza", 1, "Dang giao"},

        {"DH05", "An", "Quan 5",
         "Banh mi", 1, "Hoan thanh"}
    };

    string dishName;

    cout << "Nhap ten mon an: ";
    getline(cin, dishName);

    dishName = toLowerString(dishName);

    int count = 0;

    for (const Order &order : orders) {

        if (toLowerString(order.dish) == dishName) {
            count++;
        }
    }

    cout << "Mon an \"" << dishName
         << "\" xuat hien trong "
         << count
         << " don hang." << endl;
}

// ======================================================
// 10. TẠO THÔNG BÁO GIAO HÀNG
// ======================================================

void bai10() {

    string customer;
    string code;
    string address;

    cout << "Nhap ten khach hang: ";
    getline(cin, customer);

    cout << "Nhap ma don hang: ";
    getline(cin, code);

    cout << "Nhap dia chi: ";
    getline(cin, address);

    string notification;

    notification = "Don hang [" + code + "] cua "
                 + customer
                 + " dang duoc giao den ["
                 + address
                 + "]. Cam on ban!";

    cout << "\n===== THONG BAO =====\n";
    cout << notification << endl;
}

// ======================================================
// MAIN
// ======================================================

int main() {

    int choice;

    do {

        cout << "\n====================================\n";
        cout << "      C++ STRING - STRUCT PRACTICE\n";
        cout << "====================================\n";

        cout << "1. Nhap va hien thi ten cua hang\n";
        cout << "2. Chuan hoa ten mon an\n";
        cout << "3. Tao ma don hang\n";
        cout << "4. Kiem tra mon an\n";
        cout << "5. Tach thong tin don hang\n";
        cout << "6. Thay doi trang thai don hang\n";
        cout << "7. Tim don hang theo ten khach\n";
        cout << "8. Rut gon dia chi\n";
        cout << "9. Thong ke mon an ban chay\n";
        cout << "10. Tao thong bao giao hang\n";
        cout << "0. Thoat\n";

        cout << "------------------------------------\n";
        cout << "Chon bai: ";
        cin >> choice;
        cin.ignore();

        cout << endl;

        switch (choice) {

            case 1:
                bai1();
                break;

            case 2:
                bai2();
                break;

            case 3:
                bai3();
                break;

            case 4:
                bai4();
                break;

            case 5:
                bai5();
                break;

            case 6:
                bai6();
                break;

            case 7:
                bai7();
                break;

            case 8:
                bai8();
                break;

            case 9:
                bai9();
                break;

            case 10:
                bai10();
                break;

            case 0:
                cout << "Thoat chuong trinh.\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}