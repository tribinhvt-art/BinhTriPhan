#include <iostream>
#include <string>
using namespace std;

struct Shop
{
    struct Mobile
    {
        string id;
        string branch;
        string version;
        int year;
    };

    struct Order
    {
        string paymentStatus;
        string id;
        int month;
    };

    Mobile mobiles[100];
    Order orders[100];

    int mobileCount = 0;
    int orderCount = 0;

    // 1. Thêm điện thoại mới
    void addMobile()
    {
        cout << "Nhap ID: ";
        cin >> mobiles[mobileCount].id;

        cout << "Nhap branch: ";
        cin >> mobiles[mobileCount].branch;

        cout << "Nhap version: ";
        cin >> mobiles[mobileCount].version;

        cout << "Nhap year: ";
        cin >> mobiles[mobileCount].year;

        mobileCount++;
    }

    // 2. Xóa điện thoại
    void deleteMobile()
    {
        string id;
        cout << "Nhap ID mobile can xoa: ";
        cin >> id;

        int pos = -1;

        for (int i = 0; i < mobileCount; i++)
        {
            if (mobiles[i].id == id)
            {
                pos = i;
                break;
            }
        }

        if (pos == -1)
        {
            cout << "Mobile khong ton tai!\n";
            return;
        }

        for (int i = pos; i < mobileCount - 1; i++)
        {
            mobiles[i] = mobiles[i + 1];
        }

        mobileCount--;

        cout << "Xoa thanh cong!\n";
    }

    // 3. Thêm order
    void addOrder()
    {
        cout << "Nhap Order ID: ";
        cin >> orders[orderCount].id;

        cout << "Nhap payment status: ";
        cin >> orders[orderCount].paymentStatus;

        cout << "Nhap month: ";
        cin >> orders[orderCount].month;

        orderCount++;
    }

    // 4. Sửa order
    void editOrder()
    {
        string id;

        cout << "Nhap Order ID can sua: ";
        cin >> id;

        for (int i = 0; i < orderCount; i++)
        {
            if (orders[i].id == id)
            {
                cout << "Nhap payment status moi: ";
                cin >> orders[i].paymentStatus;

                cout << "Nhap month moi: ";
                cin >> orders[i].month;

                cout << "Sua thanh cong!\n";
                return;
            }
        }

        cout << "Order khong ton tai!\n";
    }

    // 5. Thêm order theo tháng
    void addOrderByMonth(int month)
    {
        cout << "Nhap Order ID: ";
        cin >> orders[orderCount].id;

        cout << "Nhap payment status: ";
        cin >> orders[orderCount].paymentStatus;

        orders[orderCount].month = month;

        orderCount++;
    }
};

int main()
{
    Shop shop;

    shop.addMobile();
    shop.deleteMobile();

    shop.addOrder();
    shop.editOrder();

    shop.addOrderByMonth(9);

    return 0;
}