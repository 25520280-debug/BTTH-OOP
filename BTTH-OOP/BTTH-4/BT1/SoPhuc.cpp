#include "SoPhuc.h"

bool SoPhuc::xapXi(double a, double b) {
    return fabs(a - b) < EPS;
}

SoPhuc::SoPhuc(bool, const char* msg)
    : rel(0.0), ima(0.0), hop_le(false), loi(msg) {}

SoPhuc::SoPhuc(double a, double b)
    : rel(a), ima(b), hop_le(true), loi("") {}

SoPhuc SoPhuc::loi_phep(const char* msg) {
    return SoPhuc(false, msg);
}

double SoPhuc::getThuc()  const { return rel; }
double SoPhuc::getAo()    const { return ima; }
bool   SoPhuc::laHopLe()  const { return hop_le; }

bool SoPhuc::laSo0()     const { return hop_le && xapXi(rel, 0.0) && xapXi(ima, 0.0); }
bool SoPhuc::laSoThuc()  const { return hop_le && xapXi(ima, 0.0); }
bool SoPhuc::laThuanAo() const { return hop_le && xapXi(rel, 0.0) && !xapXi(ima, 0.0); }

double SoPhuc::modulus() const {
    return sqrt(rel * rel + ima * ima);
}

SoPhuc SoPhuc::lien_hop() const {
    if (!hop_le) return *this;
    return SoPhuc(rel, -ima);
}

SoPhuc SoPhuc::operator-() const {
    if (!hop_le) return *this;
    return SoPhuc(-rel, -ima);
}

SoPhuc SoPhuc::operator+(const SoPhuc& o) const {
    if (!hop_le) return *this;
    if (!o.hop_le) return o;
    return SoPhuc(rel + o.rel, ima + o.ima);
}

SoPhuc SoPhuc::operator-(const SoPhuc& o) const {
    if (!hop_le) return *this;
    if (!o.hop_le) return o;
    return SoPhuc(rel - o.rel, ima - o.ima);
}

SoPhuc SoPhuc::operator*(const SoPhuc& o) const {
    if (!hop_le) return *this;
    if (!o.hop_le) return o;
    return SoPhuc(
        rel * o.rel - ima * o.ima,
        rel * o.ima + ima * o.rel
    );
}

SoPhuc SoPhuc::operator/(const SoPhuc& o) const {
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

bool SoPhuc::operator==(const SoPhuc& o) const {
    return hop_le && o.hop_le
        && xapXi(rel, o.rel) && xapXi(ima, o.ima);
}

bool SoPhuc::operator!=(const SoPhuc& o) const {
    return !(*this == o);
}

SoPhuc SoPhuc::can_bac_hai() const {
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

SoPhuc SoPhuc::luy_thua(int n) const {
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

void SoPhuc::xuatGiaTri() const {
    if (!hop_le) { cout << "[!] " << loi; return; }
    if (laSo0())     { cout << 0;                           return; }
    if (laSoThuc())  { cout << rel;                         return; }
    if (laThuanAo()) { cout << ima << "i";                  return; }
    cout << rel;
    if (ima > 0) cout << " + " <<  ima << "i";
    else         cout << " - " << -ima << "i";
}

void SoPhuc::xuatModulus() const {
    if (!hop_le) { cout << "[!] " << loi; return; }
    cout << modulus();
}

void SoPhuc::xuatArgument() const {
    if (!hop_le) { cout << "[!] " << loi; return; }
    if (laSo0()) { cout << "[!] arg(0) khong xac dinh";   return; }
    double ag  = atan2(ima, rel);
    double deg = ag * 180.0 / M_PI;
    cout << ag << " rad (~" << deg << " do)";
}

void SoPhuc::xuatLuongGiac() const {
    if (!hop_le) { cout << "[!] " << loi; return; }
    if (laSo0()) { cout << 0;                              return; }
    double r  = modulus();
    double ag = atan2(ima, rel);
    cout << r << " * (cos(" << ag << ") + i*sin(" << ag << "))";
}

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

void inDuong(int n) {
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