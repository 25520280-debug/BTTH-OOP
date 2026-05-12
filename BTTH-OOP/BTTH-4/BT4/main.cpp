#include <iostream>
#include <iomanip>
#include "CDate.h"
using namespace std;

CDate readDate(const string& prompt) {
    CDate d;
    while (true) {
        cout << prompt << " (dd/mm/yyyy): ";
        cin >> d;
        if (!cin.fail()) break;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "  Ngay khong hop le, vui long nhap lai!\n";
    }
    cin.ignore(1000, '\n');
    return d;
}

double readPositiveDouble(const string& prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val && val > 0) break;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "  Gia tri khong hop le, vui long nhap lai!\n";
    }
    cin.ignore(1000, '\n');
    return val;
}

int main() {
    double principal = readPositiveDouble("Nhap so tien gui (VND): ");
    double annualRate = readPositiveDouble("Nhap lai suat nam (%/nam): ");
    CDate startDate = readDate("Nhap ngay gui");
    CDate endDate   = readDate("Nhap ngay rut");

    while (!(startDate < endDate)) {
        cout << "  Ngay rut phai sau ngay gui, vui long nhap lai!\n";
        endDate = readDate("Nhap ngay rut");
    }

    long long days = endDate - startDate;
    double dailyRate = annualRate / 100.0 / 365.0;
    double interest = principal * dailyRate * days;
    double total = principal + interest;

    cout << fixed << setprecision(2);
    cout << "Ngay gui       : " << startDate << "\n";
    cout << "Ngay rut       : " << endDate   << "\n";
    cout << "So ngay gui    : " << days << " ngay\n";
    cout << "So tien goc    : " << principal  << " VND\n";
    cout << "Lai suat       : " << annualRate << "%/nam\n";
    cout << "Tien lai       : " << interest   << " VND\n";
    cout << "Tong nhan duoc : " << total      << " VND\n";

    CDate d1 = startDate;
    cout << "Ngay gui + 30 ngay : " << (d1 + 30) << "\n";
    cout << "Ngay gui - 10 ngay : " << (d1 - 10) << "\n";
    cout << "Ngay gui sau ++    : " << (++d1)     << "\n";
    cout << "Ngay gui sau --    : " << (--d1)     << "\n";
    cout << "Khoang cach (ngay) : " << (endDate - startDate) << " ngay\n";

    return 0;
}
