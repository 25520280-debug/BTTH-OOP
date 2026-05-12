#include "CDate.h"

bool CDate::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int CDate::daysInMonth(int m, int y) const {
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeapYear(y)) return 29;
    return days[m - 1];
}

long long CDate::leapsBefore(int y) const {
    y--;
    return y/4 - y/100 + y/400;
}

long long CDate::toDays() const {
    long long total = (long long)(year - 1) * 365 + leapsBefore(year);
    for (int m = 1; m < month; m++)
        total += daysInMonth(m, year);
    total += day;
    return total;
}

void CDate::fromDays(long long total) {
    long long y400 = (total - 1) / 146097;
    total -= y400 * 146097;
    long long y100 = (total - 1) / 36524;
    if (y100 == 4) y100 = 3;
    total -= y100 * 36524;
    long long y4 = (total - 1) / 1461;
    total -= y4 * 1461;
    long long y1 = (total - 1) / 365;
    if (y1 == 4) y1 = 3;
    total -= y1 * 365;
    year = (int)(y400 * 400 + y100 * 100 + y4 * 4 + y1 + 1);
    month = 1;
    while (month < 12 && total > daysInMonth(month, year)) {
        total -= daysInMonth(month, year);
        month++;
    }
    day = (int)total;
}

CDate::CDate(int d, int m, int y) : day(d), month(m), year(y) {}

bool CDate::isValid() const {
    return year >= 1 && month >= 1 && month <= 12
        && day >= 1 && day <= daysInMonth(month, year);
}

CDate CDate::operator+(int n) const {
    CDate result;
    result.fromDays(toDays() + n);
    return result;
}

CDate CDate::operator-(int n) const {
    CDate result;
    result.fromDays(toDays() - n);
    return result;
}

long long CDate::operator-(const CDate& other) const {
    return toDays() - other.toDays();
}

CDate& CDate::operator++() {
    fromDays(toDays() + 1);
    return *this;
}

CDate CDate::operator++(int) {
    CDate tmp = *this;
    fromDays(toDays() + 1);
    return tmp;
}

CDate& CDate::operator--() {
    fromDays(toDays() - 1);
    return *this;
}

CDate CDate::operator--(int) {
    CDate tmp = *this;
    fromDays(toDays() - 1);
    return tmp;
}

bool CDate::operator<(const CDate& o) const { return toDays() < o.toDays(); }
bool CDate::operator>(const CDate& o) const { return toDays() > o.toDays(); }
bool CDate::operator==(const CDate& o) const { return toDays() == o.toDays(); }

ostream& operator<<(ostream& os, const CDate& d) {
    os << setfill('0')
       << setw(2) << d.day << "/"
       << setw(2) << d.month << "/"
       << setw(4) << d.year;
    return os;
}

istream& operator>>(istream& is, CDate& d) {
    char slash1, slash2;
    int dd, mm, yy;
    if (!(is >> dd >> slash1 >> mm >> slash2 >> yy)
        || slash1 != '/' || slash2 != '/') {
        is.setstate(ios::failbit);
        return is;
    }
    CDate tmp(dd, mm, yy);
    if (!tmp.isValid()) {
        is.setstate(ios::failbit);
        return is;
    }
    d = tmp;
    return is;
}
