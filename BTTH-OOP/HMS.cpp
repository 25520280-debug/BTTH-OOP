#include "HMS.h"
#include <iostream>
#include <iomanip>

using namespace std;

void ThoiGian::Nhap() {
    bool hopLe = false;
    do {
        cout << "Nhap Gio Phut Giay: ";
        if (!(cin >> iGio >> iPhut >> iGiay)) {
            cout << "Loi: Vui long nhap so nguyen!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (iGio < 0 || iGio > 23 || iPhut < 0 || iPhut > 59 || iGiay < 0 || iGiay > 59) {
            cout << "Du lieu khong hop le (Gio: 0-23, Phut/Giay: 0-59). Nhap lai!\n";
        } else {
            hopLe = true;
        }
    } while (!hopLe);
}

void ThoiGian::Xuat() {
    cout << setfill('0') << setw(2) << iGio << ":" 
         << setfill('0') << setw(2) << iPhut << ":" 
         << setfill('0') << setw(2) << iGiay;
}

void ThoiGian::TinhCongThemMotGiay() {
    iGiay++;
    if (iGiay >= 60) {
        iGiay = 0;
        iPhut++;
        if (iPhut >= 60) {
            iPhut = 0;
            iGio++;
            if (iGio >= 24) {
                iGio = 0;
            }
        }
    }
}
