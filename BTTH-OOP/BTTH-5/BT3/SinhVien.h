#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
bool checkInput(T &test)
{
    while (!(cin >> test))
    {
        cout << "Loi! Xin nhap lai.\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.ignore(10000, '\n');
    return true;
}

class SV {
protected:
    string  MSSV,
            HoTen,
            DiaChi;
    double  TinChi,
            DTB;
public:
    SV();
    virtual ~SV() = default;
    virtual bool DKTN() const = 0;
    double getDTB() const;
    void NhapInfo();
    friend ostream& operator << (ostream& out, const SV& p);
};

class CD : public SV {
    double DTN;
public:
    CD();
    ~CD();
    bool DKTN() const override;
    friend istream& operator >> (istream& in, CD& p);
};

class DH : public SV {
    string tenLV;
    double diemLV;
public:
    DH();
    ~DH();
    bool DKTN() const override;
    friend istream& operator >> (istream& in, DH& p);
};