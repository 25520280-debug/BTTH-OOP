#include "prodworker.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool ProductionWorker::isValidDate(const string& date) const {
    if (date.size() != 10) return false;
    if (date[2] != '/' || date[5] != '/') return false;

    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (!isdigit(date[i])) return false;
    }

    int day   = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year  = stoi(date.substr(6, 4));

    if (month < 1 || month > 12) return false;
    if (year <= 0) return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeap) daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1]) return false;

    return true;
}

ProductionWorker::ProductionWorker()
    : id(""), fullName(""), birthDate(""), producedUnits(0), unitPrice(0.0) {}

string ProductionWorker::getId() const { return id; }
string ProductionWorker::getFullName() const { return fullName; }
string ProductionWorker::getBirthDate() const { return birthDate; }
int ProductionWorker::getProducedUnits() const { return producedUnits; }
double ProductionWorker::getUnitPrice() const { return unitPrice; }

void ProductionWorker::setId(string id) { this->id = id; }
void ProductionWorker::setFullName(string fullName) { this->fullName = fullName; }
void ProductionWorker::setBirthDate(string birthDate) { this->birthDate = birthDate; }
void ProductionWorker::setProducedUnits(int producedUnits) { this->producedUnits = producedUnits; }
void ProductionWorker::setUnitPrice(double unitPrice) { this->unitPrice = unitPrice; }

double ProductionWorker::calcSalary() const { return producedUnits * unitPrice; }

int ProductionWorker::getBirthYear() const {
    return stoi(birthDate.substr(birthDate.rfind('/') + 1));
}

void ProductionWorker::input() {
    do {
        cout << "ID: ";
        cin >> id;
    } while (id.empty());

    cin.ignore();
    do {
        cout << "Full name: ";
        getline(cin, fullName);
        if (fullName.empty()) cout << "Full name cannot be empty.\n";
    } while (fullName.empty());

    do {
        cout << "Birth date (dd/mm/yyyy): ";
        cin >> birthDate;
        if (!isValidDate(birthDate)) cout << "Invalid date. Please re-enter.\n";
    } while (!isValidDate(birthDate));

    do {
        cout << "Produced units: ";
        cin >> producedUnits;
        if (cin.fail() || producedUnits < 0) {
            cout << "Produced units must be >= 0. Please re-enter.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            producedUnits = -1;
        }
    } while (producedUnits < 0);

    do {
        cout << "Unit price: ";
        cin >> unitPrice;
        if (cin.fail() || unitPrice < 0) {
            cout << "Unit price must be >= 0. Please re-enter.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            unitPrice = -1;
        }
    } while (unitPrice < 0);
}

void ProductionWorker::display() const {
    cout << left
         << setw(12) << id
         << setw(25) << fullName
         << setw(14) << birthDate
         << setw(16) << producedUnits
         << setw(14) << fixed << setprecision(2) << unitPrice
         << setw(14) << calcSalary() << "\n";
}