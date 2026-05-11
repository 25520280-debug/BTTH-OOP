#include <iostream>
#include <cmath>
#include <limits>
 
using namespace std;
 
const double EPS = 1e-9;
 
class SoPhuc {
private:
    double rel;
    double ima;
    bool   hop_le;
    const char* loi;
 
    static bool xapXi(double a, double b) {
        return fabs(a - b) < EPS;
    }
 
    SoPhuc(bool, const char* msg)
        : rel(0.0), ima(0.0), hop_le(false), loi(msg) {}
 
public:
    SoPhuc(double a = 0.0, double b = 0.0)
        : rel(a), ima(b), hop_le(true), loi("") {}
 
    static SoPhuc loi_phep(const char* msg) {
        return SoPhuc(false, msg);
    }
 
    double getThuc()  const { return rel; }
    double getAo()    const { return ima; }
    bool   laHopLe()  const { return hop_le; }
 
    bool laSo0()     const { return hop_le && xapXi(rel,0.0) && xapXi(ima,0.0); }
    bool laSoThuc()  const { return hop_le && xapXi(ima,0.0); }
    bool laThuanAo() const { return hop_le && xapXi(rel,0.0) && !xapXi(ima,0.0); }
 
    double modulus() const {
        return sqrt(rel * rel + ima * ima);
    }
 
    SoPhuc lien_hop() const {
        if (!hop_le) return *this;
        return SoPhuc(rel, -ima);
    }
 
    SoPhuc operator-() const {
        if (!hop_le) return *this;
        return SoPhuc(-rel, -ima);
    }
 
    SoPhuc operator+(const SoPhuc& o) const {
        if (!hop_le) return *this;
        if (!o.hop_le) return o;
        return SoPhuc(rel + o.rel, ima + o.ima);
    }
 
    SoPhuc operator-(const SoPhuc& o) const {
        if (!hop_le) return *this;
        if (!o.hop_le) return o;
        return SoPhuc(rel - o.rel, ima - o.ima);
    }
 
    SoPhuc operator*(const SoPhuc& o) const {
        if (!hop_le) return *this;
        if (!o.hop_le) return o;
        return SoPhuc(
            rel * o.rel - ima * o.ima,
            rel * o.ima + ima * o.rel
        );
    }
 
    SoPhuc operator/(const SoPhuc& o) const {
        if (!hop_le) return *this;
        if (!o.hop_le) return o;
        double mau = o.rel * o.rel + o.ima * o.ima;
        if (mau < EPS)
            return loi_phep("Mau = 0, phep chia khong xac dinh");
        return SoPhuc(
            (rel * o.rel + ima * o.ima) / mau,
            (ima * o.rel - rel * o.ima) / mau
        );
    }
 
    bool operator==(const SoPhuc& o) const {
        return hop_le && o.hop_le
            && xapXi(rel, o.rel) && xapXi(ima, o.ima);
    }
 
    bool operator!=(const SoPhuc& o) const {
        return !(*this == o);
    }
 
    SoPhuc can_bac_hai() const {
        if (!hop_le) return *this;
        if (laSo0())  return SoPhuc(0.0, 0.0);
        double r = modulus();
        double x = sqrt((r + rel) / 2.0);
        double y = (ima >= 0.0 ? 1.0 : -1.0) * sqrt((r - rel) / 2.0);
        return SoPhuc(
            fabs(x) < EPS ? 0.0 : x,
            fabs(y) < EPS ? 0.0 : y
        );
    }
 
    SoPhuc luy_thua(int n) const {
        if (!hop_le) return *this;
        if (laSo0()) {
            if (n <= 0) return loi_phep("0^n voi n <= 0 khong xac dinh");
            return SoPhuc(0.0, 0.0);
        }
        if (n == 0) return SoPhuc(1.0, 0.0);
        if (n  < 0) return SoPhuc(1.0, 0.0) / luy_thua(-n);
        double r  = modulus();
        double ag = atan2(ima, rel);
        double rn = pow(r, n);
        double re = rn * cos(n * ag);
        double im = rn * sin(n * ag);
        return SoPhuc(fabs(re) < EPS ? 0.0 : re,
                      fabs(im) < EPS ? 0.0 : im);
    }
 
    void xuatGiaTri() const {
        if (!hop_le) { cout << "[!] " << loi; return; }
        if (laSo0())     { cout << 0;                           return; }
        if (laSoThuc())  { cout << rel;                         return; }
        if (laThuanAo()) { cout << ima << "i";                  return; }
        cout << rel;
        if (ima > 0) cout << " + " <<  ima << "i";
        else         cout << " - " << -ima << "i";
    }
 
    void xuatModulus() const {
        if (!hop_le) { cout << "[!] " << loi; return; }
        cout << modulus();
    }
 
    void xuatArgument() const {
        if (!hop_le) { cout << "[!] " << loi; return; }
        if (laSo0()) { cout << "[!] arg(0) khong xac dinh";   return; }
        double ag  = atan2(ima, rel);
        double deg = ag * 180.0 / M_PI;
        cout << ag << " rad (~" << deg << " do)";
    }
 
    void xuatLuongGiac() const {
        if (!hop_le) { cout << "[!] " << loi; return; }
        if (laSo0()) { cout << 0;                              return; }
        double r  = modulus();
        double ag = atan2(ima, rel);
        cout << r << " * (cos(" << ag << ") + i*sin(" << ag << "))";
    }
};
 
