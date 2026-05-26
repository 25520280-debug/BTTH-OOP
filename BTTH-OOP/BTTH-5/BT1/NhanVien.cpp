#include "NhanVien.h"
using namespace std;

template <typename T>
void checkNhap(T &test)
{
    while (!(cin >> test))
    {
        cout << "Error! Please try again.\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.ignore(10000, '\n');
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
NhanVien::NhanVien() : NgaySinh(1), ThangSinh(1), NamSinh(1), Luong(0) {}
NhanVien::~NhanVien() {}

double NhanVien::getLuong() const
{
    return this->Luong;
}

void NhanVien::NhapInfo()
{
    cout << "Nhap ho ten: ";
    getline(cin >> ws, this->HoTen);
    cout << "Nhap nam sinh: ";
    do
        checkNhap(this->NamSinh);
    while (this->NamSinh <= 0);
    cout << "Nhap thang sinh: ";
    do
        checkNhap(this->ThangSinh);
    while (this->ThangSinh <= 0 || this->ThangSinh > 12);
    cout << "Nhap ngay sinh: ";
    do
        checkNhap(this->NgaySinh);
    while (this->NgaySinh <= 0 ||
           this->NgaySinh > MaxDay(this->ThangSinh, this->NamSinh));
}

bool NhanVien::operator>(const NhanVien &other) const
{
    if (this->NamSinh < other.NamSinh)
        return 1;
    else if (this->NamSinh == other.NamSinh)
    {
        if (this->ThangSinh < other.ThangSinh)
            return 1;
        else if (this->ThangSinh == other.ThangSinh)
        {
            if (this->NgaySinh < other.NgaySinh)
                return 1;
        }
    }
    return 0;
}

NVSanXuat::NVSanXuat() : LuongCanBan(0), SoSanPham(0) {}

NVSanXuat::~NVSanXuat() {}

void NVSanXuat::TinhLuong()
{
    this->Luong = LuongCanBan + SoSanPham * 5000;
}

NVVanPhong::NVVanPhong() : SoNgayLamViec(0) {}

NVVanPhong::~NVVanPhong() {}

void NVVanPhong::TinhLuong()
{
    this->Luong = SoNgayLamViec * 100000;
}

istream &operator>>(istream &in, NVVanPhong &t)
{
    t.NhapInfo();
    cout << "Nhap so ngay lam viec: ";
    checkNhap(t.SoNgayLamViec);
    t.TinhLuong();
    return in;
}

istream &operator>>(istream &in, NVSanXuat &t)
{
    t.NhapInfo();
    cout << "Nhap luong can ban: ";
    checkNhap(t.LuongCanBan);
    cout << "Nhap so san pham: ";
    checkNhap(t.SoSanPham);
    t.TinhLuong();
    return in;
}

ostream &operator<<(ostream &out, const NhanVien &t)
{
    out << t.HoTen << "\t\t" << t.NgaySinh << '/' << t.ThangSinh << '/' << t.NamSinh << "\t\t"
        << "Luong : " << t.Luong << '\n';
    return out;
}
