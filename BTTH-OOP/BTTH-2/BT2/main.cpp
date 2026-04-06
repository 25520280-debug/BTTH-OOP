#include "PhanSo.h"
#include <iostream>

int main() {
    PhanSo ps1, ps2;
    ps1.Nhap(); ps2.Nhap();
    std::cout << "Tong: "; ps1.Tong(ps2).Xuat(); std::cout << '\n';
    std::cout << "Hieu: "; ps1.Hieu(ps2).Xuat(); std::cout << '\n';
    std::cout << "Tich: "; ps1.Tich(ps2).Xuat(); std::cout << '\n';
    std::cout << "Thuong: "; ps1.Thuong(ps2).Xuat(); std::cout << '\n';
    std::cout << "So sanh: "; ps1.Xuat(); 
    if (ps1.SoSanh(ps2)){
        if (ps1.SoSanh(ps2) < 0) std::cout << " < ";
        else std::cout << " > ";
    }
    else std::cout << " = ";
    ps2.Xuat();
    return 0;
}
