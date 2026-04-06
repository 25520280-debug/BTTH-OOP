#include "SoPhuc.h"
#include <iostream>

using namespace std;

int main() {
    SoPhuc sp1, sp2, kq;

    cout << "Nhap so phuc 1:\n"; sp1.Nhap();
    cout << "Nhap so phuc 2:\n"; sp2.Nhap();

    cout << "\nTong: "; kq = sp1.Tong(sp2); kq.Xuat();
    cout << "\nHieu: "; kq = sp1.Hieu(sp2); kq.Xuat();
    cout << "\nTich: "; kq = sp1.Tich(sp2); kq.Xuat();
    cout << "\nThuong: "; kq = sp1.Thuong(sp2); kq.Xuat();
    cout << endl;

    return 0;
}
