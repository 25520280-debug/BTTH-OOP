#include "Truong.h"

Truong::Truong() {
    this->MaxTB_CD = new CD();
    this->MaxTB_DH = new DH();
    this->SoSV_CD_KD = 0;
    this->SoSV_DH_KD = 0;
}

Truong::~Truong()
{
    for (SV*& x : this->svs) delete x;
    for (SV*& x : this->svKD) delete x;
    for (SV*& x : this->svD) delete x;
    delete MaxTB_CD;
    delete MaxTB_DH;
}

void Truong::Nhap()
{
    cout << "Nhap so luong sinh vien: "; int n; checkInput(n);
    for (int i = 0; i < n; i++){
        int x;
        while (true) {
            cout << "Nhap he dao tao cua sinh vien (1: Cao dang, 2: Dai hoc): ";
            cin >> x;
            if (x == 1 || x == 2) break;
            cout << "Loi! Xin nhap lai.\n\n";
            cin.clear();
            cin.ignore(10000,'\n');
        }
        if (x == 1) {
            CD* temp = new CD();
            cin >> *temp; this->svs.push_back(temp); 
            if (temp->getDTB() > this->MaxTB_CD->getDTB()) this->MaxTB_CD = temp;
            if (!(temp->DKTN())) {this->svKD.push_back(temp); this->SoSV_CD_KD++;}
            else this->svD.push_back(temp);
        }
        else {
            DH* temp = new DH();
            cin >> *temp; this->svs.push_back(temp); 
            if (temp->getDTB() > this->MaxTB_DH->getDTB()) this->MaxTB_DH = temp;
            if (!(temp->DKTN())) { this->svKD.push_back(temp); this->SoSV_DH_KD++; }
            else this->svD.push_back(temp);
        }
    }
}

void Truong::Xuat()
{
    cout << "\n\nDanh sach sinh vien:\n\n";
    for (SV* x : svs) cout << *x;
    cout << "\nDanh sach sinh vien du dieu kien:\n\n";
    for (SV* x : svD) cout << *x;
    cout << "\nDanh sach sinh vien khong du dieu kien:\n\n";
    for (SV* x : svKD) cout << *x;
    cout << "\nSinh vien cao dang co diem trung binh cao nhat:\n"; cout << *this->MaxTB_CD;
    cout << "\nSinh vien dai hoc co diem trung binh cao nhat:\n"; cout << *this->MaxTB_DH;
    cout << "\nSo sinh vien cao dang khong du dieu kien tot nghiep: " << this->SoSV_CD_KD;
    cout << "\nSo sinh vien dai hoc khong du dieu kien tot nghiep: " << this->SoSV_DH_KD;
}
