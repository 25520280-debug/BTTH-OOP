#include <iostream>
#include <stdexcept>
#include <cmath>
#include <sstream>
 
using namespace std;
 
class SoPhuc {
private:
    double thucPhan;   // phần thực  (a)
    double aoPhan;     // phần ảo   (b)
 
public:
    SoPhuc(double a = 0.0, double b = 0.0)
        : thucPhan(a), aoPhan(b) {}
 
    double getThuc() const { return thucPhan; }
    double getAo()   const { return aoPhan;   }
 
    double modulus() const {
        return sqrt(thucPhan * thucPhan + aoPhan * aoPhan);
    }
 
    SoPhuc operator+(const SoPhuc& other) const {
        return SoPhuc(thucPhan + other.thucPhan,
                      aoPhan   + other.aoPhan);
    }
 
    SoPhuc operator-(const SoPhuc& other) const {
        return SoPhuc(thucPhan - other.thucPhan,
                      aoPhan   - other.aoPhan);
    }
 
    SoPhuc operator*(const SoPhuc& other) const {
        return SoPhuc(
            thucPhan * other.thucPhan - aoPhan * other.aoPhan,
            thucPhan * other.aoPhan   + aoPhan * other.thucPhan
        );
    }
 
    SoPhuc operator/(const SoPhuc& other) const {
        double mauSo = other.thucPhan * other.thucPhan
                     + other.aoPhan   * other.aoPhan;
        if (mauSo == 0.0) {cout << "Loi: Chia cho so phuc bang 0!"; return; }
        else return SoPhuc(
            (thucPhan * other.thucPhan + aoPhan * other.aoPhan) / mauSo,
            (aoPhan * other.thucPhan - thucPhan * other.aoPhan) / mauSo
        );
    }

    bool operator==(const SoPhuc& other) const {
        return (thucPhan == other.thucPhan) && (aoPhan == other.aoPhan);
    }
 
    bool operator!=(const SoPhuc& other) const {
        return !(*this == other);
    }
 
    friend ostream& operator<<(ostream& os, const SoPhuc& z) {
        os << z.thucPhan;
        if (z.aoPhan >= 0)
            os << " + " <<  z.aoPhan << "i";
        else
            os << " - " << -z.aoPhan << "i";
        return os;
    }
 
    friend istream& operator>>(istream& is, SoPhuc& z) {
        cout << "  Nhap phan thuc: ";
        is >> z.thucPhan;
        cout << "  Nhap phan ao  : ";
        is >> z.aoPhan;
        return is;
    }
};
 
int main() {

    SoPhuc z1, z2;
 
    cout << "z1 + z2 = " << (z1 + z2) << "\n";
    cout << "z1 - z2 = " << (z1 - z2) << "\n";
    cout << "z1 * z2 = " << (z1 * z2) << "\n";
    cout << "z1 / z2 = " << (z1 / z2) << "\n\n";
 
    cout << "--- Phep toan voi so thuc z3 = 5 ---\n";
    cout << "z1 + z3 = " << (z1 + z3) << "\n";
    cout << "z1 * z3 = " << (z1 * z3) << "\n\n";
 
    SoPhuc z3;
    cout << "z1 == z2 : " << (z1 == z2 ? "True" : "False") << "\n";
    cout << "za != zc : " << (z1 != z3 ? "True" : "False") << "\n\n";
 
    cout << "--- Chia cho so phuc bang 0 ---\n";
    try {
        SoPhuc zero(0, 0);
        SoPhuc result = z1 / zero;
        cout << "Ket qua: " << result << "\n";
    } catch (const runtime_error& e) {
        cout << e.what() << "\n";
    }
    cout << "\n";
 
    // --- Nhập từ bàn phím ---
    cout << "--- Nhap so phuc tu ban phim ---\n";
    SoPhuc zNhap;
    cin >> zNhap;
    cout << "So phuc vua nhap: " << zNhap << "\n";
    cout << "z1 + zNhap = " << (z1 + zNhap) << "\n";
 
    return 0;
}