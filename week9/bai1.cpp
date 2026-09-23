#include <iostream>
#include <string>
using namespace std;

struct restaurent {

    // =========================
    // STRUCT FOOD
    // =========================
    struct food {
        string id;
        string name;
        double price;
        int so_luong;
    };

    // =========================
    // STRUCT ORDER
    // =========================
    struct order {
        string id;
        string tenkhach;
        string dia_chi;
        string mon_an;
        int so_luongconlai;
        string trang_thai;
    };

    // =========================
    // THONG TIN CUA HANG
    // =========================
    string name;
    string address;
    string phone;

    food mon_an[100];
    order orders[100];

    int foodcount = 0;
    int ordercount = 0;


    // =====================================================
    // 1. NHAP THONG TIN CUA HANG
    // =====================================================
    void nhap_thong_tin() {

        cout << "\n===== NHAP THONG TIN CUA HANG =====\n";

        cout << "Nhap ten cua hang: ";
        cin >> name;

        cout << "Nhap dia chi cua hang: ";
        cin >> address;

        cout << "Nhap so dien thoai: ";
        cin >> phone;
    }


    // =====================================================
    // 2. THEM MON AN MOI
    // =====================================================
    void them_mon_an() {

        if (foodcount >= 100) {
            cout << "Danh sach mon an da day!\n";
            return;
        }

        cout << "\n===== THEM MON AN =====\n";

        cout << "Nhap ID mon: ";
        cin >> mon_an[foodcount].id;

        cout << "Nhap ten mon: ";
        cin >> mon_an[foodcount].name;

        cout << "Nhap gia mon: ";
        cin >> mon_an[foodcount].price;

        cout << "Nhap so luong: ";
        cin >> mon_an[foodcount].so_luong;

        foodcount++;

        cout << "Them mon an thanh cong!\n";
    }


    // =====================================================
    // 3. HIEN THI DANH SACH MON AN
    // =====================================================
    void hien_thi_danh_sach() {

        cout << "\n========== DANH SACH MON AN ==========\n";

        if (foodcount == 0) {
            cout << "Chua co mon an nao.\n";
            return;
        }

        for (int i = 0; i < foodcount; i++) {

            cout << "\n-----------------------------\n";
            cout << "ID: " << mon_an[i].id << endl;
            cout << "Ten mon: " << mon_an[i].name << endl;
            cout << "Gia: " << mon_an[i].price << endl;
            cout << "So luong: " << mon_an[i].so_luong << endl;
        }
    }


    // =====================================================
    // HAM TIM VI TRI MON AN
    // Tim theo ID HOAC ten
    // =====================================================
    int tim_vi_tri_mon_an(string keyword) {

        for (int i = 0; i < foodcount; i++) {

            if (mon_an[i].id == keyword ||
                mon_an[i].name == keyword) {

                return i;
            }
        }

        return -1;
    }


    // =====================================================
    // 4. TIM MON AN THEO MA HOAC TEN
    // =====================================================
    void tim_mon_an_theo_ma_hoac_ten() {

        string keyword;

        cout << "\n===== TIM MON AN =====\n";
        cout << "Nhap ID hoac ten mon: ";
        cin >> keyword;

        int vitri = tim_vi_tri_mon_an(keyword);

        if (vitri == -1) {

            cout << "Khong tim thay mon an!\n";
            return;
        }

        cout << "\nTim thay mon an:\n";
        cout << "ID: " << mon_an[vitri].id << endl;
        cout << "Ten mon: " << mon_an[vitri].name << endl;
        cout << "Gia: " << mon_an[vitri].price << endl;
        cout << "So luong: " << mon_an[vitri].so_luong << endl;
    }


    // =====================================================
    // 5. CAP NHAT GIA HOAC SO LUONG
    // =====================================================
    void cap_nhat_gia() {

        string keyword;

        cout << "\n===== CAP NHAT MON AN =====\n";
        cout << "Nhap ID hoac ten mon: ";
        cin >> keyword;

        int vitri = tim_vi_tri_mon_an(keyword);

        if (vitri == -1) {

            cout << "Khong tim thay mon an!\n";
            return;
        }

        cout << "\nMon an hien tai:\n";
        cout << "Ten: " << mon_an[vitri].name << endl;
        cout << "Gia: " << mon_an[vitri].price << endl;
        cout << "So luong: " << mon_an[vitri].so_luong << endl;

        cout << "\nNhap gia moi: ";
        cin >> mon_an[vitri].price;

        cout << "Nhap so luong moi: ";
        cin >> mon_an[vitri].so_luong;

        cout << "Cap nhat thanh cong!\n";
    }


