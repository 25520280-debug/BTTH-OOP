#include <iostream>
#include <iomanip>
using namespace std;
 
class CTime {
private:
    int gio, phut, giay;
 
    void chuanHoa() {
        if (giay >= 60) { phut += giay / 60; giay %= 60; }
        if (giay < 0)   { phut -= (-giay + 59) / 60; giay = ((giay % 60) + 60) % 60; }
        if (phut >= 60) { gio += phut / 60; phut %= 60; }
        if (phut < 0)   { gio -= (-phut + 59) / 60; phut = ((phut % 60) + 60) % 60; }
        gio = ((gio % 24) + 24) % 24;
    }
 
public:
    CTime() : gio(0), phut(0), giay(0) {}
 
    CTime(int g, int p, int s) : gio(g), phut(p), giay(s) {
        chuanHoa();
    }
 
    CTime operator+(int s) const { return CTime(gio, phut, giay + s); }
    CTime operator-(int s) const { return CTime(gio, phut, giay - s); }
 
    CTime& operator++() { *this = *this + 1; return *this; }
    CTime  operator++(int) { CTime t = *this; ++(*this); return t; }
    CTime& operator--() { *this = *this - 1; return *this; }
    CTime  operator--(int) { CTime t = *this; --(*this); return t; }
 
    friend ostream& operator<<(ostream& os, const CTime& t) {
        os << setfill('0') << setw(2) << t.gio << ":"
           << setw(2) << t.phut << ":"
           << setw(2) << t.giay;
        return os;
    }
 
    friend istream& operator>>(istream& is, CTime& t) {
        char c;
        is >> t.gio >> c >> t.phut >> c >> t.giay;
        t.chuanHoa();
        return is;
    }
};
 
int main() {
    CTime t1(23, 59, 55);
    cout << "t1            = " << t1 << "\n";
    cout << "t1 + 10 giay  = " << (t1 + 10) << "\n";
    cout << "t1 - 120 giay = " << (t1 - 120) << "\n";
 
    CTime t2(0, 0, 5);
    cout << "t2            = " << t2 << "\n";
    cout << "t2++ (post)   = " << t2++ << "  ->  t2 = " << t2 << "\n";
    cout << "++t2 (pre)    = " << ++t2 << "\n";
    cout << "t2-- (post)   = " << t2-- << "  ->  t2 = " << t2 << "\n";
    cout << "--t2 (pre)    = " << --t2 << "\n";
 
    CTime nhap;
    cout << "Nhap thoi gian (HH:MM:SS): ";
    cin >> nhap;
    cout << "Da nhap: " << nhap << "\n";
 
    return 0;
}