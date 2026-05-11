#include "PhanSo.h"
using namespace std;

int main() {
    PhanSo a, b;

    cout << "Nhap phan so a (tu/mau): ";
    cin >> a;

    cout << "Nhap phan so b (tu/mau): ";
    cin >> b;

    cout << "\na = " << a << endl;
    cout << "b = " << b << endl;

    cout << "\na + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << endl;

    cout << "\na = b : " << (a == b ? "true" : "false") << endl;
    cout << "a > b : " << (a >  b ? "true" : "false") << endl;
    cout << "a < b : " << (a <  b ? "true" : "false") << endl;

    return 0;
}