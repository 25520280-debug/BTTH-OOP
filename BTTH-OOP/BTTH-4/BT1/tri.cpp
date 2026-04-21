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
        void InputVertex(vert& x) {
            while (true) {
                if (cin >> x) break;
                else {
                    cout << "Error! Please try again!\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
        }
    }
}
};

class edge {
    private:
        vert a;
        vert b;
    public:
        edge(vert x, vert y) : a(x), b(y) {}
        const double getLength() {return sqrtf((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));}
};

class tri : protected vert{
    private :
        edge a;
        edge b;
        edge c;
        double AB = c.getLength(), AC = b.getLength(), BC = a.getLength();
    public:
        double p = (AB+AC+BC)/2;
        double check = p * (p - AB)*(p - AC)*(p - BC);

        void Input() {
            while (true) {
                vert x, y, z;
                cout << "Please enter the first vertex : "; InputVertex(x);
                cout << "\nPlease enter the second vertex : "; InputVertex(y);
                cout << "\nPlease enter the third vertex : "; InputVertex(z); 
                c = edge(x,y), a = edge(y,z), b = edge(z,x);
                if (check > 0) break; 
            }
        }

        void triType() {
            if (AB - AC - BC == 0) {
                cout << "This is an equilateral triangle.\n";
                return;
            }
            else if ((AB - AC == 0) || (AB - BC == 0) || (AC - BC == 0)) {
                cout << "This is an isosceles triangle.\n";
                return;
            }
            else if ((AB*AB + AC*AC == BC*BC)||(AB*AB + BC*BC == AC*AC)||(BC*BC+ AC*AC == AB*AB)) {
                cout << "This is an right triangle.\n";
                return;
            }
            else {
                cout << "This is an scalene triangle.\n";
                return;
            }
        }

        double triCir() { return p*2; }

        double triArea() {
            return sqrtf(p * (p - AB)*(p - AC)*(p - BC));
        }

        
};