#include "KhachHang.h"
#include <algorithm>

template <typename T>
void checkNhap(T &test)
{
    while (!(cin >> test))
    {
        cout << "Loi! Xin nhap lai.\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void KH::NhapInfo()
{
    getline(cin >> ws, this->HoTen);
    checkNhap(this->SoLuongHang);
    checkNhap(this->DonGiaHang);
}

void x::TinhTien()
{
    double TongTien = this->SoLuongHang * this->DonGiaHang;
    this->VAT = TongTien * 0.1;
    this->SoTienPhaiTra = TongTien + this->VAT;
}

void y::TinhTien()
{
    double PhanTramKhuyenMai = max((double) this->SoNamThanThiet * 0.05, 0.5);
    double TongTien = this->SoLuongHang * this->DonGiaHang * (1 - PhanTramKhuyenMai);
    this->VAT = TongTien * 0.1;
    this->SoTienPhaiTra = TongTien + this->VAT;
}

void z::TinhTien()
{
    double TongTien = (this->SoLuongHang * this->DonGiaHang) * 0.5;
    this->VAT = TongTien * 0.1;
    this->SoTienPhaiTra = TongTien + this->VAT;
}

istream &operator>>(istream &in, z &p)
{
    p.NhapInfo();
    p.TinhTien();
    return in;
}

istream &operator>>(istream &in, y &p)
{
    p.NhapInfo();
    in >> p.SoNamThanThiet;
    p.TinhTien();
    return in;
}

istream &operator>>(istream &in, x &p)
{
    p.NhapInfo();
    p.TinhTien();
    return in;
}

ostream &operator<<(ostream &out, const KH &p)
{
    out << p.HoTen << '\n'
        << p.SoTienPhaiTra << '\n';
    return out;
}

double KH::getSTPT() const
{
    return this->SoTienPhaiTra;
}
