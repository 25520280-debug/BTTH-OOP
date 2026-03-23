#include "day.h"

int main()
{
    doy x; 
    std :: cout << "Nhap ngay, thang, nam: ";
    Input(x); // Nhập ngày, tháng, và năm.
    addDay(x);  // Tịnh tiến sang ngày kế tiếp.
    Output(x);  // Xuất ngày, tháng, và năm kết quả.
    return 0;
}