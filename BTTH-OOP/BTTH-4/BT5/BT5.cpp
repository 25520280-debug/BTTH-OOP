#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <string>
using namespace std;

class Polynomial {
private:
    vector<double> coeffs;

    void trim() {
        while (coeffs.size() > 1 && coeffs.back() == 0.0)
            coeffs.pop_back();
    }

public:
    Polynomial() : coeffs(1, 0.0) {}

    Polynomial(const vector<double>& c) : coeffs(c) {
        if (coeffs.empty()) coeffs.push_back(0.0);
        trim();
    }

    Polynomial(double constant) : coeffs(1, constant) {}

    int degree() const {
        return (int)coeffs.size() - 1;
    }

    double getCoeff(int i) const {
        if (i < 0 || i >= (int)coeffs.size()) return 0.0;
        return coeffs[i];
    }

    void setCoeff(int i, double val) {
        if (i < 0) return;
        if (i >= (int)coeffs.size())
            coeffs.resize(i + 1, 0.0);
        coeffs[i] = val;
        trim();
    }

    double leadingCoeff() const {
        return coeffs.back();
    }

    bool isZero() const {
        return coeffs.size() == 1 && coeffs[0] == 0.0;
    }

    double eval(double x) const {
        double result = 0.0;
        for (int i = degree(); i >= 0; --i)
            result = result * x + coeffs[i];
        return result;
    }

    double operator()(double x) const {
        return eval(x);
    }

    Polynomial operator+(const Polynomial& other) const {
        int maxDeg = max(degree(), other.degree());
        vector<double> res(maxDeg + 1, 0.0);
        for (int i = 0; i <= maxDeg; ++i)
            res[i] = getCoeff(i) + other.getCoeff(i);
        return Polynomial(res);
    }

    Polynomial operator-(const Polynomial& other) const {
        int maxDeg = max(degree(), other.degree());
        vector<double> res(maxDeg + 1, 0.0);
        for (int i = 0; i <= maxDeg; ++i)
            res[i] = getCoeff(i) - other.getCoeff(i);
        return Polynomial(res);
    }

    Polynomial operator*(const Polynomial& other) const {
        int newDeg = degree() + other.degree();
        vector<double> res(newDeg + 1, 0.0);
        for (int i = 0; i <= degree(); ++i)
            for (int j = 0; j <= other.degree(); ++j)
                res[i + j] += coeffs[i] * other.coeffs[j];
        return Polynomial(res);
    }

    Polynomial operator*(double scalar) const {
        vector<double> res = coeffs;
        for (double& c : res) c *= scalar;
        return Polynomial(res);
    }

    pair<Polynomial, Polynomial> divmod(const Polynomial& divisor) const {
        if (divisor.isZero())
            throw invalid_argument("Khong the chia cho da thuc 0!");

        vector<double> quot;
        vector<double> rem = coeffs;

        int remDeg = degree();
        int divDeg = divisor.degree();

        while (remDeg >= divDeg) {
            double factor = rem[remDeg] / divisor.coeffs[divDeg];
            quot.insert(quot.begin(), factor);
            for (int i = 0; i <= divDeg; ++i)
                rem[remDeg - divDeg + i] -= factor * divisor.coeffs[i];
            rem.pop_back();
            remDeg--;
        }

        if (quot.empty()) quot.push_back(0.0);
        return { Polynomial(quot), Polynomial(rem) };
    }

    Polynomial operator/(const Polynomial& other) const {
        return divmod(other).first;
    }

    Polynomial operator%(const Polynomial& other) const {
        return divmod(other).second;
    }

    Polynomial derivative() const {
        if (degree() == 0) return Polynomial(0.0);
        vector<double> res(degree());
        for (int i = 1; i <= degree(); ++i)
            res[i - 1] = i * coeffs[i];
        return Polynomial(res);
    }

    Polynomial integral() const {
        vector<double> res(degree() + 2, 0.0);
        for (int i = 0; i <= degree(); ++i)
            res[i + 1] = coeffs[i] / (i + 1);
        return Polynomial(res);
    }

    double integral(double a, double b) const {
        Polynomial F = integral();
        return F.eval(b) - F.eval(a);
    }

    bool operator==(const Polynomial& other) const {
        return coeffs == other.coeffs;
    }

    bool operator!=(const Polynomial& other) const {
        return !(*this == other);
    }

    Polynomial compose(const Polynomial& q) const {
        Polynomial result(0.0);
        Polynomial qPow(1.0);
        for (int i = 0; i <= degree(); ++i) {
            result = result + qPow * coeffs[i];
            if (i < degree()) qPow = qPow * q;
        }
        return result;
    }

    string toString() const {
        if (isZero()) return "0";
        string s;
        for (int i = degree(); i >= 0; --i) {
            double c = coeffs[i];
            if (c == 0.0) continue;

            if (!s.empty())
                s += (c > 0 ? " + " : " - ");
            else if (c < 0)
                s += "-";

            double absC = fabs(c);

            if (i == 0) {
                s += to_string((int)absC == absC ? (int)absC : absC);
            } else {
                if (absC != 1.0)
                    s += to_string((int)absC == absC ? (long long)absC : absC);
                s += "x";
                if (i > 1) s += "^" + to_string(i);
            }
        }
        return s;
    }

    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        os << p.toString();
        return os;
    }
};

int main() {
    cout << "=== DEMO LOP DA THUC ===\n\n";

    Polynomial P({1, 3, 2});
    Polynomial Q({2, 1});
    Polynomial R({0, 0, 1});

    cout << "P(x) = " << P << "  (bac " << P.degree() << ")\n";
    cout << "Q(x) = " << Q << "  (bac " << Q.degree() << ")\n";
    cout << "R(x) = " << R << "  (bac " << R.degree() << ")\n\n";

    cout << "--- Phep toan co ban ---\n";
    cout << "P + Q = " << (P + Q) << "\n";
    cout << "P - Q = " << (P - Q) << "\n";
    cout << "P * Q = " << (P * Q) << "\n";
    cout << "P * 3 = " << (P * 3) << "\n\n";

    cout << "--- Phep chia ---\n";
    auto [quot, rem] = P.divmod(Q);
    cout << "P / Q = " << quot << "  du " << rem << "\n\n";

    cout << "--- Tinh gia tri ---\n";
    cout << "P(2) = " << P.eval(2) << "\n";
    cout << "Q(-1) = " << Q(-1) << "\n\n";

    cout << "--- Dao ham & tich phan ---\n";
    cout << "P'(x)  = " << P.derivative() << "\n";
    cout << "P''(x) = " << P.derivative().derivative() << "\n";
    cout << "Int(P) = " << P.integral() << " + C\n";
    cout << "Int(P, 0, 1) = " << P.integral(0, 1) << "\n\n";

    cout << "--- Ham hop ---\n";
    cout << "P(Q(x)) = " << P.compose(Q) << "\n\n";

    cout << "--- So sanh ---\n";
    cout << "P == Q ? " << (P == Q ? "true" : "false") << "\n";
    cout << "P == P ? " << (P == P ? "true" : "false") << "\n\n";

    cout << "--- Da thuc dac biet ---\n";
    Polynomial zero;
    Polynomial constant(5.0);
    cout << "Da thuc 0:     " << zero   << "  (bac " << zero.degree()     << ")\n";
    cout << "Hang so 5:     " << constant << "  (bac " << constant.degree() << ")\n";

    return 0;
}