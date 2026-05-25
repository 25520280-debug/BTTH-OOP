#include "CongTy.h"

void CongTy::Nhap()
{
    int a, b, c;
    cin >> a >> b >> c;
    this->DSKT.resize(a);
    this->DSKTT.resize(b);
    this->DSKDB.resize(c);

    for (x *&t : this->DSKT)
    {
        x *temp = new x();
        cin >> *temp;
        this->TongSoTienThuDuoc += temp->getSTPT();
        t = temp;
    }
    for (y *&t : this->DSKTT)
    {
        y *temp = new y();
        cin >> *temp;
        this->TongSoTienThuDuoc += temp->getSTPT();
        t = temp;
    }
    for (z *&t : this->DSKDB)
    {
        z *temp = new z();
        cin >> *temp;
        this->TongSoTienThuDuoc += temp->getSTPT();
        t = temp;
    }
}

void CongTy::Xuat()
{
    cout << '\n';
    for (x *t : this->DSKT)
        cout << *t;
    cout << '\n';
    for (y *t : this->DSKTT)
        cout << *t;
    cout << '\n';
    for (z *t : this->DSKDB)
        cout << *t;
    cout << '\n' << this->TongSoTienThuDuoc;
}

CongTy::~CongTy()
{
    for (x *&t : this->DSKT)
        delete t;
    for (y *&t : this->DSKTT)
        delete t;
    for (z *&t : this->DSKDB)
        delete t;
}
