#include "GD.h"
#include <vector>

class CT
{
private:
    vector<GD *> gds;
    vector<int> type;
    double TBTCC, MaxNha;
    vector <GD*> date;

public:
    CT();
    ~CT();
    void Nhap();
    void Xuat();
};