#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double cleanNum(double x) {
    if (fabs(x) < 1e-9) return 0;  
    else return x;
}

class vert {
    private : 
        double x, y;
    public:
        vert(){}
        vert(double a, double b): x(a), y(b) {}

        double distance_X(const vert& other) {return this->x - other.x;}
        double distance_Y(const vert& other) {return this->y - other.y;}

        friend istream& operator >> (istream& in, vert& p) {
            while (true) {
                if (in >> p.x >> p.y) break;
                else {
                    cout << "Error! Please try again.\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
            }
            return in;
        }
        friend ostream& operator << (ostream& out, vert& p) {
            out << "( " << cleanNum(p.x) << " ; " << cleanNum(p.y) << " )";
            return out;
        }
        friend vert operator + (vert& p, double t) {return vert(p.x+t, p.y+t); }
        friend vert operator * (vert& p, double t) {return vert(p.x*t, p.y*t); }
        friend vert operator / (vert& p, double t) {return vert(p.x/t, p.y/t); }

        vert Translate(double a, double b) {return vert(this->x + a, this->y + b); }
        vert Revolve(double alpha) {
            double rad = (alpha/180)*M_PI;
            return vert(this->x*cos(rad) - this->y*sin(rad), this->x*sin(rad) + this->y*cos(rad));
        }
        vert ZoomIn(double t) {return vert(this->x*t,this->y*t); }
        vert ZoomOut(double t) {return vert(this->x/t,this->y/t); }
};

class edge {
    private:
        vert a, b;
    public:
        edge(){}
        edge(vert A, vert B) : a(A), b(B) {}
        
        double getLength() {
            double dis_X = a.distance_X(b), dis_Y = a.distance_Y(b);
            return sqrt(dis_X*dis_X + dis_Y*dis_Y);
        }
};

class tri{
    private :
        vert i, j, k;
        edge a, b, c;
        double p;
    public :
        tri(){}
        tri(vert m, vert n, vert o) : i(m), j(n), k(o), a(edge(j,k)), b(edge(i,k)), c(edge(i,j)) {
            this->p = (a.getLength() + b.getLength() + c.getLength()) / 2;
        }
        void Input() {
            cout << "Please input the coordinate of the first vertex: "; cin >> this->i;
            cout << "Please input the coordinate of the second vertex: "; cin >> this->j;
            cout << "Please input the coordinate of the third vertex: "; cin >> this->k;
            this->a = edge(j,k), this->b = edge(i,k), this->c = edge(i,j);
            this->p = (this->a.getLength() + this->b.getLength() + this->c.getLength())/2; 
        }
        bool check() {
            if (this->p*
                (this->p - this->a.getLength())*
                (this->p - this->b.getLength())*
                (this->p - this->c.getLength()) > 0) return true;
            else return false;
        }
        void triType() {
            double A = a.getLength(), B = b.getLength(), C = c.getLength();
            const double eps = 1e-9;
            bool isRight = fabs(A*A + B*B - C*C) < eps ||
                        fabs(A*A + C*C - B*B) < eps ||
                        fabs(B*B + C*C - A*A) < eps;
            bool isEquil = fabs(A-B) < eps && fabs(B-C) < eps;
            bool isIsoc  = fabs(A-B) < eps || fabs(A-C) < eps || fabs(B-C) < eps;

            if (isEquil)      cout << "\nThis is an equilateral triangle.\n";
            else if (isIsoc)  cout << "\nThis is an isosceles triangle.\n";
            else if (isRight) cout << "\nThis is a right triangle.\n";
            else              cout << "\nThis is a scalene triangle.\n";
        }
        double triArea() {return sqrt(this->p*
                                        (this->p - this->a.getLength())*
                                        (this->p - this->b.getLength())*
                                        (this->p - this->c.getLength())); }
        double triCir() {return this->p*2;}
        void printStat() {
            cout << "Coordinates:\n" << fixed << setprecision(2) << this->i << ' ' << this->j << ' ' << this->k;
            cout << "\nArea : " << fixed << setprecision(2) << this->triArea();
            cout << "\nCircumference : " << fixed << setprecision(2) << this->triCir();
        }
        void triRevolution(double alpha) {
            tri temp (this->i.Revolve(alpha), this->j.Revolve(alpha), this->k.Revolve(alpha));
            cout << "After the revolution :\n" << fixed << setprecision(2) << temp.i << temp.j << temp.k; 
        }
        void triTranslation(double u, double v) {
            tri temp (this->i.Translate(u,v), this->j.Translate(u,v), this->k.Translate(u,v));
            cout << "After the translation :\n" << fixed << setprecision(2) << temp.i << temp.j << temp.k;
        }
        void triZoom(double t) {
            if (t == 0) return;
            else if (t > 0) {
                tri temp (this->i.ZoomIn(t),this->j.ZoomIn(t), this->k.ZoomIn(t)); 
                cout << "\nAfter zoom in :\n"; temp.printStat();
            }
            else {
                tri temp (this->i.ZoomOut(-t),this->j.ZoomOut(-t), this->k.ZoomOut(-t)); 
                cout << "\nAfter zoom out :\n"; temp.printStat();
            }   
        }

        void printAll() {
            triType(); printStat();
            double p,q;
            cout << "\nHow do you want to translate this triangle : "; cin >> p >> q;
            triTranslation(p,q);
            double rev,zoom;
            cout << "\nHow many degrees do you want to rotate this triangle : "; cin >> rev;
            triRevolution(rev);
            cout << "\nBy what scale factor do you want to enlarge this triangle : "; cin >> zoom;
            triZoom(zoom);
        }
} ;

int main(){
    tri p;
    while (true) {
        p.Input();
        if (p.check()) break;
        else cout << "Error! Cannot build up a triangle, please try again!\n";
    }
    p.printAll();
    return 0;
}