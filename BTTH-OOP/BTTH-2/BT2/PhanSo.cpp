#include "PhanSo.h"
#include <iostream>
#include <cmath>
using namespace std;

int PhanSo::GCD(int a, int b) {
    return b == 0 ? abs(a) : GCD(b, a % b);
}

void PhanSo::Nhap() {
    cout << "Nhap tu: "; cin >> iTu;
    do {
        cout << "Nhap mau (khac 0): "; cin >> iMau;
    } while (iMau == 0);
}

void PhanSo::RutGon() {
    int common = GCD(iTu, iMau);
    iTu /= common;
    iMau /= common;
    if (iMau < 0) { iTu = -iTu; iMau = -iMau; }
}

PhanSo PhanSo::Tong(PhanSo b) {
    PhanSo res;
    res.iTu = iTu * b.iMau + b.iTu * iMau;
    res.iMau = iMau * b.iMau;
    res.RutGon();
    return res;
}

PhanSo PhanSo::Hieu(PhanSo b) {
    PhanSo res;
    res.iTu = iTu * b.iMau - b.iTu * iMau;
    res.iMau = iMau * b.iMau;
    res.RutGon();
    return res;
}

PhanSo PhanSo::Tich(PhanSo b) {
    PhanSo res;
    res.iTu = iTu * b.iTu;
    res.iMau = iMau * b.iMau;
    res.RutGon();
    return res;
}

PhanSo PhanSo::Thuong(PhanSo b) {
    PhanSo res;
    if (b.iTu == 0) {
        cout << "Loi: Khong the chia cho ";
        res.iTu = 0; res.iMau = 1;
    } else {
        res.iTu = iTu * b.iMau;
        res.iMau = iMau * b.iTu;
        res.RutGon();
    }
    return res;
}


int PhanSo::SoSanh(PhanSo b) {
    int VT = iTu * b.iMau;
    int VP = b.iTu * iMau;
    
    if (VT > VP) return 1;
    if (VT < VP) return -1;
    return 0;
}

void PhanSo::Xuat() {
    if (iMau == 1) cout << iTu;
    else if (iTu == 0) cout << 0;
    else cout << iTu << "/" << iMau;
}
