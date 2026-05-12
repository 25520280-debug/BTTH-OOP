#include "CTime.h"
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int g1, p1, s1, g2, p2, s2;
    int congGiay, truGiay;
    
    cout << "Nhap thoi gian thu nhat (gio phut giay): ";
    while (!(cin >> g1 >> p1 >> s1)) {
    cout << "Loi: Vui long nhap 3 so nguyen!\n";
    cout << "Nhap lai...: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
    
    cout << "Nhap so giay de cong: ";
    cin >> congGiay;
    
    cout << "Nhap so giay de tru: ";
    cin >> truGiay;
    
    cout << "Nhap thoi gian thu hai (gio phut giay): ";
    cin >> g2 >> p2 >> s2;
    
    CTime t1(g1, p1, s1);
    cout << "\nThoi gian thu nhat:" << endl;
    cout << "  Dinh dang 24h: " << t1 << endl;
    cout << "  Dinh dang 12h: "; t1.xuat12h(); cout << endl;
    
    CTime cong = t1 + congGiay;
    cout << "\nCong " << congGiay << " giay:" << endl;
    cout << "  Dinh dang 24h: " << cong << endl;
    cout << "  Dinh dang 12h: "; cong.xuat12h(); cout << endl;
    
    CTime tru = t1 - truGiay;
    cout << "\nTru " << truGiay << " giay:" << endl;
    cout << "  Dinh dang 24h: " << tru << endl;
    cout << "  Dinh dang 12h: "; tru.xuat12h(); cout << endl;
    
    CTime t2(g2, p2, s2);
    cout << "\nThoi gian thu hai:" << endl;
    cout << "  Dinh dang 24h: " << t2 << endl;
    cout << "  Dinh dang 12h: "; t2.xuat12h(); cout << endl;
    
    cout << "\nCac phep toan tang giam:" << endl;
    CTime temp = t2++;
    cout << "t2++ (hau to): "; temp.xuat24h(); cout << '(';  temp.xuat12h(); cout << ")" << endl;
    cout << "  t2 sau khi tang: "; t2.xuat24h(); cout << '(';  temp.xuat12h(); cout << ")" << endl;
    
    temp = ++t2;
    cout << "++t2 (tien to): "; temp.xuat24h(); cout << '(';  temp.xuat12h(); cout << ")" << endl;
    
    temp = t2--;
    cout << "t2-- (hau to): "; temp.xuat24h(); cout << '(';  temp.xuat12h(); cout << ")" << endl;
    cout << "  t2 sau khi giam: "; t2.xuat24h(); cout << '(';  temp.xuat12h(); cout << ")" << endl;
    
    temp = --t2;
    cout << "--t2 (tien to): "; temp.xuat24h(); cout << '(';  temp.xuat12h(); cout << ")" << endl;
    
    return 0;
}
