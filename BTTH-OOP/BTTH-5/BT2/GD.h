#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
bool checkInput(T &test);

class GD
{
protected:
    string MaGD;
    int Ngay,
        Thang,
        Nam;
    double Gia, S, Tien;
public:
    virtual ~GD();
    virtual void TinhTien() = 0;
    void NhapInfo();
    double getTien() const;
    friend ostream &operator<<(ostream &out, const GD &p);
    bool flag() const;
};

class Dat : public GD
{
private:
    char type;

public:
    void TinhTien() override;
    friend istream &operator>>(istream &in, Dat &obj);
};

class Nha : public GD
{
private:
    string type;
    string dc;

public:
    void TinhTien() override;
    friend istream &operator>>(istream &in, Nha &obj);
};

class CC : public GD
{
private:
    string MaCan;
    int VTT;

public:
    void TinhTien() override;
    friend istream &operator>>(istream &in, CC &obj);
};