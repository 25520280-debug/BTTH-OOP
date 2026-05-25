#pragma once
#include <iostream>
#include <string>
using namespace std;

class KH
{
protected:
    string HoTen;
    int SoLuongHang;
    double DonGiaHang,
        SoTienPhaiTra,
        VAT;

public:
    KH() : SoLuongHang(0), DonGiaHang(0), SoTienPhaiTra(0), VAT(0) {}
    ~KH() {}
    virtual void TinhTien() = 0;
    double getSTPT() const;
    void NhapInfo();
    friend ostream &operator<<(ostream &out, const KH &p);
};

class x : public KH
{
public:
    void TinhTien() override;
    friend istream &operator>>(istream &in, x &p);
};

class y : public KH
{
    int SoNamThanThiet;

public:
    y() : SoNamThanThiet(0) {}
    ~y() {}
    void TinhTien() override;
    friend istream &operator>>(istream &in, y &p);
};

class z : public KH
{
public:
    void TinhTien() override;
    friend istream &operator>>(istream &in, z &p);
};