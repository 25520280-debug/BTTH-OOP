#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int gcd(int a, int b);

class PhanSo {
private:
    int tu, mau;

    /*
        Ten phuong thuc : rutGon
        ------------------------------------------------------------
        Input: Khong co (tac dong truc tiep len doi tuong hien tai).
        ------------------------------------------------------------
        Output: Phan so duoc rut gon ve dang toi gian, mau luon duong.
        ------------------------------------------------------------
        Huong giai thuat:
        - Neu mau am, dao dau ca tu va mau de mau luon duong.
        - Tinh UCLN cua |tu| va mau.
        - Chia ca tu va mau cho UCLN.
    */
    void rutGon();

public:
    /*
        Ten phuong thuc : PhanSo (mac dinh)
        ------------------------------------------------------------
        Input: Khong co.
        ------------------------------------------------------------
        Output: Phan so 0/1.
    */
    PhanSo();

    /*
        Ten phuong thuc : PhanSo (tu so nguyen)
        ------------------------------------------------------------
        Input: So nguyen nguyen.
        ------------------------------------------------------------
        Output: Phan so nguyen/1.
    */
    PhanSo(int nguyen);

    /*
        Ten phuong thuc : PhanSo (tu tu va mau)
        ------------------------------------------------------------
        Input: Tu so t va mau so m.
        ------------------------------------------------------------
        Output: Phan so t/m da rut gon. Loi neu m = 0.
        ------------------------------------------------------------
        Huong giai thuat:
        - Kiem tra mau = 0, nem ngoai le neu sai.
        - Gan tu, mau roi goi rutGon().
    */
    PhanSo(int t, int m);

    /*
        Ten phuong thuc : operator+
        ------------------------------------------------------------
        Input: Phan so hien tai va phan so other.
        ------------------------------------------------------------
        Output: Tong hai phan so da rut gon.
        ------------------------------------------------------------
        Huong giai thuat:
        - Quy dong mau: (tu*other.mau + other.tu*mau) / (mau*other.mau).
    */
    PhanSo operator+(const PhanSo& other) const;

    /*
        Ten phuong thuc : operator-
        ------------------------------------------------------------
        Input: Phan so hien tai va phan so other.
        ------------------------------------------------------------
        Output: Hieu hai phan so da rut gon.
        ------------------------------------------------------------
        Huong giai thuat:
        - Quy dong mau: (tu*other.mau - other.tu*mau) / (mau*other.mau).
    */
    PhanSo operator-(const PhanSo& other) const;

    /*
        Ten phuong thuc : operator*
        ------------------------------------------------------------
        Input: Phan so hien tai va phan so other.
        ------------------------------------------------------------
        Output: Tich hai phan so da rut gon.
        ------------------------------------------------------------
        Huong giai thuat:
        - Nhan thang: (tu*other.tu) / (mau*other.mau).
    */
    PhanSo operator*(const PhanSo& other) const;

    /*
        Ten phuong thuc : operator/
        ------------------------------------------------------------
        Input: Phan so hien tai va phan so other.
        ------------------------------------------------------------
        Output: Thuong hai phan so da rut gon. Loi neu other = 0.
        ------------------------------------------------------------
        Huong giai thuat:
        - Kiem tra other.tu = 0, nem ngoai le neu sai.
        - Nhan nguoc: (tu*other.mau) / (mau*other.tu).
    */
    PhanSo operator/(const PhanSo& other) const;

    /*
        Ten phuong thuc : operator==
        ------------------------------------------------------------
        Input: Phan so hien tai va phan so other.
        ------------------------------------------------------------
        Output: true neu hai phan so bang nhau, false neu khac.
        ------------------------------------------------------------
        Huong giai thuat:
        - So sanh cheo: tu*other.mau == other.tu*mau.
    */
    bool operator==(const PhanSo& other) const;

    /*
        Ten phuong thuc : operator>
        ------------------------------------------------------------
        Input: Phan so hien tai va phan so other.
        ------------------------------------------------------------
        Output: true neu phan so hien tai lon hon other, false neu khong.
        ------------------------------------------------------------
        Huong giai thuat:
        - So sanh cheo: tu*other.mau > other.tu*mau.
    */
    bool operator>(const PhanSo& other) const;

    /*
        Ten phuong thuc : operator<
        ------------------------------------------------------------
        Input: Phan so hien tai va phan so other.
        ------------------------------------------------------------
        Output: true neu phan so hien tai nho hon other, false neu khong.
        ------------------------------------------------------------
        Huong giai thuat:
        - So sanh cheo: tu*other.mau < other.tu*mau.
    */
    bool operator<(const PhanSo& other) const;

    /*
        Ten phuong thuc : operator<<
        ------------------------------------------------------------
        Input: Doi tuong ostream va phan so ps.
        ------------------------------------------------------------
        Output: Xuat phan so ra luong: "tu/mau" hoac "tu" neu mau = 1.
    */
    friend ostream& operator<<(ostream& os, const PhanSo& ps);

    /*
        Ten phuong thuc : operator>>
        ------------------------------------------------------------
        Input: Doi tuong istream va phan so ps.
        ------------------------------------------------------------
        Output: Doc phan so dinh dang "tu/mau" tu luong nhap. Loi neu sai dinh dang hoac mau = 0.
    */
    friend istream& operator>>(istream& is, PhanSo& ps);
};