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
            LTV *temp;
            cin >> *temp;
            if (temp->getLuong() > p.LTV_Max->getLuong())
                p.LTV_Max = temp;
            if (temp->getLuong() > p.NVL_Max->getLuong())
                p.NVL_Max = temp;
            if (temp->getLuong() < p.NVL_Min->getLuong())
                p.NVL_Min = temp;
            p.DSNV.push_back(temp);
            p.LuongTB += temp->getLuong();
        }
        else
        {
            KCV *temp;
            cin >> *temp;
            if (temp->getLuong() < p.KCV_Min->getLuong())
                p.KCV_Min = temp;
            if (temp->getLuong() > p.NVL_Max->getLuong())
                p.NVL_Max = temp;
            if (temp->getLuong() < p.NVL_Min->getLuong())
                p.NVL_Min = temp;
            p.DSNV.push_back(temp);
            p.LuongTB += temp->getLuong();
        }
    }
    p.LuongTB /= n;
}

ostream &operator<<(ostream &out, const CongTy &p)
{
}

CongTy::~CongTy()
{
    for (NhanVien *&x : this->DSNV)
        delete x;
    delete this->NVL_Min;
    delete this->KCV_Min;
    delete this->LTV_Max;
    delete this->NVL_Max;
}
