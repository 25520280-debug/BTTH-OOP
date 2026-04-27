#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "prodworker.h"
using namespace std;

void printHeader() {
    cout << left
         << setw(12) << "ID"
         << setw(25) << "Full Name"
         << setw(14) << "Birth Date"
         << setw(16) << "Produced Units"
         << setw(14) << "Unit Price"
         << setw(14) << "Salary" << "\n"
         << string(95, '-') << "\n";
}

void displayAll(const vector<ProductionWorker>& workers) {
    printHeader();
    for (const auto& w : workers)
        w.display();
}

int main() {
    int n;
    while (true) {
        cout << "Number of production workers: ";
        if (cin >> n && n > 0) break;
        cout << "Error! Please try again.\n";
        cin.clear(); cin.ignore(10000,'\n');
    }

    vector<ProductionWorker> workers(n);
    for (int i = 0; i < n; i++) {
        cout << "\nWorker #" << (i + 1) << ":\n";
        workers[i].input();
    }

    cout << "\n";
    displayAll(workers);

    auto lowestIt = min_element(workers.begin(), workers.end(),
        [](const ProductionWorker& a, const ProductionWorker& b) {
            return a.calcSalary() < b.calcSalary();
        });
    cout << "\nWorker with lowest salary:\n";
    printHeader();
    lowestIt->display();

    double total = 0;
    for (const auto& w : workers) total += w.calcSalary();
    cout << "\nTotal salary: " << fixed << setprecision(2) << total << "\n";

    auto oldestIt = min_element(workers.begin(), workers.end(),
        [](const ProductionWorker& a, const ProductionWorker& b) {
            return a.getBirthYear() < b.getBirthYear();
        });
    cout << "\nOldest worker:\n";
    printHeader();
    oldestIt->display();

    vector<ProductionWorker> sorted = workers;
    sort(sorted.begin(), sorted.end(),
        [](const ProductionWorker& a, const ProductionWorker& b) {
            return a.calcSalary() < b.calcSalary();
        });
    cout << "\nWorkers sorted by salary (ascending):\n";
    displayAll(sorted);

    return 0;
}