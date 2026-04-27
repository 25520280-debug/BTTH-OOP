#include <iostream>
#include "array.h"
using namespace std;

int main() {
    Array arr;

    arr.input();
    arr.printInfo();

    int x = readInt("\nEnter value x to count: ");
    cout << "  Occurrences of " << x << ": " << arr.count(x) << "\n";

    int st = arr.sortedStatus();

    if (st == 2) {
        cout << "\nAll elements are equal. No sorting needed.\n";
    } else if (st == 1) {
        char doSort = readChoice("\nArray is already sorted ascending. Reverse it? (y/n): ", "yn");
        if (doSort == 'y') {
            arr.mergeSort(false);
            arr.printInfo();
        } else {
            cout << "  Skipping sort.\n";
        }
    } else if (st == -1) {
        char doSort = readChoice("\nArray is already sorted descending. Reverse it? (y/n): ", "yn");
        if (doSort == 'y') {
            arr.mergeSort(true);
            arr.printInfo();
        } else {
            cout << "  Skipping sort.\n";
        }
    } else {
        char doSort = readChoice("\nDo you want to sort the array? (y/n): ", "yn");
        if (doSort == 'y') {
            char order = readChoice("Sort order (a = ascending / d = descending): ", "ad");
            bool asc = (order == 'a');
            arr.mergeSort(asc);
            arr.printInfo();
        } else {
            cout << "  Skipping sort.\n";
        }
    }

    return 0;
}