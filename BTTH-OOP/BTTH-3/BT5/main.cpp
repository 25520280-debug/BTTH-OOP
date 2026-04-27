#include "Polynomial.h"

int main() {
    Polynomial p1;
    p1.input();

    cout << "P1(x) = ";
    p1.display();

    do {
        double x;
        cout << "Please enter the value for x: ";
        cin >> x;
        cout << "P1(" << x << ") = " << p1.evaluate(x) << endl;
    } while (askYesNo("Do you want to evaluate P1 at another value of x?"));

    if (!askYesNo("Do you want to continue with a second polynomial?")) {
        return 0;
    }

    Polynomial p2;
    p2.input();

    cout << "P2(x) = ";
    p2.display();

    char op;
    cout << "Do you want to add or subtract? (+ / -): ";
    cin >> op;

    Polynomial result = (op == '+') ? p1.add(p2) : p1.subtract(p2);

    cout << "Result: P(x) = ";
    result.display();

    if (askYesNo("Do you want to evaluate the result at a value of x?")) {
        double x;
        cout << "Please enter the value for x: ";
        cin >> x;
        cout << "P(" << x << ") = " << result.evaluate(x) << endl;
    }

    return 0;
}