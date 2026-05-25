#pragma once
#include "KhachHang.h"
#include <vector>

class CongTy {
    vector <x*> DSKT;
    vector <y*> DSKTT;
    vector <z*> DSKDB;
    double TongSoTienThuDuoc;
public:
    CongTy() : TongSoTienThuDuoc(0) {}
    ~CongTy();
    void Nhap();
    void Xuat();
};