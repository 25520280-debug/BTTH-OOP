#include "Header.h"

void TacVu::NhapInfo()
{
    cout << "Ma tac vu: "; getline(cin >> ws, MTV);
    cout << "Ten nguoi yeu cau: "; getline(cin>>ws, HoTen);
    cout << "Don vi yeu cau: "; getline(cin>>ws,DonVi);
    cout << "So token dau vao: "; cin >> SoTokenDauVao;
    cout << "Thoi gian xu ly: "; cin >> ThoiGian;
}

int ContentGenerationTask::QuyDoiDiemSangTao()
{
    if (MucDoSangTao == "Low") return 5;
    else if (MucDoSangTao == "Medium") return 10;
    else if (MucDoSangTao == "High") return 20;
}

double ContentGenerationTask::TinhChiPhi()
{
    return (SoTokenDauVao*0.001 + SoTokenDauRa * 0.002);
}

int ContentGenerationTask::QuyDoiDiemSangTao()
{
    if (MucDoSangTao == "Low") return 5;
    else if (MucDoSangTao == "Medium") return 10;
    else if (MucDoSangTao == "High") return 20;
}

double ContentGenerationTask::TinhChiPhi()
{
    return (SoTokenDauVao*0.001 + SoTokenDauRa * 0.002);
}

int ContentGenerationTask::TinhDiemRR()
{
    return (QuyDoiDiemSangTao() + SoTokenDauRa * 0.005);
}

int ContentGenerationTask::TinhDiemUT()
{
    return (MucDoKhanCap * 12 + ThoiGian * 0.8 + TinhDiemRR() - TinhChiPhi() * 0.5);
}

istream& operator >> (istream& in, ContentGenerationTask& p)
{
    p.NhapInfo();
    p.Type = "ContentGenerationTask";
    cout << "So token dau ra du kien: "; in >> p.SoTokenDauRa;
    cout <<"Muc do sang tao: "; getline(in>>ws,p.MucDoSangTao);
}

istream& operator >> (istream& in, SuKien& p)
{
    cout << "Ma tac vu: "; in >> p.MTV;
    cout << "Loai su kien: "; getline(in >> ws, p.Loai);
    cout << "Gia tri: "; in >> p.GiaTri;
    return in;
}

istream& operator >> (istream& in, LearningAnalyticsTask& p)
{
    p.NhapInfo();
    p.Type = "LearningAnalyticsTask";
    cout << "So luong ban ghi can phan tich: ";
    in >> p.SoLuongBan;
    cout << "Loai mo hinh phan tich: ";
    getline(in>>ws, p.LoaiMoHinh);
    return in;
}

istream& operator >> (istream& in, ContentMdoderationTask& p)
{
    p.NhapInfo();
    p.Type = "ContentMdoderationTask";
    cout << "Loai noi dung can kiem duyet: "; getline(in >> ws, p.LoaiNoiDungKiemDuyet);
    cout << "Muc do nhay cam: "; in >> p.MucDoNhayCam;
    return in;
}

istream& operator>>(istream &in, SuKien &p)
{
    cout << "Ma tac vu: "; in >> p.MTV;
    cout << "Loai su kien: "; getline(in>>ws,p.Loai);
    cout << "Gia tri: "; in >> p.GiaTri;
    return in;
};

void System::Nhap()
{
    int n1;
    cout << "Nhap so luong tac vu: ";
    cin >> n1;
    DSTV.resize(n1);
    for (int i = 0; i < n1; i++)
    {
        cout << "Nhap tac vu thu " << i + 1 << ":\n";
        cout << "Nhap loai tac vu: ";
        int x;
        cin >> x;
        if (x == 1)
        {
            ContentGenerationTask *temp = new ContentGenerationTask();
            cin >> *temp;
            DSTV[i] = temp;
        }
        else if (x == 2)
        {
            LearningAnalyticsTask *temp = new LearningAnalyticsTask();
            cin >> *temp;
            DSTV[i] = temp;
        }
        else
        {
            ContentMdoderationTask *temp = new ContentMdoderationTask();
            cin >> *temp;
            DSTV[i] = temp;
        }
    }

    cout << "Nhap so luong su kien: ";
    int n2;
    cin >> n2;
    DSSK.resize(n2);
    for (int i = 0; i < n2; i++)
    {
        cout << "Nhap su kien thu " << i + 1 << ":\n";
        cin >> *DSSK[i];
    }
}

string TacVu::getType()
{
    return Type;
}

string TacVu::getMTV()
{
    return MTV;
}

string TacVu::getHoTen()
{
    return HoTen;
}

string TacVu::getDonVi()
{
    return DonVi;
}

int TacVu::getSoTokenDauVao()
{
    return SoTokenDauVao;
}

int TacVu::getMucDoKhanCap()
{
    return MucDoKhanCap;
}

double TacVu::getThoiGian()
{
    return ThoiGian;
}

int ContentGenerationTask::getSoTokenDauRa()
{
    return SoTokenDauRa;
}

string ContentGenerationTask::getMucDoSangTao()
{
    return MucDoSangTao;
}