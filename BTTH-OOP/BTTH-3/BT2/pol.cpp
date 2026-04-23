#include <iostream>
#include <vector>
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
        friend ostream& operator << (ostream& out, vert p) {
            out << "( " << p.x << " ; " << p.y << " )\n";
            return out; 
        }
        friend vert operator + (double t, vert& p) { return vert(p.x+t,p.y+t); }
        friend vert operator * (double t, vert& p) { return vert(p.x*t,p.y*t); }
        friend vert operator / (double t, vert& p) { return vert(p.x/t,p.y/t); }
        
        vert Revolve(double alpha) {
            double r = alpha * M_PI / 180;
            return vert(this->x*cos(r) - this->y*sin(r),this->x*sin(r)+this->y*cos(r));
        }
        vert Translate(double a, double b) {
        return vert(this->x+a,this->y+b);
    }

};

class edge : public vert {
    public :
        vert a,b;
        edge(){}
        edge(vert A, vert B) : a(A), b(B) {}

        const double getLength() {
            double disX = a.x - b.x, disY = a.y - b.y;
            return sqrtf(disX*disX + disY*disY);
        }
};

class pol : protected edge {
    private:
        vector <vert> verts;
        vector <edge> edges;
    public:
        pol(){}
        pol(vector <vert> p) : verts(p) {
            edges.resize(verts.size());
            int i = 0;
            for (; i < verts.size()-1; i++){ edges[i] = edge(verts[i],verts[i+1]); }
            edges[i+1] = edge(verts[i++],verts[0]);
        }
};