bool docDouble(double& x) {
    if (cin >> x) return true;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
}
 
SoPhuc nhapSoPhuc(const char* ten) {
    double a, b;
    while (true) {
        cout << "Nhap " << ten << ":\n";
        cout << "  Phan thuc : ";
        if (!docDouble(a)) { cout << "  [!] Sai kieu, nhap lai.\n\n"; continue; }
        cout << "  Phan ao   : ";
        if (!docDouble(b)) { cout << "  [!] Sai kieu, nhap lai.\n\n"; continue; }
        return SoPhuc(a, b);
    }
}
 
int nhapSoMu() {
    int n;
    while (true) {
        cout << "Nhap so mu n (nguyen): ";
        if (cin >> n) return n;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  [!] Sai kieu, nhap lai.\n";
    }
}
 
void inDuong(int n = 48) {
    for (int i = 0; i < n; i++) cout << '-';
    cout << '\n';
}
 
void inTitle(const char* s) {
    inDuong();
    cout << "  " << s << '\n';
    inDuong();
}
 
void inNhan(const char* nhan) {
    cout << "  " << nhan;
    int len = 0;
    while (nhan[len]) len++;
    for (int i = len; i < 26; i++) cout << ' ';
    cout << "= ";
}
 
int main() {
    SoPhuc z1 = nhapSoPhuc("z1");
    cout << '\n';
    SoPhuc z2 = nhapSoPhuc("z2");
    cout << '\n';
    int n = nhapSoMu();
    cout << '\n';
 
    inTitle("GIA TRI NHAP:");
    inNhan("z1");              z1.xuatGiaTri();       cout << '\n';
    inNhan("z2");              z2.xuatGiaTri();       cout << '\n';
 
    inTitle("DANG LUONG GIAC:");
    inNhan("z1");              z1.xuatLuongGiac();    cout << '\n';
    inNhan("z2");              z2.xuatLuongGiac();    cout << '\n';
 
    inTitle("TINH CHAT:");
    inNhan("|z1|");            z1.xuatModulus();      cout << '\n';
    inNhan("|z2|");            z2.xuatModulus();      cout << '\n';
    inNhan("arg(z1)");         z1.xuatArgument();     cout << '\n';
    inNhan("arg(z2)");         z2.xuatArgument();     cout << '\n';
    inNhan("conj(z1)");        z1.lien_hop().xuatGiaTri();  cout << '\n';
    inNhan("conj(z2)");        z2.lien_hop().xuatGiaTri();  cout << '\n';
    inNhan("-z1");             (-z1).xuatGiaTri();    cout << '\n';
    inNhan("-z2");             (-z2).xuatGiaTri();    cout << '\n';
    inNhan("z1 la so 0?");     cout << (z1.laSo0()     ? "Co" : "Khong") << '\n';
    inNhan("z1 la so thuc?");  cout << (z1.laSoThuc()  ? "Co" : "Khong") << '\n';
    inNhan("z1 la thuan ao?"); cout << (z1.laThuanAo() ? "Co" : "Khong") << '\n';
    inNhan("z2 la so 0?");     cout << (z2.laSo0()     ? "Co" : "Khong") << '\n';
    inNhan("z2 la so thuc?");  cout << (z2.laSoThuc()  ? "Co" : "Khong") << '\n';
    inNhan("z2 la thuan ao?"); cout << (z2.laThuanAo() ? "Co" : "Khong") << '\n';
 
    inTitle("4 PHEP TOAN:");
    inNhan("z1 + z2");         (z1 + z2).xuatGiaTri(); cout << '\n';
    inNhan("z1 - z2");         (z1 - z2).xuatGiaTri(); cout << '\n';
    inNhan("z1 * z2");         (z1 * z2).xuatGiaTri(); cout << '\n';
    inNhan("z1 / z2");         (z1 / z2).xuatGiaTri(); cout << '\n';
    inNhan("z2 / z1");         (z2 / z1).xuatGiaTri(); cout << '\n';
 
    inTitle("LUY THUA & CAN BAC HAI:");
    inNhan("sqrt(z1)");        z1.can_bac_hai().xuatGiaTri(); cout << '\n';
    inNhan("sqrt(z2)");        z2.can_bac_hai().xuatGiaTri(); cout << '\n';
    inNhan("z1^n");            z1.luy_thua(n).xuatGiaTri();   cout << '\n';
    inNhan("z2^n");            z2.luy_thua(n).xuatGiaTri();   cout << '\n';
 
    inTitle("SO SANH:");
    inNhan("z1 == z2");        cout << (z1 == z2 ? "True"  : "False") << '\n';
    inNhan("z1 != z2");        cout << (z1 != z2 ? "True"  : "False") << '\n';
 
    inTitle("KIEM TRA TINH CHAT:");
    inNhan("z1 * conj(z1)");   (z1 * z1.lien_hop()).xuatGiaTri(); cout << '\n';
    inNhan("|z1|^2");          cout << z1.modulus() * z1.modulus()  << '\n';
    inNhan("z2 * conj(z2)");   (z2 * z2.lien_hop()).xuatGiaTri(); cout << '\n';
    inNhan("|z2|^2");          cout << z2.modulus() * z2.modulus()  << '\n';
 
    inDuong();
    return 0;
}