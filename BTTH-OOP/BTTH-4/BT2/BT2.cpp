#include <iostream>

using namespace std;

int gcd(int a, int b) {
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

class PhanSo {
private:
    int tu, mau;

    void rutGon() {
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
        int g = gcd((tu < 0 ? -tu : tu), mau);
        if (g != 0) {
            tu /= g;
            mau /= g;
        }
    }

public:
    PhanSo() : tu(0), mau(1) {}

    PhanSo(int nguyen) : tu(nguyen), mau(1) {}

    PhanSo(int t, int m) {
        if (m == 0)
            throw invalid_argument("Mau so khong duoc bang 0.");
        tu = t;
        mau = m;
        rutGon();
    }

    PhanSo operator+(const PhanSo& other) const {
        return PhanSo(tu * other.mau + other.tu * mau, mau * other.mau);
    }

    PhanSo operator-(const PhanSo& other) const {
        return PhanSo(tu * other.mau - other.tu * mau, mau * other.mau);
    }

    PhanSo operator*(const PhanSo& other) const {
        return PhanSo(tu * other.tu, mau * other.mau);
    }

    PhanSo operator/(const PhanSo& other) const {
        if (other.tu == 0)
            throw invalid_argument("Khong the chia cho phan so bang 0.");
        return PhanSo(tu * other.mau, mau * other.tu);
    }

    bool operator==(const PhanSo& other) const {
        return tu * other.mau == other.tu * mau;
    }

    bool operator>(const PhanSo& other) const {
        return tu * other.mau > other.tu * mau;
    }

    bool operator<(const PhanSo& other) const {
        return tu * other.mau < other.tu * mau;
    }

    friend ostream& operator<<(ostream& os, const PhanSo& ps) {
        if (ps.mau == 1)
            os << ps.tu;
        else
            os << ps.tu << "/" << ps.mau;
        return os;
    }

    friend istream& operator>>(istream& is, PhanSo& ps) {
        char dau;
        int t, m;
        is >> t >> dau >> m;
        if (dau != '/')
            throw invalid_argument("Dinh dang nhap sai. Dung dinh dang: tu/mau");
        if (m == 0)
            throw invalid_argument("Mau so khong duoc bang 0.");
        ps = PhanSo(t, m);
        return is;
    }
};

int main() {
    PhanSo a(1, 2);
    PhanSo b(1, 3);
    PhanSo nguyen(5);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "nguyen = " << nguyen << endl;

    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << endl;

    cout << "a == b: " << (a == b ? "true" : "false") << endl;
    cout << "a > b:  " << (a > b  ? "true" : "false") << endl;
    cout << "a < b:  " << (a < b  ? "true" : "false") << endl;

    cout << "nguyen + a = " << (nguyen + a) << endl;

    cout << "\nNhap phan so (dinh dang tu/mau): ";
    PhanSo nhap;
    cin >> nhap;
    cout << "Phan so vua nhap: " << nhap << endl;

    return 0;
}