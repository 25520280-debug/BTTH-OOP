#include "CT.h"

void CT::Nhap()
{
    int n;
    cout << "Nhap so luong giao dich: ";
    cin >> n;
    this->gds.reserve(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap loai giao dich (1: Dat, 2: Nha, 3: Chung cu):";
        int x;
        while (true)
        {
            cin >> x;
            if (x == 1 || x == 2 || x == 3)
                break;
            cout << "Loi! Xin nhap lai.\n\n";
        }
        if (x == 1)
        {
            Dat *temp = new Dat();
            cin >> *temp;
            this->gds.push_back(temp);
            if (temp->flag()) this->date.push_back(temp);
            this->type[0]++;
        }
        else if (x == 2)
        {
            Nha *temp = new Nha();
            cin >> *temp;
            if (this->MaxNha < temp->getTien())
                this->MaxNha = temp->getTien();
            this->gds.push_back(temp);
            if (temp->flag()) this->date.push_back(temp);
            this->type[1]++;
        }
        else
        {
            CC *temp = new CC();
            cin >> *temp;
            this->TBTCC += temp->getTien();
            this->gds.push_back(temp);
            if (temp->flag()) this->date.push_back(temp);
            this->type[2]++;
        }
        cin.ignore();
    }
}

void CT::Xuat()
{
    cout << "\nGD Dat: ";
    cout << this->type[0] << '\n';
    cout << "GD Nha: ";
    cout << this->type[1] << '\n';
    cout << "GD Chung cu: ";
    cout << this->type[2] << "\n\n";
    cout << "TB GD Chung cu: ";
    if (this->type[2] != 0)
        cout << this->TBTCC / this->type[2] << '\n';
    else
        cout << "Khong co giao dich nao.\n";
    cout << "GD Nha co gia tri cao nhat: ";
    cout << this->MaxNha << "\n\n";
    for (GD* x : this->date) cout << *x;
}

CT::CT()
{
    this->type = {0, 0, 0};
    this->TBTCC = 0;
    this->MaxNha = 0;
}
CT::~CT()
{
    for (GD *&x : this->gds)
        delete x;
}
