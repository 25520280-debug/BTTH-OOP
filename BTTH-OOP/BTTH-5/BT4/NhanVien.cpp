#include "NhanVien.h"

void NhanVien::NhapInfo()
{
    cout << "Ma: ";
    getline(cin >> ws, this->Ma);
    cout << "Ho ten: ";
    getline(cin >> ws, this->HoTen);
    cout << "So dien thoai: ";
    getline(cin >> ws, this->sdt);
    cout << "Email: ";
    getline(cin >> ws, this->email);
    cout << "Tuoi: ";
    checkNhap(this->Tuoi);
    cout << "Luong co ban: ";
    checkNhap(this->Tuoi);
}

double NhanVien::getLuong() const
{
    return this->Luong;
}

void LTV::TinhLuong()
{
    this->Luong = this->LuongCB + this->ovt * 200000;
}

void KCV::TinhLuong()
{
    this->Luong = this->LuongCB + this->err * 50000;
}

istream &operator>>(istream &in, KCV &p)
{
    p.NhapInfo();
    in >> p.err;
    p.TinhLuong();
    return in;
}

istream &operator>>(istream &in, LTV &p)
{
    p.NhapInfo();
    in >> p.ovt;
    p.TinhLuong();
    return in;
}

ostream &operator<<(ostream &out, const NhanVien &p)
{
    out << p.Ma << "\t\t" << p.Tuoi << "\t\t" << p.HoTen << "\t\t" << p.sdt << "\t\t" << p.email << "\t\t" << p.sdt << '\n';
    return out;
}
