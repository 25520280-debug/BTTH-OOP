#include "Polynomial.h"
 
Polynomial::Polynomial() : degree(0), coeffs(1, 0.0) {}
Polynomial::Polynomial(int n) : degree(n), coeffs(n + 1, 0.0) {}
 
void Polynomial::input() {
    while (true) {
        cout << "Enter degree of polynomial: ";
        if (cin >> degree && degree >= 0) {
            coeffs.resize(degree + 1);
            for (int i = 0; i <= degree; i++) {
                cout << "  a" << i + 1 << " (x^" << degree - i << "): ";
                cin >> coeffs[i];
            }
            break;
        }
        else {
            cout << "Error! Please try again.\n";
            cin.clear();    cin.ignore(10000,'\n');
        }
    }
}
 
double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (int i = 0; i <= degree; i++) {
        result += coeffs[i] * pow(x, degree - i);
    }
    return result;
}
 
void Polynomial::display() const {
    bool first = true;
    for (int i = 0; i <= degree; i++) {
        double c = coeffs[i];
        int exp = degree - i;
        if (c == 0.0) continue;
 
        if (!first && c > 0) cout << " + ";
        else if (c < 0) cout << " - ";
 
        double absC = abs(c);
        if (exp == 0) {
            cout << absC;
        } else if (exp == 1) {
            if (absC != 1.0) cout << absC;
            cout << "x";
        } else {
            if (absC != 1.0) cout << absC;
            cout << "x^" << exp;
        }
        first = false;
    }
    if (first) cout << "0";
    cout << endl;
}
 
Polynomial Polynomial::add(const Polynomial& other) const {
    int maxDeg = max(degree, other.degree);
    Polynomial result(maxDeg);
    for (int i = 0; i <= maxDeg; i++) {
        double a = (i <= degree) ? coeffs[degree - i] : 0.0;
        double b = (i <= other.degree) ? other.coeffs[other.degree - i] : 0.0;
        result.coeffs[maxDeg - i] = a + b;
    }
    return result;
}
 
Polynomial Polynomial::subtract(const Polynomial& other) const {
    int maxDeg = max(degree, other.degree);
    Polynomial result(maxDeg);
    for (int i = 0; i <= maxDeg; i++) {
        double a = (i <= degree) ? coeffs[degree - i] : 0.0;
        double b = (i <= other.degree) ? other.coeffs[other.degree - i] : 0.0;
        result.coeffs[maxDeg - i] = a - b;
    }
    return result;
}
 
bool askYesNo(const string& question) {
    char ch;
    cout << question << " (y/n): ";
    cin >> ch;
    return (ch == 'y' || ch == 'Y');
}