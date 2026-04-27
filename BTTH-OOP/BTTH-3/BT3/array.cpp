#include "array.h"
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int readInt(const string& prompt) {
    int v;
    while (true) {
        cout << prompt;
        if (cin >> v) return v;
        cout << "  [!] Invalid value, please try again.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

char readChoice(const string& prompt, const string& valid) {
    char c;
    while (true) {
        cout << prompt;
        cin >> c;
        c = (char)tolower(c);
        for (char ch : valid)
            if (c == ch) return c;
        cout << "  [!] Invalid choice.\n";
    }
}

bool Array::isPrime(int x) const {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i <= (int)sqrt((double)x); i += 2)
        if (x % i == 0) return false;
    return true;
}
void Array::swp(int& a, int& b) const {
    int t = a; a = b; b = t;
}

void Array::_merge(bool asc, int lo, int hi) {
    if (lo >= hi) return;
    int mid = (lo + hi) / 2;
    _merge(asc, lo, mid);
    _merge(asc, mid + 1, hi);
    int len = hi - lo + 1;
    int* tmp = new int[len];
    int i = lo, j = mid + 1, k = 0;
    while (i <= mid && j <= hi) {
        bool cond = asc ? data[i] <= data[j] : data[i] >= data[j];
        tmp[k++] = cond ? data[i++] : data[j++];
    }
    while (i <= mid) tmp[k++] = data[i++];
    while (j <= hi)  tmp[k++] = data[j++];
    for (int x = 0; x < len; x++) data[lo + x] = tmp[x];
    delete[] tmp;
}

Array::Array() : data(nullptr), n(0) {}
Array::~Array() { delete[] data; }

void Array::input() {
    n = readInt("Enter number of elements n = ");
    while (n <= 0) {
        cout << "  [!] n must be > 0.\n";
        n = readInt("Enter number of elements n = ");
    }
    delete[] data;
    data = new int[n];
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++)
        data[i] = readInt("  a[" + to_string(i) + "] = ");
}

void Array::print() const {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << data[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " ]\n";
}

int Array::sortedStatus() const {
    bool asc = true, desc = true;
    for (int i = 0; i < n - 1; i++) {
        if (data[i] > data[i + 1]) asc  = false;
        if (data[i] < data[i + 1]) desc = false;
    }
    if (asc && desc) return  2;
    if (asc)         return  1;
    if (desc)        return -1;
    return 0;
}

int Array::count(int x) const {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (data[i] == x) cnt++;
    return cnt;
}

bool Array::minOdd(int& result) const {
    result = INT_MAX;
    bool found = false;
    for (int i = 0; i < n; i++)
        if (data[i] % 2 != 0 && data[i] < result) {
            result = data[i]; found = true;
        }
    return found;
}

bool Array::maxPrime(int& result) const {
    result = INT_MIN;
    bool found = false;
    for (int i = 0; i < n; i++)
        if (isPrime(data[i]) && data[i] > result) {
            result = data[i]; found = true;
        }
    return found;
}
void Array::printInfo() const {
    cout << "\nArray       : "; print();

    int st = sortedStatus();
    if      (st ==  2) cout << "Sorted      : All elements equal\n";
    else if (st ==  1) cout << "Sorted      : Ascending\n";
    else if (st == -1) cout << "Sorted      : Descending\n";
    else               cout << "Sorted      : Not sorted\n";

    int odd;
    if (minOdd(odd)) cout << "Min odd     : " << odd << "\n";
    else             cout << "Min odd     : (no odd elements)\n";

    int prime;
    if (maxPrime(prime)) cout << "Max prime   : " << prime << "\n";
    else                 cout << "Max prime   : (no prime elements)\n";
}
void Array::mergeSort(bool asc) {
    _merge(asc, 0, n - 1);
}
