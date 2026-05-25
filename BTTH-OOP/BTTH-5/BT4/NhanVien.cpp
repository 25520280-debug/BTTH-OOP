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
    while (true)
    {
        cout << "Tuoi: ";
        checkNhap(this->Tuoi);
        if (this->Tuoi > 0)
            break;
        cout << "Loi! Xin nhap lai.\n\n";
    }
    while (true)
    {
        cout << "Luong co ban: ";
        checkNhap(this->LuongCB);
        if (this->LuongCB >= 0)
            break;
        cout << "Loi! Xin nhap lai.\n\n";
    }
}

istream &operator>>(istream &in, KCV &p)
{
    p.NhapInfo();
    while (true)
    {
        cout << "So loi tim duoc: ";
        in >> p.err;
        if (p.err >= 0)
            break;
        cout << "Loi! Xin nhap lai.\n\n";
    }
    p.TinhLuong();
    return in;
}

istream &operator>>(istream &in, LTV &p)
{
    p.NhapInfo();
    while (true)
    {
        cout << "So gio tang ca: ";
        in >> p.ovt;
        if (p.ovt >= 0)
            break;
        cout << "Loi! Xin nhap lai.\n\n";
    }
    p.TinhLuong();
    return in;
}

ostream &operator<<(ostream &out, const NhanVien &p)
{
    out << p.Ma << "\t\t" << p.HoTen << "\t\t" << p.Tuoi << "\t\t" << p.sdt << "\t\t" << p.email;
    return out;
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