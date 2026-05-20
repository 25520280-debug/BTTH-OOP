#include <iostream>
#include <string>
#include <vector>
using namespace std;

void checkNhap(auto &test)
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

class NhanVien
{
protected:
    string HoTen;
    int NgaySinh,
        ThangSinh,
        NamSinh;
    long double Luong;

public:
    NhanVien() : NgaySinh(1), ThangSinh(1), NamSinh(1), Luong(0) {}
    virtual ~NhanVien() {}

    virtual void TinhLuong() = 0;

    double getLuong() const { return this->Luong; }
    void NhapInfo()
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
    };

    friend ostream &operator<<(ostream &out, const NhanVien &t)
    {
        out << t.HoTen << "\t\t" << t.NgaySinh << '/' << t.ThangSinh << '/' << t.NamSinh << "\t\t"
            << "Luong : " << t.Luong << '\n';
        return out;
    }
    bool operator>(const NhanVien &other) const
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
};

class NVSanXuat : public NhanVien
{
private:
    double LuongCanBan;
    int SoSanPham;

public:
    NVSanXuat() : LuongCanBan(0), SoSanPham(0) {}
    ~NVSanXuat() {}

    void TinhLuong() override
    {
        this->Luong = LuongCanBan + SoSanPham * 5000;
    }

    friend istream &operator>>(istream &in, NVSanXuat &t)
    {
        t.NhapInfo();
        cout << "Nhap luong can ban: ";
        checkNhap(t.LuongCanBan);
        cout << "Nhap so san pham: ";
        checkNhap(t.SoSanPham);
        t.TinhLuong();
        return in;
    };
};

class NVVanPhong : public NhanVien
{
private:
    int SoNgayLamViec;

public:
    NVVanPhong() : SoNgayLamViec(0) {}
    ~NVVanPhong() {}

    void TinhLuong() override
    {
        this->Luong = SoNgayLamViec * 100000;
    }

    friend istream &operator>>(istream &in, NVVanPhong &t)
    {
        t.NhapInfo();
        cout << "Nhap so ngay lam viec: ";
        checkNhap(t.SoNgayLamViec);
        t.TinhLuong();
        return in;
    }
};

class CongTy
{
private:
    vector<NhanVien *> NV;

public:
    CongTy() {}
    ~CongTy()
    {
        for (NhanVien *&x : NV)
            delete x;
    }
    void Nhap()
    {
        cout << "So nhan vien muon them: ";
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int type;
            cout << "Chon nhan vien (1 : San xuat, 2 : Van phong): ";
            while (!(cin >> type) || (type <= 0 || type > 2))
            {
                cout << "Error! Please try again.\n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            if (type == 1)
            {
                NVSanXuat *temp = new NVSanXuat();
                cin >> *temp;
                NV.push_back(temp);
            }
            else if (type == 2)
            {
                NVVanPhong *temp = new NVVanPhong();
                cin >> *temp;
                NV.push_back(temp);
            }
        }
    }

    void Xuat()
    {
        if (this->NV.empty())
            return;
        for (NhanVien *x : this->NV)
        {
            cout << *x;
        };
        NhanVien *old = NV[0];
        NhanVien *low = NV[0];
        for (int i = 0; i < NV.size(); i++)
        {
            if (NV[i]->getLuong() < low->getLuong())
                low = NV[i];
            if (*NV[i] > *old)
                old = NV[i];
        }
        cout << "Nhan vien lon tuoi nhat: \n";
        cout << *old;
        cout << "Nhan vien co luong thap nhat: \n";
        cout << *low;
    }
};

int main()
{
    CongTy CT;
    CT.Nhap();
    CT.Xuat();
    return 0;
}