
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ==================== STAFF MANAGEMENT ====================
class Staff {
private:
    string identityNumber;
    string contactNumber;
    string residence;

public:
    Staff() : identityNumber(""), contactNumber(""), residence("") {}

    Staff(string id, string phone, string address)
        : identityNumber(id), contactNumber(phone), residence(address) {}

    string getIdentityNumber() const {
        return identityNumber;
    }

    string getContactNumber() const {
        return contactNumber;
    }

    string getResidence() const {
        return residence;
    }

    void setIdentityNumber(string id) {
        identityNumber = id;
    }

    void setContactNumber(string phone) {
        contactNumber = phone;
    }

    void setResidence(string address) {
        residence = address;
    }

    virtual double salaryFor(int month, int year) = 0;

    virtual void showStaff() const {
        cout << "Identity number: " << identityNumber << endl;
        cout << "Contact number: " << contactNumber << endl;
        cout << "Residence: " << residence << endl;
    }

    virtual ~Staff() = default;
};

// ==================== HOURLY STAFF ====================
class HourlyStaff : public Staff {
private:
    int hoursCompleted;
    double ratePerHour;
    int salaryMonth;
    int salaryYear;

public:
    HourlyStaff()
        : Staff(), hoursCompleted(0), ratePerHour(0),
          salaryMonth(0), salaryYear(0) {}

    HourlyStaff(string id, string phone, string address,
                int hours, double rate, int month, int year)
        : Staff(id, phone, address),
          hoursCompleted(hours),
          ratePerHour(rate),
          salaryMonth(month),
          salaryYear(year) {}

    int getHoursCompleted() const {
        return hoursCompleted;
    }

    double getRatePerHour() const {
        return ratePerHour;
    }

    int getSalaryMonth() const {
        return salaryMonth;
    }

    int getSalaryYear() const {
        return salaryYear;
    }

    void setHoursCompleted(int hours) {
        hoursCompleted = hours;
    }

    void setRatePerHour(double rate) {
        ratePerHour = rate;
    }

    void setSalaryMonth(int month) {
        salaryMonth = month;
    }

    void setSalaryYear(int year) {
        salaryYear = year;
    }

    double salaryFor(int month, int year) override {
        if (month == salaryMonth && year == salaryYear) {
            return hoursCompleted * ratePerHour;
        }

        return 0;
    }

    void showStaff() const override {
        cout << "\n--- HOURLY STAFF ---\n";
        Staff::showStaff();

        cout << "Hours completed: " << hoursCompleted << endl;
        cout << "Rate per hour: " << ratePerHour << endl;
        cout << "Salary period: "
             << salaryMonth << "/" << salaryYear << endl;
    }
};

// ==================== MONTHLY STAFF ====================
class MonthlyStaff : public Staff {
private:
    double fixedPay;
    int salaryMonth;
    int salaryYear;

public:
    MonthlyStaff()
        : Staff(), fixedPay(0), salaryMonth(0), salaryYear(0) {}

    MonthlyStaff(string id, string phone, string address,
                 double pay, int month, int year)
        : Staff(id, phone, address),
          fixedPay(pay),
          salaryMonth(month),
          salaryYear(year) {}

    double getFixedPay() const {
        return fixedPay;
    }

    int getSalaryMonth() const {
        return salaryMonth;
    }

    int getSalaryYear() const {
        return salaryYear;
    }

    void setFixedPay(double pay) {
        fixedPay = pay;
    }

    void setSalaryMonth(int month) {
        salaryMonth = month;
    }

    void setSalaryYear(int year) {
        salaryYear = year;
    }

    double salaryFor(int month, int year) override {
        if (month == salaryMonth && year == salaryYear) {
            return fixedPay;
        }

        return 0;
    }

    void showStaff() const override {
        cout << "\n--- MONTHLY STAFF ---\n";
        Staff::showStaff();

        cout << "Fixed pay: " << fixedPay << endl;
        cout << "Salary period: "
             << salaryMonth << "/" << salaryYear << endl;
    }
};

