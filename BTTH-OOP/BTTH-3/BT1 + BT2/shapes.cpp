#include "shapes.h"

// ============================================================
//  Utility
// ============================================================
double cleanNum(double x) { return (fabs(x) < 1e-9) ? 0 : x; }

// ============================================================
//  vertex
// ============================================================
vertex::vertex() {}
vertex::vertex(double x, double y) : x(x), y(y) {}

double vertex::distance(const vertex& other) {
    double dis_X = this->x - other.x, dis_Y = this->y - other.y;
    return sqrt(dis_X*dis_X + dis_Y*dis_Y);
}

istream& operator>>(istream& in, vertex& p) {
    while (true) {
        if (in >> p.x >> p.y) break;
        cout << "Error! Please try again.\n\n";
        cin.clear(); cin.ignore(10000, '\n');
    }
    return in;
}

ostream& operator<<(ostream& out, const vertex& p) {
    out << "( " << cleanNum(p.x) << " ; " << cleanNum(p.y) << " )";
    return out;
}

// ============================================================
//  translation
// ============================================================
translation::translation(double u, double v) : u(u), v(v) {}

vertex translation::apply(const vertex& p) const {
    return vertex(p.x + u, p.y + v);
}

string translation::name() const { return "Translation"; }

// ============================================================
//  rotation
// ============================================================
rotation::rotation(const double& degrees) : deg(degrees) {}

vertex rotation::apply(const vertex& p) const {
    double rad = deg * M_PI / 180;
    return vertex(p.x*cos(rad) - p.y*sin(rad),
                  p.x*sin(rad) + p.y*cos(rad));
}

string rotation::name() const { return "Rotation"; }

// ============================================================
//  scaling
// ============================================================
scaling::scaling(double t) : t(t) {}

vertex scaling::apply(const vertex& p) const {
    if (t < 0) return vertex(p.x / (-t), p.y / (-t));
    else       return vertex(p.x * t,    p.y * t);
}

string scaling::name() const { return "Scaling"; }

// ============================================================
//  shape
// ============================================================
void shape::printTransformed(const transformation& t) const {
    cout << "\nAfter " << t.name() << " :\n";
    applyAndPrint(t);
}

// ============================================================
//  triangle
// ============================================================
void triangle::build() {
    a = B.distance(C);
    b = A.distance(C);
    c = B.distance(A);
    p = (a + b + c) / 2;
}

string triangle::triType() const {
    const double eps = 1e-9;
    if (fabs(a-b) < eps && fabs(b-c) < eps)                    return "Equilateral";
    if (fabs(a-b) < eps || fabs(a-c) < eps || fabs(b-c) < eps) return "Isosceles";
    if (fabs(a*a+b*b-c*c) < eps ||
        fabs(a*a+c*c-b*b) < eps ||
        fabs(b*b+c*c-a*a) < eps)                               return "Right";
    return "Scalene";
}

void triangle::applyAndPrint(const transformation& t) const {
    triangle result(t.apply(A), t.apply(B), t.apply(C));
    result.printInfo();
}

triangle::triangle() { build(); }
triangle::triangle(vertex A, vertex B, vertex C) : A(A), B(B), C(C) { build(); }

bool triangle::check() { return (p*(p-a)*(p-b)*(p-c) > 1e-9); }

void triangle::input() {
    while (true) {
        vertex t1, t2, t3;
        cout << "First vertex  : "; cin >> t1;
        cout << "Second vertex : "; cin >> t2;
        cout << "Third vertex  : "; cin >> t3;
        triangle temp(t1, t2, t3);
        temp.build();
        if (temp.check()) {
            A = t1; B = t2; C = t3; build();
            break;
        }
        cout << "Error! Cannot form a triangle. Please try again.\n\n";
    }
}

double triangle::area() const { return sqrt(p*(p-a)*(p-b)*(p-c)); }
double triangle::per()  const { return p * 2; }

void triangle::printInfo() const {
    cout << fixed << setprecision(2);
    cout << "Coordinates:\t" << A << ' ' << B << ' ' << C << '\n';
    cout << "Type:\t\t"      << triType() << '\n';
    cout << "Area:\t\t"      << area()    << '\n';
    cout << "Perimeter:\t"   << per()     << '\n';
}

// ============================================================
//  polygon
// ============================================================
bool polygon::collinear(const vertex& a, const vertex& b, const vertex& c) {
    double cross = (b.x - a.x) * (c.y - a.y)
                 - (b.y - a.y) * (c.x - a.x);
    return (fabs(cross) < 1e-9);
}

bool polygon::check(const vector<vertex>& points) {
    int n = points.size();
    for (int i = 0; i < n; i++) {
        const vertex& a = points[i];
        const vertex& b = points[(i+1) % n];
        const vertex& c = points[(i+2) % n];
        if (collinear(a, b, c)) return false;
    }
    return true;
}

void polygon::applyAndPrint(const transformation& t) const {
    vector<vertex> newVerts;
    for (const vertex& v : verticles)
        newVerts.push_back(t.apply(v));
    polygon result(newVerts);
    result.printInfo();
}

polygon::polygon() {}
polygon::polygon(const vector<vertex>& points) : verticles(points) {}

void polygon::input() {
    while (true) {
        int n;
        cout << "Number of vertices (>= 3) : "; cin >> n;
        if (n < 3) {
            cout << "Error! Please try again.\n\n";
            continue;
        }

        vector<vertex> temp(n);
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i+1 << ": "; cin >> temp[i];
        }

        if (check(temp)) { verticles = temp; break; }
        cout << "Error! 3 consecutive collinear vertices found. Try again.\n\n";
    }
}

double polygon::per() const {
    double total = 0;
    int n = verticles.size();
    for (int i = 0; i < n; i++) {
        const vertex& a = verticles[i];
        const vertex& b = verticles[(i+1) % n];
        double dx = a.x - b.x, dy = a.y - b.y;
        total += sqrt(dx*dx + dy*dy);
    }
    return total;
}

double polygon::area() const {
    double sum = 0;
    int n = verticles.size();
    for (int i = 0; i < n; i++) {
        const vertex& a = verticles[i];
        const vertex& b = verticles[(i+1) % n];
        sum += a.x * b.y - b.x * a.y;
    }
    return fabs(sum) / 2.0;
}

void polygon::printInfo() const {
    cout << fixed << setprecision(2);
    cout << "Vertices  : ";
    for (const vertex& v : verticles) cout << v << " ";
    cout << "\nSides     : " << verticles.size();
    cout << "\nArea      : " << area();
    cout << "\nPerimeter : " << per() << "\n";
}