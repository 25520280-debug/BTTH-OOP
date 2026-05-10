#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;
 
class CDate {
private:
    int ngay, thang, nam;
 
    static bool namNhuan(int n) {
        return (n % 4 == 0 && n % 100 != 0) || (n % 400 == 0);
    }
 
    static int soNgayTrongThang(int th, int n) {
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if (th == 2 && namNhuan(n)) return 29;
        return days[th - 1];
    }
 
    static bool hopLe(int ng, int th, int n) {
        if (th < 1 || th > 12) return false;
        if (ng < 1 || ng > soNgayTrongThang(th, n)) return false;
        return true;
    }
 
    long long toJulian() const {
        int a = (14 - thang) / 12;
        int y = nam + 4800 - a;
        int m = thang + 12 * a - 3;
        return ngay + (153*m + 2)/5 + 365LL*y + y/4 - y/100 + y/400 - 32045;
    }
 
    static CDate fromJulian(long long jd) {
        long long a = jd + 32044;
        long long b = (4*a + 3) / 146097;
        long long c = a - (146097*b) / 4;
        long long d = (4*c + 3) / 1461;
        long long e = c - (1461*d) / 4;
        long long m = (5*e + 2) / 153;
        int ng  = (int)(e - (153*m + 2)/5 + 1);
        int th  = (int)(m + 3 - 12*(m/10));
        int n   = (int)(100*b + d - 4800 + m/10);
        return CDate(ng, th, n);
    }
 
public:
    CDate() : ngay(1), thang(1), nam(2000) {}
 
    CDate(int ng, int th, int n) {
        if (!hopLe(ng, th, n))
            throw invalid_argument("Ngay thang nam khong hop le.");
        ngay = ng; thang = th; nam = n;
    }
 
    CDate operator+(int soNgay) const { return fromJulian(toJulian() + soNgay); }
    CDate operator-(int soNgay) const { return fromJulian(toJulian() - soNgay); }
 
    long long operator-(const CDate& other) const { return toJulian() - other.toJulian(); }
 
    CDate& operator++() { *this = *this + 1; return *this; }
    CDate  operator++(int) { CDate t = *this; ++(*this); return t; }
    CDate& operator--() { *this = *this - 1; return *this; }
    CDate  operator--(int) { CDate t = *this; --(*this); return t; }
 
    friend ostream& operator<<(ostream& os, const CDate& d) {
        os << setfill('0') << setw(2) << d.ngay << "/"
           << setw(2) << d.thang << "/"
           << setw(4) << d.nam;
        return os;
    }
 
    friend istream& operator>>(istream& is, CDate& d) {
        char c;
        int ng, th, n;
        is >> ng >> c >> th >> c >> n;
        if (!hopLe(ng, th, n))
            throw invalid_argument("Ngay thang nam khong hop le.");
        d.ngay = ng; d.thang = th; d.nam = n;
        return is;
    }
};
 
void tinhLaiSuat() {
    cout << "\n========================================\n";
    cout << "  BAI TOAN LAI SUAT TIEN GUI NGAN HANG\n";
    cout << "========================================\n\n";
 
    double vonGoc, laiSuatNam;
    CDate ngayGui, ngayRut;
 
    cout << "Nhap von goc (VND)          : ";
    cin >> vonGoc;
    cout << "Nhap lai suat nam (%)       : ";
    cin >> laiSuatNam;
    cout << "Nhap ngay gui (dd/mm/yyyy)  : ";
    cin >> ngayGui;
    cout << "Nhap ngay rut (dd/mm/yyyy)  : ";
    cin >> ngayRut;
 
    long long soNgay = ngayRut - ngayGui;
    if (soNgay <= 0) { cout << "Ngay rut phai sau ngay gui!\n"; return; }
 
    double tienLai  = vonGoc * (laiSuatNam / 100.0) * soNgay / 365.0;
    double tongTien = vonGoc + tienLai;
 
    cout << "\n----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Von goc        : " << vonGoc      << " VND\n";
    cout << "Lai suat/nam   : " << laiSuatNam  << " %\n";
    cout << "Ngay gui       : " << ngayGui      << "\n";
    cout << "Ngay rut       : " << ngayRut      << "\n";
    cout << "So ngay gui    : " << soNgay        << " ngay\n";
    cout << "Tien lai       : " << tienLai      << " VND\n";
    cout << "Tong tien nhan : " << tongTien     << " VND\n";
    cout << "----------------------------------------\n";
}
 
int main() {
    cout << "=== DEMO LOP CDate ===\n\n";
 
    CDate d1(28, 2, 2024);
    cout << "d1             = " << d1         << "\n";
    cout << "d1 + 1 ngay    = " << (d1 + 1)   << "  (nam nhuan)\n";
    cout << "d1 + 400 ngay  = " << (d1 + 400) << "\n";
    cout << "d1 - 60 ngay   = " << (d1 - 60)  << "\n";
 
    CDate d2(1, 1, 2025);
    cout << "d2             = " << d2          << "\n";
    cout << "d2 - d1        = " << (d2 - d1)   << " ngay\n";
    cout << "d2++ (post)    = " << d2++         << "  ->  d2 = " << d2 << "\n";
    cout << "++d2 (pre)     = " << ++d2         << "\n";
    cout << "d2-- (post)    = " << d2--         << "  ->  d2 = " << d2 << "\n";
    cout << "--d2 (pre)     = " << --d2         << "\n";
 
    tinhLaiSuat();
    return 0;
}
 