    // =====================================================
    // 6. TAO DON HANG MOI
    // =====================================================
    void don_hang_moi() {

        if (ordercount >= 100) {
            cout << "Danh sach don hang da day!\n";
            return;
        }

        cout << "\n===== TAO DON HANG MOI =====\n";

        cout << "Nhap ID don hang: ";
        cin >> orders[ordercount].id;

        cout << "Nhap ten khach hang: ";
        cin >> orders[ordercount].tenkhach;

        cout << "Nhap dia chi: ";
        cin >> orders[ordercount].dia_chi;

        cout << "Nhap ID hoac ten mon an: ";
        cin >> orders[ordercount].mon_an;

        // Tim mon
        int vitri = tim_vi_tri_mon_an(orders[ordercount].mon_an);

        if (vitri == -1) {

            cout << "Mon an khong ton tai!\n";
            return;
        }

        cout << "Nhap so luong: ";
        cin >> orders[ordercount].so_luongconlai;

        // Kiem tra so luong
        if (orders[ordercount].so_luongconlai <= 0) {

            cout << "So luong khong hop le!\n";
            return;
        }

        if (orders[ordercount].so_luongconlai >
            mon_an[vitri].so_luong) {

            cout << "Khong du mon an trong kho!\n";
            cout << "So luong hien co: "
                 << mon_an[vitri].so_luong << endl;

            return;
        }

        // Tru so luong mon an
        mon_an[vitri].so_luong -=
            orders[ordercount].so_luongconlai;

        // Trang thai mac dinh
        orders[ordercount].trang_thai = "Cho xac nhan";

        ordercount++;

        cout << "Tao don hang thanh cong!\n";
    }


    // =====================================================
    // 7. KIEM TRA MON AN CO TON TAI VA DU SO LUONG
    // =====================================================
    void kiemtramonan() {

        string keyword;
        int soluong;

        cout << "\n===== KIEM TRA MON AN =====\n";

        cout << "Nhap ID hoac ten mon: ";
        cin >> keyword;

        int vitri = tim_vi_tri_mon_an(keyword);

        if (vitri == -1) {

            cout << "Mon an khong ton tai!\n";
            return;
        }

        cout << "Mon an ton tai!\n";
        cout << "So luong hien co: "
             << mon_an[vitri].so_luong << endl;

        cout << "Nhap so luong can mua: ";
        cin >> soluong;

        if (soluong <= mon_an[vitri].so_luong) {

            cout << "Du so luong de dat hang.\n";

        } else {

            cout << "Khong du so luong.\n";
        }
    }


    // =====================================================
    // 8. TINH TONG TIEN CUA MOT DON HANG
    // =====================================================
    void tongtiencuadonhang() {

        string id_don;

        cout << "\n===== TINH TONG TIEN DON HANG =====\n";

        cout << "Nhap ID don hang: ";
        cin >> id_don;

        for (int i = 0; i < ordercount; i++) {

            if (orders[i].id == id_don) {

                int vitri =
                    tim_vi_tri_mon_an(orders[i].mon_an);

                if (vitri == -1) {

                    cout << "Khong tim thay mon trong don hang!\n";
                    return;
                }

                double tongtien =
                    mon_an[vitri].price *
                    orders[i].so_luongconlai;

                cout << "Don hang: "
                     << orders[i].id << endl;

                cout << "Mon: "
                     << mon_an[vitri].name << endl;

                cout << "So luong: "
                     << orders[i].so_luongconlai << endl;

                cout << "Don gia: "
                     << mon_an[vitri].price << endl;

                cout << "Tong tien: "
                     << tongtien << endl;

                return;
            }
        }

        cout << "Khong tim thay don hang!\n";
    }


    // =====================================================
    // 9. HIEN THI DANH SACH DON HANG
    // =====================================================
    void hien_thi_danh_sach_don_hang() {

        cout << "\n========== DANH SACH DON HANG ==========\n";

        if (ordercount == 0) {

            cout << "Chua co don hang nao.\n";
            return;
        }

        for (int i = 0; i < ordercount; i++) {

            cout << "\n-----------------------------\n";

            cout << "ID don hang: "
                 << orders[i].id << endl;

            cout << "Khach hang: "
                 << orders[i].tenkhach << endl;

            cout << "Dia chi: "
                 << orders[i].dia_chi << endl;

            cout << "Mon an: "
                 << orders[i].mon_an << endl;

            cout << "So luong: "
                 << orders[i].so_luongconlai << endl;

            cout << "Trang thai: "
                 << orders[i].trang_thai << endl;
        }
    }


