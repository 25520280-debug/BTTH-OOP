#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

class TacVu
{
protected:
    string MTV,
        HoTen,
        DonVi,
        Type;
    int SoTokenDauVao,
        MucDoKhanCap;
    double ThoiGian;

public:
    void NhapInfo();
    
    string getType();
    string getMTV();
    string getHoTen();
    string getDonVi();
    int getSoTokenDauVao();
    int getMucDoKhanCap();
    double getThoiGian();

    virtual double TinhChiPhi() = 0;
    virtual int TinhDiemRR() = 0;
    virtual int TinhDiemUT() = 0;
};

class ContentGenerationTask : public TacVu
{
    int SoTokenDauRa;
    string MucDoSangTao;

public:
    int getSoTokenDauRa();
    string getMucDoSangTao();
    int QuyDoiDiemSangTao();

    double TinhChiPhi() override;
    int TinhDiemRR() override;
    int TinhDiemUT() override;

    friend istream &operator>>(istream &in, ContentGenerationTask &p);
};



class LearningAnalyticsTask : public TacVu
{
    int SoLuongBan;
    string LoaiMoHinh;

public:
    double QuyDoiDiemLoaiMoHinh();

    double TinhChiPhi() override;
    int TinhDiemRR() override;
    int TinhDiemUT() override;

    friend istream &operator>>(istream &in, LearningAnalyticsTask &p);
};

class ContentMdoderationTask : public TacVu
{
    string LoaiNoiDungKiemDuyet;
    int MucDoNhayCam;

public:
    double QuyDoiDiemLoaiNoiDung();
    string getLoai();
    int getMDNC();

    double TinhChiPhi() override;
    int TinhDiemRR() override;
    int TinhDiemUT() override;

    friend istream &operator>>(istream &in, ContentMdoderationTask &p);
};


class SuKien
{
    string MTV,
        Loai;
    int GiaTri;

public:
    virtual void ADD_DATA() = 0;
    virtual void URGENT_UPDATE() = 0;
    virtual void REVIEW() = 0;
    virtual void xuLySuKien() = 0;
    virtual void capNhatTrangThai() = 0;

    friend istream &operator>>(istream &in, SuKien &p);
};

class System
{
    vector<TacVu *> DSTV;
    vector<SuKien *> DSSK;

public:
    void Nhap();
    void Xuat();
};

void System::Xuat()
{
    int n = DSTV.size();
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " Tac vu\n";
        cout << DSTV[i]->getType();
        cout << "Ma tac vu: " << DSTV[i]->getMTV();
        cout << "Ten nguoi yeu cau: " << DSTV[i]->getHoTen();
        cout << "Don vi yeu cau: " << DSTV[i]->getDonVi();
        cout << "So token dau vao: " << DSTV[i]->getSoTokenDauVao();
        cout << "Thoi gian xu ly: " << DSTV[i]->getThoiGian();
        if (DSTV[i]->getType() == "ContentGenerationTask") {
            cout << "So token dau ra du kien: \n";
            cout <<"Muc do sang tao: \n";
        }
        else if (DSTV[i]->getType() == "LearningAnalyticsTask") {
            cout << "So luong ban ghi can phan tich: \n";
            cout << "Loai mo hinh phan tich: \n";
        }
        else if (DSTV[i]->getType() == "ContentMdoderationTask") {
            cout << "Muc do nhay cam: \n";
        }    
        
    }
}
