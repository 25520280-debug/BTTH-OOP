#include "PhanSo.h"
using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void PhanSo::rutGon() {
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
    int g = gcd(abs(tu), mau);
    if (g != 0) {
        tu /= g;
        mau /= g;
    }
}

PhanSo::PhanSo() : tu(0), mau(1) {}

PhanSo::PhanSo(int nguyen) : tu(nguyen), mau(1) {}

PhanSo::PhanSo(int t, int m) {
    if (m == 0)
        throw invalid_argument("Mau so khong duoc bang 0.");
    tu = t;
    mau = m;
    rutGon();
}

PhanSo PhanSo::operator+(const PhanSo& other) const {
    return PhanSo(tu * other.mau + other.tu * mau, mau * other.mau);
}

PhanSo PhanSo::operator-(const PhanSo& other) const {
    return PhanSo(tu * other.mau - other.tu * mau, mau * other.mau);
}

PhanSo PhanSo::operator*(const PhanSo& other) const {
    return PhanSo(tu * other.tu, mau * other.mau);
}

PhanSo PhanSo::operator/(const PhanSo& other) const {
    if (other.tu == 0)
        throw invalid_argument("Khong the chia cho phan so bang 0.");
    return PhanSo(tu * other.mau, mau * other.tu);
}

bool PhanSo::operator==(const PhanSo& other) const {
    return tu * other.mau == other.tu * mau;
}

bool PhanSo::operator>(const PhanSo& other) const {
    return tu * other.mau > other.tu * mau;
}

bool PhanSo::operator<(const PhanSo& other) const {
    return tu * other.mau < other.tu * mau;
}

ostream& operator<<(ostream& os, const PhanSo& ps) {
    if (ps.mau == 1)
        os << ps.tu;
    else
        os << ps.tu << "/" << ps.mau;
    return os;
}

istream& operator>>(istream& is, PhanSo& ps) {
    char dau;
    int t, m;
    if (!(is >> t >> dau >> m) || dau != '/')
        throw invalid_argument("Dinh dang nhap sai. Dung dinh dang: tu/mau");
    if (m == 0)
        throw invalid_argument("Mau so khong duoc bang 0.");
    ps = PhanSo(t, m);
    return is;
}