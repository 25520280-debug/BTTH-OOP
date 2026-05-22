#pragma once
#include <vector>
#include "SinhVien.h"

class Truong {
    vector<SV*> svs;
    vector<SV*> svKD;
    vector<SV*> svD;
    CD* MaxTB_CD;
    DH* MaxTB_DH;
    int SoSV_CD_KD,
        SoSV_DH_KD;
public:
    Truong();
    ~Truong();
    void Nhap();
    void Xuat();
};