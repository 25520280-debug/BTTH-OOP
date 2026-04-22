#include <iostream>
#include <cmath>
using namespace std;

class vert {
    public:
        double x, y;

        vert(){}
        vert(double a, double b) : x(a), y(b) {}

        friend istream& operator >> (istream& in, vert& p) {
            in >> p.x >> p.y;
            return in;
        }
        friend vert operator * (vert &p, double m) {
            return vert(p.x * m, p.y * m);
        }
        friend vert operator / (vert &p, double m) {
            return vert(p.x / m, p.y / m);
        }
        friend ostream& operator << (ostream& out, vert p) {
            out << "( " << p.x << " ; " << p.y << " )\n";
            return out;
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
        void Revolve(double t) {
            this->x = this->x*cos((M_PI*t)/180) - this->y*sin((M_PI*t)/180);
            this->y = this->x*sin((M_PI*t)/180) + this->y*cos((M_PI*t)/180);        
        }
        void Translate(double a, double b) {
            this->x += a, this->y += b;
        }
};

class edge : public vert {
    public:
        vert a, b;
        edge(){}
        edge(vert x, vert y) : a(x), b(y) {}
        double getLength() {return sqrtf((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));}
};

class tri : protected edge{
    private :
        vert i, j, k;
        edge a, b, c;
    public:
        tri(){}
        double AB() {return c.getLength();};
        double AC() {return b.getLength();};
        double BC() {return a.getLength();};
        double p()  {return (AB() + AC() + BC())/2;};
        double check() {return p() * (p() - AB() )*(p() - AC() )*(p() - BC());};
        void Input() {
            while (true) {
                cout << "Please enter the first vertex : "; InputVertex(this->i);
                cout << "\nPlease enter the second vertex : "; InputVertex(this->j);
                cout << "\nPlease enter the third vertex : "; InputVertex(this->k); 
                this->a = edge(j,k), this->b = edge(i,k), this->c = edge(i,j);
                if (this->check() > 0) break;
                else cout << "Error : These coordinates cannot build up a triangle. Please try again!\n";
            }
        }

        void triType() {
            if (AB() - AC() - BC() == 0) {
                cout << "This is an equilateral triangle.\n";
                return;
            }
            else if ((AB() - AC() == 0) || (AB() - BC() == 0) || (AC() - BC() == 0)) {
                cout << "This is an isosceles triangle.\n";
                return;
            }
            else if ((AB() *AB() + AC() *AC() == BC() *BC())||(AB() *AB() + BC() *BC() == AC() *AC() )||(BC() *BC() + AC() *AC() == AB() *AB())) {
                cout << "This is a right triangle.\n";
                return;
            }
            else {
                cout << "This is a scalene triangle.\n";
                return;
            }
        }

        double triCir() { return p()*2; }

        double triArea() {
            return sqrtf(p() * (p() - AB())*(p() - AC())*(p() - BC()));
        }

        void printStat() {
            cout << "\nCoordinates :\n A" << this->i << " B" << this->j << " C" << this->k;
        }

        void ZoomIn(double x) {
            this->i = this->i*x, this->j = this->j*x, this->k = this->k*x;
            cout << "\nAfter zoom in :\n"; printStat();
        }
        
        void ZoomOut(double x) {
            this->i = this->i/x, this->j = this->j/x, this->k = this->k/x;
            cout << "\nAfter zoom out :\n"; this->printStat();
        }

        void triRevolve(double t) {
            this->i.Revolve(t), this->j.Revolve(t), this->k.Revolve(t);
            cout << "\nAfter revolution :\n"; this->printStat();
        }

        void triTranslate(double a, double b) {
            this->i.Translate(a,b), this->j.Translate(a,b), this->k.Translate(a,b);
            cout << "\nAfter translation :\n"; this->printStat();
        }

        void printAll() {
            this->triType();
            this->printStat();
            cout << "Area : " << this->triArea();
            cout << "\nCircumference : " << this->triCir();
            cout << "\nHow much do you want to scale this triangle?\n";
            double a; 
            while (true) {
                if (cin >> a) break;
                else {
                    cout << "Error! Please try again!\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
            }
            if (a > 0) this->ZoomIn(fabs(a));
            else if (a < 0) this->ZoomOut(fabs(a));

            cout << "\nAfter that, how much do you want to shift the triangle along the x and y axes?\n";
            double m,n;
            while (true) {
                if (cin >> m >> n) break;
                else {
                    cout << "Error! Please try again!\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
            }
            this->triTranslate(m,n);

            double alpha;
            cout << "\nAfter that, how many degrees do you want to revolve this triangle?\n";
            while (true) {
                if (cin >> alpha) break;
                else {
                    cout << "Error! Please try again!\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
            }
            this->triRevolve(alpha);
        }

};

int main() {
    tri t;
    t.Input();
    t.printAll();
    return 0;
}