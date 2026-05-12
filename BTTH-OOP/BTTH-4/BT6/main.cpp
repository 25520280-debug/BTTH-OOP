#include "cvector.h"

int main() {
    cout << "=== Vector V1 ===" << endl;
    CVector v1;
    v1.input();
    cout << "V1 = " << v1 << endl;
    cout << "Norm of V1: " << v1.norm() << endl;

    cout << "\n=== Vector V2 ===" << endl;
    CVector v2;
    v2.input();
    cout << "V2 = " << v2 << endl;
    cout << "Norm of V2: " << v2.norm() << endl;

    try {
        cout << "\nV1 + V2 = " << (v1 + v2) << endl;
        cout << "V1 - V2 = " << (v1 - v2) << endl;
        cout << "Dot product V1.V2 = " << v1.dot(v2) << endl;
        cout << "V1 == V2: " << (v1 == v2 ? "true" : "false") << endl;
        cout << "V1 != V2: " << (v1 != v2 ? "true" : "false") << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    double k;
    cout << "\nEnter scalar k: ";
    while (!(cin >> k)) {
        cout << "Error! Please enter a valid number.\nEnter scalar k: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "k * V1 = " << (k * v1) << endl;
    cout << "V1 * k = " << (v1 * k) << endl;
    cout << "-V1    = " << (-v1) << endl;

    return 0;
}