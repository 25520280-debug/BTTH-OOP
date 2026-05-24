#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void checkNhap(T& test) {
    while (!(cin >> test)) {
        cout << "Loi! Xin nhap lai.\n\n";
        cin.clear();
        cin.ignore(10000,'\n');
    }
}

class NhanVien
{
protected:
    string  Ma,
            HoTen,
            sdt,
            email;
    int     Tuoi;
    double  LuongCB,
            Luong;

public:
    NhanVien() {}
    ~NhanVien() {}
    virtual void TinhLuong() = 0;
    void NhapInfo();
    double getLuong() const;
    friend ostream &operator<<(ostream &out, const NhanVien &p);
};

class LTV : public NhanVien
{
    double ovt;

public:
    LTV() {}
    ~LTV() {}
    void TinhLuong() override;
    friend istream &operator>>(istream &in, LTV &p);
};

class KCV : public NhanVien
{
    int err;

public:
    KCV() {}
    ~KCV() {}
    void TinhLuong() override;
    friend istream &operator>>(istream &in, KCV &p);
};