#include <iostream>
#include <cmath>
using namespace std;

class vert {
    public:
        double x;
        double y;
        vert(): x(0), y(0) {}
        vert(double a, double b) : x(a), y(b) {}

        friend istream& operator >> (istream& in, vert& p) {
            in >> p.x >> p.y;
            return in;
        }
};

class edge : protected vert{
    private:
        vert a;
        vert b;
    public:
        void Input() {
            cout << "Enter the coordinate of first vertex : "; cin >> a;
            cout << "\nEnter the coordinate of second vertex : "; cin >> b;
        }
        const double getLength() {return sqrtf((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));}
};