// ==================== DAILY STAFF ====================
class DailyStaff : public Staff {
private:
    int daysCompleted;
    double ratePerDay;
    int salaryMonth;
    int salaryYear;

public:
    DailyStaff()
        : Staff(), daysCompleted(0), ratePerDay(0),
          salaryMonth(0), salaryYear(0) {}

    DailyStaff(string id, string phone, string address,
               int days, double rate, int month, int year)
        : Staff(id, phone, address),
          daysCompleted(days),
          ratePerDay(rate),
          salaryMonth(month),
          salaryYear(year) {}

    int getDaysCompleted() const {
        return daysCompleted;
    }

    double getRatePerDay() const {
        return ratePerDay;
    }

    int getSalaryMonth() const {
        return salaryMonth;
    }

    int getSalaryYear() const {
        return salaryYear;
    }

    void setDaysCompleted(int days) {
        daysCompleted = days;
    }

    void setRatePerDay(double rate) {
        ratePerDay = rate;
    }

    void setSalaryMonth(int month) {
        salaryMonth = month;
    }

    void setSalaryYear(int year) {
        salaryYear = year;
    }

    double salaryFor(int month, int year) override {
        if (month == salaryMonth && year == salaryYear) {
            return daysCompleted * ratePerDay;
        }

        return 0;
    }

    void showStaff() const override {
        cout << "\n--- DAILY STAFF ---\n";
        Staff::showStaff();

        cout << "Days completed: " << daysCompleted << endl;
        cout << "Rate per day: " << ratePerDay << endl;
        cout << "Salary period: "
             << salaryMonth << "/" << salaryYear << endl;
    }
};

// ==================== PAYROLL REPORTS ====================
void reportMonthlyPayroll(
    Staff* staffMembers[],
    int memberCount,
    int month,
    int year
) {
    double monthTotal = 0;

    cout << "\n========== MONTHLY PAYROLL ==========\n";
    cout << "Month/Year: " << month << "/" << year << "\n\n";

    for (int i = 0; i < memberCount; i++) {
        double amount = staffMembers[i]->salaryFor(month, year);

        cout << "Staff " << i + 1 << ": "
             << amount << " VND\n";

        monthTotal += amount;
    }

    cout << "Total monthly salary: "
         << monthTotal << " VND\n";
}

double calculateYearlyPayroll(
    Staff* staffMembers[],
    int memberCount,
    int year
) {
    double yearTotal = 0;

    for (int i = 0; i < memberCount; i++) {
        for (int month = 1; month <= 12; month++) {
            yearTotal += staffMembers[i]->salaryFor(month, year);
        }
    }

    return yearTotal;
}

// ==================== MAIN ====================
int main() {
    cout << fixed << setprecision(0);

    // Create staff records
    HourlyStaff staffA(
        "001", "0901", "HCM",
        160, 50000, 10, 2026
    );

    MonthlyStaff staffB(
        "002", "0902", "Dong Nai",
        15000000, 10, 2026
    );

    DailyStaff staffC(
        "003", "0903", "Ha Noi",
        22, 400000, 10, 2026
    );

    Staff* staffMembers[] = {
        &staffA,
        &staffB,
        &staffC
    };

    int memberCount = 3;

    // Display staff information
    cout << "========== STAFF INFORMATION ==========\n";

    for (int i = 0; i < memberCount; i++) {
        staffMembers[i]->showStaff();
    }

    // Monthly salary report
    int selectedMonth = 10;
    int selectedYear = 2026;

    reportMonthlyPayroll(
        staffMembers,
        memberCount,
        selectedMonth,
        selectedYear
    );

    // Yearly salary report
    cout << "\n========== YEARLY PAYROLL ==========\n";

    int reportYear = 2026;

    cout << "Total yearly salary for " << reportYear << ": "
         << calculateYearlyPayroll(
                staffMembers,
                memberCount,
                reportYear
            )
         << " VND\n";

    return 0;
}
    