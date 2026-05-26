#include "GD.h"

template <typename T>
bool checkInput(T &test)
{
    while (!(cin >> test))
    {
        cout << "Error! Please try again.\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.ignore(10000,'\n');
    return true;
}

bool checkLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}

int MaxDay(int month, int year)
{
    switch (month)
    {
    case 2:
        if (checkLeap(year))
            return 29;
        else
            return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    default:
        return 30;
    }
}

void GD::NhapInfo()
{
    cout << "Nhap ma giao dich: ";
    getline(cin >> ws, this->MaGD);
    cout << "Nhap nam: ";
    while (true) {checkInput(this->Nam);
    if (this->Nam > 0) break; }
    cout << "Nhap thang: ";

    while (true) {checkInput(this->Thang);
    if (this->Thang > 0 && this->Thang <= 12)break;}
    cout << "Nhap ngay: ";
    do checkInput(this->Ngay);
    while (this->Ngay <= 0 ||
           this->Ngay > MaxDay(this->Thang, this->Nam));
    cout << "Nhap dien tich: ";
    while (true)
    {checkInput(this->S);
    if (this->S >= 0) break;}
    cout << "Nhap gia: ";
    while (true) {checkInput(this->Gia);
    if (this->Gia >= 0) break;}
}

void Dat::TinhTien()
{
    while (true)
    {
        if (this->type == 'A')
        {
            this->Tien = this->S * this->Gia;
            break;
        }
        else if (this->type == 'B' || this->type == 'C')
        {
            this->Tien = this->S * this->Gia * 1.5;
            break;
        }
    }
}

void Nha::TinhTien()
{
    if (this->type == "cao cap")
    {
        this->Tien = this->S * this->Gia;
    }
    else
    {
        this->Tien = this->S * this->Gia * 0.9;
    }
}

void CC::TinhTien()
{
    if (this->VTT == 1)
    {
        this->Tien = this->S * this->Gia * 2;
    }
    else if (this->VTT >= 15)
    {
        this->Tien = this->S * this->Gia * 1.2;
    }
    else
    {
        this->Tien = this->S * this->Gia;
    }
}

double GD::getTien() const
{
    return this->Tien;
}

string GD::getMa()
{
    return this->MaGD;
}

bool GD::flag() const
{
    if (this->Nam == 2024 && this->Thang == 12)
        return true;
    else
        return false;
}

ostream &operator<<(ostream &out, const GD &p)
{
    out << p.MaGD << "\t\t" << p.Ngay << '/' << p.Thang << '/' << p.Nam << "\t\t" << p.Tien << "\n\n";
    return out;
}

istream &operator>>(istream &in, CC &obj)
{
    obj.NhapInfo();
    cout << "Nhap ma can: ";
    getline(in >> ws, obj.MaCan);
    cout << "Nhap vi tri tang: ";
    while (!(in >> obj.VTT) || obj.VTT <= 0)
    {
        cout << "Loi! Xin nhap lai.\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    obj.TinhTien();
    return in;
}

istream &operator>>(istream &in, Nha &obj)
{
    obj.NhapInfo();
    cout << "Nhap loai nha (cao cap, thuong): ";
    while (true)
    {
        getline(in, obj.type);
        if (obj.type == "cao cap" || obj.type == "thuong")
            break;
        cout << "Loi! Hay nhap lai.\n";
    }
    cout << "Nhap dia chi nha: ";
    getline(in, obj.dc);
    obj.TinhTien();
    return in;
}

istream &operator>>(istream &in, Dat &obj)
{
    obj.NhapInfo();
    cout << "Nhap loai dat (A, B, C): ";
    while (true)
    {
        in >> obj.type;
        if (obj.type == 'A' || obj.type == 'B' || obj.type == 'C')
            break;
        cout << "Loi! Xin nhap lai.\n\n";
    }
    obj.TinhTien();
    return in;
}

GD::~GD() = default;
