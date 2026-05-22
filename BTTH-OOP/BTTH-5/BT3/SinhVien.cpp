#include "SinhVien.h"

void SV::NhapInfo()
{
    cout << "Nhap MSSV: ";
    getline(cin >> ws, this->MSSV);
    cout << "Nhap ho ten: ";
    getline(cin >> ws, this->HoTen);
    cout << "Nhap dia chi: ";
    getline(cin >> ws, this->DiaChi);
    while (true)
    {
        cout << "Nhap tong so tin chi: ";
        checkInput(this->TinChi);
        if (this->TinChi >= 0)
            break;
        cout << "Loi! Xin nhap lai.\n\n";
    }
    while (true)
    {
        cout << "Nhap diem trung binh: ";
        checkInput(this->DTB);
        if (this->DTB >= 0 && this->DTB <= 10)
            break;
        cout << "Loi! Xin nhap lai.\n\n";
    }
}

CD::CD() : DTN(0) {}

CD::~CD() {}

ostream &operator<<(ostream &out, const SV &p)
{
    out << p.MSSV << "\t\t" << p.HoTen << "\t\t" << p.DiaChi << "\n";
    return out;
}

bool CD::DKTN() const
{
    if (this->TinChi >= 120 && this->DTB >= 5 && this->DTN >= 5)
        return true;
    else
        return false;
}

DH::DH() : diemLV(0) {}

DH::~DH() {}

bool DH::DKTN() const
{
    if (this->TinChi >= 170 && this->DTB >= 5 && this->diemLV >= 5)
        return true;
    else
        return false;
}

istream &operator>>(istream &in, DH &p)
{
    p.NhapInfo();
    cout << "Nhap ten luan van: ";
    getline(in >> ws, p.tenLV);
    while (true)
    {
        cout << "Nhap diem luan van: ";
        checkInput(p.diemLV);
        if (p.diemLV >= 0 && p.diemLV <= 10)
            break;
        cout << "Loi! Xin nhap lai.\n\n";
    }
    return in;
}

istream &operator>>(istream &in, CD &p)
{
    p.NhapInfo();
    while (true)
    {
        cout << "Nhap diem thi tot nghiep: ";
        checkInput(p.DTN);
        if (p.DTN >= 0 && p.DTN <= 10)
            break;
        cout << "Loi! Xin nhap lai.\n\n";
    }
    return in;
}

SV::SV() : TinChi(0), DTB(0) {}

double SV::getDTB() const
{
    return this->DTB;
}
