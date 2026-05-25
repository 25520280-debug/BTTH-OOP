#include "CongTy.h"

istream &operator>>(istream &in, CongTy &p)
{
    int n;
    while (true)
    {
        cout << "Nhap so luong nhan vien: ";
        checkNhap(n);
        if (n > 0)
            break;
    }
    p.DSNV.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        while (true)
        {
            cout << "Chon loai nhan vien (1: Lap trinh vien, 2: Kiem chung vien): ";
            checkNhap(x);
            if (x == 1 || x == 2)
                break;
            cout << "Loi! Xin nhap lai.\n\n";
        }
        if (x == 1)
        {
            LTV *temp = new LTV();
            in >> *temp;
            if (!p.LTV_Max ||temp->getLuong() > p.LTV_Max->getLuong())
                p.LTV_Max = temp;
            if (!p.NVL_Max || temp->getLuong() > p.NVL_Max->getLuong())
                p.NVL_Max = temp;
            if (!p.NVL_Min || temp->getLuong() < p.NVL_Min->getLuong())
                p.NVL_Min = temp;
            p.DSNV.push_back(temp);
            p.LuongTB += temp->getLuong();
        }
        else
        {
            KCV *temp = new KCV();
            in >> *temp;
            if (!p.KCV_Min || temp->getLuong() < p.KCV_Min->getLuong())
                p.KCV_Min = temp;
            if (!p.NVL_Max || temp->getLuong() > p.NVL_Max->getLuong())
                p.NVL_Max = temp;
            if (!p.NVL_Min || temp->getLuong() < p.NVL_Min->getLuong())
                p.NVL_Min = temp;
            p.DSNV.push_back(temp);
            p.LuongTB += temp->getLuong();
        }
    }
    p.LuongTB /= n;
    return in;
}

ostream &operator<<(ostream &out, const CongTy &p)
{
    out << "Danh sach nhan vien\n\n"; 
    out << "Ma\t\tHo_ten\t\tTuoi\t\tSo_dien_thoai\t\tEmail\n";
    for (NhanVien* x : p.DSNV) out << *x << '\n';
    out << "\nDanh sach nhan vien co muc luong it hon muc trung binh:\n\n";
    for (NhanVien* x : p.DSNV) {
        if (x->getLuong() < p.LuongTB) out << *x << '\n';
    }
    out << "\nNhan vien co muc luong cao nhat:\n"; out << *p.NVL_Max;
    out << "\n\nNhan vien co muc luong thap nhat:\n"; out << *p.NVL_Min;
    out << "\n\nLap trinh vien co muc luong cao nhat:\n"; out << *p.LTV_Max;
    out << "\n\nKiem chung vien co muc luong thap nhat:\n"; out << *p.KCV_Min;
    return out;
}

CongTy::~CongTy()
{
    for (NhanVien *&x : this->DSNV)
        delete x;
}
