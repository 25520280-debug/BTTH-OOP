#include "pol.h"

int main() {
    Polynomial p1;
    p1.input();

    cout << "P1(x) = " << p1 << endl;          

    do {
        double x;
        cout << "Please enter the value for x: ";
        cin >> x;
        cout << "P1(" << x << ") = " << p1(x) << endl;   
    } while (askYesNo("Do you want to evaluate P1 at another value of x?"));

    if (!askYesNo("Do you want to continue with a second polynomial?")) {
        return 0;
    }

    Polynomial p2;
    p2.input();

    cout << "P2(x) = " << p2 << endl;          

    char op;
    cout << "Do you want to add or subtract? (+ / -): ";
    cin >> op;

    Polynomial result = (op == '+') ? p1 + p2 : p1 - p2;   

    cout << "Result: P(x) = " << result << endl;    

    if (askYesNo("Do you want to evaluate the result at a value of x?")) {
        double x;
        cout << "Please enter the value for x: ";
        cin >> x;
        cout << "P(" << x << ") = " << result(x) << endl;  
    }

    return 0;
}