#include "shapes.h"

int main() {
    int mode;
    cout << "Select mode:\n";
    cout << "  1. Triangle\n";
    cout << "  2. Polygon\n";

    shape* Shape = nullptr;
    while (true) {
        cout << "Choice: "; cin >> mode;
        if      (mode == 1) { Shape = new triangle(); break; }
        else if (mode == 2) { Shape = new polygon();  break; }
        cout << "Error! Please try again.\n\n";
        cin.clear(); cin.ignore(10000, '\n');
    }

    cout << "\n";
    Shape->input();
    cout << '\n';
    Shape->printInfo();

    double u, v;
    cout << "\nTranslation vector (u v): "; cin >> u >> v;
    Shape->printTransformed(translation(u, v));

    double deg;
    cout << "\nRotation angle (degrees): "; cin >> deg;
    Shape->printTransformed(rotation(deg));

    double factor;
    cout << "\nScale factor: "; cin >> factor;
    Shape->printTransformed(scaling(factor));

    delete Shape;
    return 0;
}