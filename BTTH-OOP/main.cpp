#include "HMS.h"
#include <iostream>

using namespace std;

int main() {
    ThoiGian tg;
    tg.Nhap();
    tg.TinhCongThemMotGiay();
    cout << "Thoi gian moi: ";
    tg.Xuat();
    cout << endl;
    return 0;
}
