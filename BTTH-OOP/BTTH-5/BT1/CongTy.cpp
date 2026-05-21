#include "CongTy.h"

CongTy::CongTy() {}
CongTy::~CongTy()
{
    for (NhanVien *&x : NV)
        delete x;
}

void CongTy::Nhap()
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

void CongTy::Xuat()
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
