#include "DOY.h"
#include <iostream>

using namespace std;

bool DOY::isLeap(int nam) 
{
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

int DOY::dayInMonth(int thang, int nam) 
{
    if (thang == 2) return isLeap(nam) ? 29 : 28;
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) return 30;
    return 31;
}

void DOY::Nhap() {
    cout << "Nhap ngay: "; cin >> iNgay;
    cout << "Nhap thang: "; cin >> iThang;
    cout << "Nhap nam: "; cin >> iNam;
}

void DOY::Xuat() {
    cout << iNgay << "/" << iThang << "/" << iNam << endl;
}

void DOY::NgayThangNamTiepTheo(DOY NgayTrongNam) {
    this->iNgay = NgayTrongNam.iNgay;
    this->iThang = NgayTrongNam.iThang;
    this->iNam = NgayTrongNam.iNam;

    iNgay++;

    if (iNgay > dayInMonth(iThang, iNam)) {
        iNgay = 1;
        iThang++;
    }

    if (iThang > 12) {
        iThang = 1;
        iNam++;
    }

    cout << "Ngay tiep theo la: ";
    Xuat();
}
