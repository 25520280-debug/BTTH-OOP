#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkLeap(int year);
int MaxDay(int month, int year);

class NhanVien
{
protected:
    string HoTen;
    int NgaySinh,
        ThangSinh,
        NamSinh;
    double Luong;

public:
    NhanVien();
    virtual ~NhanVien();
    virtual void TinhLuong() = 0;
    double getLuong() const;
    void NhapInfo();
    friend ostream &operator<<(ostream &out, const NhanVien &t);
    bool operator>(const NhanVien &other) const;
};

class NVSanXuat : public NhanVien
{
private:
    double LuongCanBan;
    int SoSanPham;

public:
    NVSanXuat();
    ~NVSanXuat();
    void TinhLuong() override;
    friend istream &operator>>(istream &in, NVSanXuat &t);
};

class NVVanPhong : public NhanVien
{
private:
    int SoNgayLamViec;

public:
    NVVanPhong();
    ~NVVanPhong();
    void TinhLuong() override;
    friend istream &operator>>(istream &in, NVVanPhong &t);
};