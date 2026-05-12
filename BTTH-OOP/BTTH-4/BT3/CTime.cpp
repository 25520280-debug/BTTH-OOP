#include "CTime.h"
#include <iomanip>
using namespace std;

void CTime::chuanHoa() {
    if (giay >= 60) { 
        phut += giay / 60; 
        giay %= 60; 
    }
    if (giay < 0) { 
        phut -= (-giay + 59) / 60; 
        giay = ((giay % 60) + 60) % 60; 
    }
    if (phut >= 60) { 
        gio += phut / 60; 
        phut %= 60; 
    }
    if (phut < 0) { 
        gio -= (-phut + 59) / 60; 
        phut = ((phut % 60) + 60) % 60; 
    }
    gio = ((gio % 24) + 24) % 24;
}

CTime::CTime() : gio(0), phut(0), giay(0) {}

CTime::CTime(int g, int p, int s) : gio(g), phut(p), giay(s) {
    chuanHoa();
}

CTime CTime::operator+(int s) const {
    return CTime(gio, phut, giay + s);
}

CTime CTime::operator-(int s) const {
    return CTime(gio, phut, giay - s);
}

CTime& CTime::operator++() {
    *this = *this + 1;
    return *this;
}

CTime CTime::operator++(int) {
    CTime t = *this;
    ++(*this);
    return t;
}

CTime& CTime::operator--() {
    *this = *this - 1;
    return *this;
}

CTime CTime::operator--(int) {
    CTime t = *this;
    --(*this);
    return t;
}

ostream& operator<<(ostream& os, const CTime& t) {
    os << setfill('0') << setw(2) << t.gio << ":"
       << setw(2) << t.phut << ":"
       << setw(2) << t.giay;
    return os;
}

istream& operator>>(istream& is, CTime& t) {
    char c;
    is >> t.gio >> c >> t.phut >> c >> t.giay;
    if (is.fail()) {
        is.clear();                          
        is.ignore(10000, '\n');              
        t.gio = 0;                           
        t.phut = 0;
        t.giay = 0;
    }
        t.chuanHoa();
        return is;
} 

void CTime::xuat12h() const {
    int g12 = gio;
    string period = "AM";
    
    if (gio == 0) {
        g12 = 12;
    } else if (gio == 12) {
        period = "PM";
    } else if (gio > 12) {
        g12 = gio - 12;
        period = "PM";
    }
    
    cout << setfill('0') << setw(2) << g12 << ":"
         << setw(2) << phut << ":"
         << setw(2) << giay << " " << period;
}

void CTime::xuat24h() const {
    cout << setfill('0') << setw(2) << gio << ":"
         << setw(2) << phut << ":"
         << setw(2) << giay;
}
