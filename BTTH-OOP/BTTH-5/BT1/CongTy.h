#include "NhanVien.h"

class CongTy
{
private:
    vector<NhanVien *> NV;

public:
    CongTy();
    ~CongTy();
    void Nhap();
    void Xuat();
};
