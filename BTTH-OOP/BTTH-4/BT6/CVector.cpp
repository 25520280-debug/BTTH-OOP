#include "CVector.h"

CVector::CVector() : components(1, 0.0) {}

CVector::CVector(int n) {
    if (n < 1) throw invalid_argument("Dimension must be >= 1.");
    components.assign(n, 0.0);
}

CVector::CVector(const vector<double>& v) {
    if (v.empty()) throw invalid_argument("Dimension must be >= 1.");
    components = v;
}

int CVector::dim() const { return (int)components.size(); }

double& CVector::operator[](int i) {
    if (i < 0 || i >= dim()) throw out_of_range("Index out of range.");
    return components[i];
}

const double& CVector::operator[](int i) const {
    if (i < 0 || i >= dim()) throw out_of_range("Index out of range.");
    return components[i];
}

void CVector::input() {
    int n;
    while (true) {
        cout << "Enter number of dimensions: ";
        if (cin >> n && n >= 1) break;
        cout << "Error! Dimension must be a positive integer.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    components.resize(n);
    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "  v[" << i + 1 << "]: ";
            if (cin >> components[i]) break;
            cout << "Error! Please enter a valid number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

void CVector::display() const {
    cout << "(";
    for (int i = 0; i < dim(); i++) {
        cout << components[i];
        if (i < dim() - 1) cout << ", ";
    }
    cout << ")" << endl;
}

CVector CVector::operator+(const CVector& other) const {
    if (dim() != other.dim()) throw invalid_argument("Vectors must have the same dimension.");
    CVector result(dim());
    for (int i = 0; i < dim(); i++)
        result[i] = components[i] + other.components[i];
    return result;
}

CVector CVector::operator-(const CVector& other) const {
    if (dim() != other.dim()) throw invalid_argument("Vectors must have the same dimension.");
    CVector result(dim());
    for (int i = 0; i < dim(); i++)
        result[i] = components[i] - other.components[i];
    return result;
}

CVector CVector::operator*(double scalar) const {
    CVector result(dim());
    for (int i = 0; i < dim(); i++) {
        result[i] = components[i] * scalar;
        if (result[i] == 0.0) result[i] = 0.0; 
    }
    return result;
}

CVector operator*(double scalar, const CVector& v) {
    return v * scalar;
}

CVector CVector::operator-() const {
    CVector result(dim());
    for (int i = 0; i < dim(); i++)
        result[i] = -components[i];
    return result;
}

double CVector::dot(const CVector& other) const {
    if (dim() != other.dim()) throw invalid_argument("Vectors must have the same dimension.");
    double sum = 0.0;
    for (int i = 0; i < dim(); i++)
        sum += components[i] * other.components[i];
    return sum;
}

double CVector::norm() const {
    return sqrt(dot(*this));
}

bool CVector::operator==(const CVector& other) const {
    if (dim() != other.dim()) return false;
    for (int i = 0; i < dim(); i++)
        if (abs(components[i] - other.components[i]) > 1e-9) return false;
    return true;
}

bool CVector::operator!=(const CVector& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const CVector& v) {
    os << "(";
    for (int i = 0; i < v.dim(); i++) {
        os << v.components[i];
        if (i < v.dim() - 1) os << ", ";
    }
    os << ")";
    return os;
}

istream& operator>>(istream& is, CVector& v) {
    int n;
    if (!(is >> n) || n < 1) {
        is.setstate(ios::failbit);
        return is;
    }
    v.components.resize(n);
    for (int i = 0; i < n; i++)
        is >> v.components[i];
    return is;
}