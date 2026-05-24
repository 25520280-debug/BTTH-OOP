#pragma once
#include "NhanVien.h"
#include <vector>

class CongTy {
    vector <NhanVien*> DSNV;
    double LuongTB;
    NhanVien* NVL_Max;
    NhanVien* NVL_Min;
    LTV* LTV_Max;
    KCV* KCV_Min;
public:
    CongTy() : LuongTB(0), LTV_Max(new LTV()), KCV_Min(new KCV()) {}
    ~CongTy();
    friend istream& operator >> (istream& in, CongTy& p);
    friend ostream& operator << (ostream& out, const CongTy& p);
};