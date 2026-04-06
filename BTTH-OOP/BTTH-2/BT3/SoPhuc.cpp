#include "SoPhuc.h"
#include <iostream>
#include <cmath>

using namespace std;

void SoPhuc::Nhap() {
    while (true) {
        cout << "Nhap phan thuc va phan ao: ";
        if (cin >> iThuc >> iAo) {
            break; 
        } else {
            cout << "Du lieu khong hop le! Vui long nhap so thuc.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

void SoPhuc::Xuat() {
    if (iAo >= 0)
        cout << iThuc << " + " << iAo << "i";
    else
        cout << iThuc << " - " << abs(iAo) << "i";
}

SoPhuc SoPhuc::Tong(SoPhuc b) {
    SoPhuc res;
    res.iThuc = iThuc + b.iThuc;
    res.iAo = iAo + b.iAo;
    return res;
}

SoPhuc SoPhuc::Hieu(SoPhuc b) {
    SoPhuc res;
    res.iThuc = iThuc - b.iThuc;
    res.iAo = iAo - b.iAo;
    return res;
}

SoPhuc SoPhuc::Tich(SoPhuc b) {
    SoPhuc res;
    res.iThuc = iThuc * b.iThuc - iAo * b.iAo;
    res.iAo = iThuc * b.iAo + iAo * b.iThuc;
    return res;
}

SoPhuc SoPhuc::Thuong(SoPhuc b) {
    SoPhuc res;
    float mau = b.iThuc * b.iThuc + b.iAo * b.iAo;
    if (mau == 0) {
        cout << "Loi: Mau so bang ";
        res.iThuc = 0; res.iAo = 0;
    } else {
        res.iThuc = (iThuc * b.iThuc + iAo * b.iAo) / mau;
        res.iAo = (iAo * b.iThuc - iThuc * b.iAo) / mau;
    }
    return res;
}
