#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

class CVector {
private:
    vector<double> data;
    int dim;

public:
    CVector() : dim(0) {}

    CVector(int n) : dim(n), data(n, 0.0) {}

    CVector(vector<double> v) : data(v), dim(v.size()) {}

    void nhap() {
        cout << "Nhap so chieu: ";
        cin >> dim;
        data.resize(dim);
        for (int i = 0; i < dim; i++) {
            cout << "  v[" << i << "] = ";
            cin >> data[i];
        }
    }

    void xuat(const string& ten = "v") const {
        cout << ten << " = [ ";
        for (int i = 0; i < dim; i++)
            cout << data[i] << (i < dim - 1 ? ", " : " ");
        cout << "]" << endl;
    }

    int sochieu() const { return dim; }

    double& operator[](int i) { return data[i]; }
    const double& operator[](int i) const { return data[i]; }

    CVector operator+(const CVector& other) const {
        if (dim != other.dim) throw invalid_argument("Khac so chieu!");
        CVector result(dim);
        for (int i = 0; i < dim; i++)
            result.data[i] = data[i] + other.data[i];
        return result;
    }

    CVector operator-(const CVector& other) const {
        if (dim != other.dim) throw invalid_argument("Khac so chieu!");
        CVector result(dim);
        for (int i = 0; i < dim; i++)
            result.data[i] = data[i] - other.data[i];
        return result;
    }

    CVector operator*(double scalar) const {
        CVector result(dim);
        for (int i = 0; i < dim; i++)
            result.data[i] = data[i] * scalar;
        return result;
    }

    friend CVector operator*(double scalar, const CVector& v) {
        return v * scalar;
    }

    CVector operator/(double scalar) const {
        if (scalar == 0) throw invalid_argument("Khong the chia cho 0!");
        CVector result(dim);
        for (int i = 0; i < dim; i++)
            result.data[i] = data[i] / scalar;
        return result;
    }

    CVector operator-() const {
        CVector result(dim);
        for (int i = 0; i < dim; i++)
            result.data[i] = -data[i];
        return result;
    }

    bool operator==(const CVector& other) const {
        if (dim != other.dim) return false;
        for (int i = 0; i < dim; i++)
            if (data[i] != other.data[i]) return false;
        return true;
    }

    bool operator!=(const CVector& other) const { return !(*this == other); }

    double tich_vo_huong(const CVector& other) const {
        if (dim != other.dim) throw invalid_argument("Khac so chieu!");
        double result = 0;
        for (int i = 0; i < dim; i++)
            result += data[i] * other.data[i];
        return result;
    }

    double do_dai() const {
        double sum = 0;
        for (int i = 0; i < dim; i++)
            sum += data[i] * data[i];
        return sqrt(sum);
    }

    CVector chuan_hoa() const {
        double len = do_dai();
        if (len == 0) throw invalid_argument("Khong the chuan hoa vector khong!");
        return *this / len;
    }

    double goc_voi(const CVector& other) const {
        double cos_theta = tich_vo_huong(other) / (do_dai() * other.do_dai());
        if (cos_theta > 1.0) cos_theta = 1.0;
        if (cos_theta < -1.0) cos_theta = -1.0;
        return acos(cos_theta) * 180.0 / M_PI;
    }

    bool vuong_goc(const CVector& other) const {
        return fabs(tich_vo_huong(other)) < 1e-9;
    }

    bool song_song(const CVector& other) const {
        if (dim != other.dim) return false;
        double ratio = 0;
        int first = -1;
        for (int i = 0; i < dim; i++) {
            if (other.data[i] != 0) { first = i; break; }
        }
        if (first == -1) return true;
        ratio = data[first] / other.data[first];
        for (int i = 0; i < dim; i++) {
            if (fabs(data[i] - ratio * other.data[i]) > 1e-9) return false;
        }
        return true;
    }