    // =====================================================
    // 10. TIM DON HANG THEO MA
    // =====================================================
    void tim_don_hang_theo_ma() {

        string id;

        cout << "\n===== TIM DON HANG =====\n";

        cout << "Nhap ID don hang: ";
        cin >> id;

        for (int i = 0; i < ordercount; i++) {

            if (orders[i].id == id) {

                cout << "\nTim thay don hang:\n";

                cout << "ID: "
                     << orders[i].id << endl;

                cout << "Khach hang: "
                     << orders[i].tenkhach << endl;

                cout << "Dia chi: "
                     << orders[i].dia_chi << endl;

                cout << "Mon an: "
                     << orders[i].mon_an << endl;

                cout << "So luong: "
                     << orders[i].so_luongconlai << endl;

                cout << "Trang thai: "
                     << orders[i].trang_thai << endl;

                return;
            }
        }

        cout << "Khong tim thay don hang!\n";
    }


    // =====================================================
    // 11. CAP NHAT TRANG THAI DON HANG
    // =====================================================
    void cap_nhat_trang_thai() {

        string id;

        cout << "\n===== CAP NHAT TRANG THAI =====\n";

        cout << "Nhap ID don hang: ";
        cin >> id;

        for (int i = 0; i < ordercount; i++) {

            if (orders[i].id == id) {

                cout << "Trang thai hien tai: "
                     << orders[i].trang_thai << endl;

                cout << "\nNhap trang thai moi:\n";
                cout << "1. Cho xac nhan\n";
                cout << "2. Dang giao\n";
                cout << "3. Da giao\n";
                cout << "4. Da huy\n";

                int choice;
                cin >> choice;

                if (choice == 1) {
                    orders[i].trang_thai = "Cho xac nhan";
                }
                else if (choice == 2) {
                    orders[i].trang_thai = "Dang giao";
                }
                else if (choice == 3) {
                    orders[i].trang_thai = "Da giao";
                }
                else if (choice == 4) {
                    orders[i].trang_thai = "Da huy";
                }
                else {
                    cout << "Lua chon khong hop le!\n";
                    return;
                }

                cout << "Cap nhat thanh cong!\n";

                return;
            }
        }

        cout << "Khong tim thay don hang!\n";
    }


    // =====================================================
    // 12. THONG KE DOANH THU CAC DON DA HOAN THANH
    // =====================================================
    void thong_ke_doanh_thu() {

        double doanhthu = 0;

        cout << "\n===== THONG KE DOANH THU =====\n";

        for (int i = 0; i < ordercount; i++) {

            if (orders[i].trang_thai == "Da giao") {

                int vitri =
                    tim_vi_tri_mon_an(orders[i].mon_an);

                if (vitri != -1) {

                    doanhthu +=
                        mon_an[vitri].price *
                        orders[i].so_luongconlai;
                }
            }
        }

        cout << "Tong doanh thu cac don da giao: "
             << doanhthu << endl;
    }
};


// =========================================================
// MAIN
// =========================================================

int main() {

    restaurent shop;

    int choice;

    do {

        cout << "\n\n========================================\n";
        cout << "     QUAN LY CUA HANG GIAO DO AN\n";
        cout << "========================================\n";

        cout << "1. Nhap thong tin cua hang\n";
        cout << "2. Them mon an moi\n";
        cout << "3. Hien thi danh sach mon an\n";
        cout << "4. Tim mon an theo ma hoac ten\n";
        cout << "5. Cap nhat gia / so luong mon an\n";
        cout << "6. Tao don hang moi\n";
        cout << "7. Kiem tra mon an\n";
        cout << "8. Tinh tong tien don hang\n";
        cout << "9. Hien thi danh sach don hang\n";
        cout << "10. Tim don hang theo ma\n";
        cout << "11. Cap nhat trang thai don hang\n";
        cout << "12. Thong ke doanh thu\n";
        cout << "0. Thoat\n";

        cout << "\nNhap lua chon: ";
        cin >> choice;

        switch (choice) {

            case 1:
                shop.nhap_thong_tin();
                break;

            case 2:
                shop.them_mon_an();
                break;

            case 3:
                shop.hien_thi_danh_sach();
                break;

            case 4:
                shop.tim_mon_an_theo_ma_hoac_ten();
                break;

            case 5:
                shop.cap_nhat_gia();
                break;

            case 6:
                shop.don_hang_moi();
                break;

            case 7:
                shop.kiemtramonan();
                break;

            case 8:
                shop.tongtiencuadonhang();
                break;

            case 9:
                shop.hien_thi_danh_sach_don_hang();
                break;

            case 10:
                shop.tim_don_hang_theo_ma();
                break;

            case 11:
                shop.cap_nhat_trang_thai();
                break;

            case 12:
                shop.thong_ke_doanh_thu();
                break;

            case 0:
                cout << "Thoat chuong trinh!\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}