    CVector tich_co_huong(const CVector& other) const {
        if (dim != 3 || other.dim != 3)
            throw invalid_argument("Tich co huong chi ap dung cho vector 3 chieu!");
        CVector result(3);
        result.data[0] = data[1] * other.data[2] - data[2] * other.data[1];
        result.data[1] = data[2] * other.data[0] - data[0] * other.data[2];
        result.data[2] = data[0] * other.data[1] - data[1] * other.data[0];
        return result;
    }

    double khoang_cach(const CVector& other) const {
        return (*this - other).do_dai();
    }

    CVector chieu_len(const CVector& other) const {
        double scalar = tich_vo_huong(other) / (other.do_dai() * other.do_dai());
        return other * scalar;
    }
};

void in_duong(int n = 45) { for (int i = 0; i < n; i++) cout << "-"; cout << endl; }

int main() {
    cout << "=========================================" << endl;
    cout << "         DEMO LOP CVECTOR                " << endl;
    cout << "=========================================" << endl;

    CVector u, v;

    cout << "\n[1] NHAP VECTOR U:" << endl;
    u.nhap();

    cout << "\n[2] NHAP VECTOR V (cung so chieu " << u.sochieu() << "):" << endl;
    v = CVector(u.sochieu());
    for (int i = 0; i < u.sochieu(); i++) {
        cout << "  v[" << i << "] = ";
        cin >> v[i];
    }

    in_duong();
    cout << "KET QUA:" << endl;
    in_duong();

    u.xuat("u");
    v.xuat("v");

    in_duong();
    cout << "PHEP TOAN CO BAN:" << endl;
    in_duong();

    (u + v).xuat("u + v");
    (u - v).xuat("u - v");
    (-u).xuat("-u");

    double k;
    cout << "Nhap he so nhan scalar k: ";
    cin >> k;
    (u * k).xuat("u * k");
    (u / k).xuat("u / k");

    in_duong();
    cout << "DO DAI & CHUAN HOA:" << endl;
    in_duong();

    cout << "|u| = " << u.do_dai() << endl;
    cout << "|v| = " << v.do_dai() << endl;
    u.chuan_hoa().xuat("u chuan hoa");
    v.chuan_hoa().xuat("v chuan hoa");

    in_duong();
    cout << "TICH VA GOC:" << endl;
    in_duong();

    cout << "u . v (tich vo huong) = " << u.tich_vo_huong(v) << endl;
    cout << "Goc giua u va v = " << u.goc_voi(v) << " do" << endl;
    cout << "u va v vuong goc? " << (u.vuong_goc(v) ? "Co" : "Khong") << endl;
    cout << "u va v song song? " << (u.song_song(v) ? "Co" : "Khong") << endl;

    in_duong();
    cout << "KHOANG CACH & CHIEU:" << endl;
    in_duong();

    cout << "Khoang cach u va v = " << u.khoang_cach(v) << endl;
    u.chieu_len(v).xuat("Chieu cua u len v");

    if (u.sochieu() == 3) {
        in_duong();
        cout << "TICH CO HUONG (3D):" << endl;
        in_duong();
        u.tich_co_huong(v).xuat("u x v");
    }

    in_duong();
    cout << "SO SANH:" << endl;
    in_duong();

    cout << "u == v ? " << (u == v ? "Bang nhau" : "Khac nhau") << endl;
    cout << "u != v ? " << (u != v ? "Khac nhau" : "Bang nhau") << endl;

    in_duong();
    cout << "DEMO VECTOR NHIEU CHIEU (5D):" << endl;
    in_duong();

    CVector a({1, 2, 3, 4, 5});
    CVector b({5, 4, 3, 2, 1});
    a.xuat("a");
    b.xuat("b");
    (a + b).xuat("a + b");
    cout << "a . b = " << a.tich_vo_huong(b) << endl;
    cout << "Goc a, b = " << a.goc_voi(b) << " do" << endl;

    return 0;
}